#include "Sphere.h"
#include <ngl/VAOPrimitives.h>
#include <ngl/Random.h>


Sphere::Sphere( ngl::Vec3 _pos, ngl::Vec3 _vel,  GLfloat _rad)
{
  // set values from params
  m_pos=0,0,0;
  m_vel=_vel;
  m_rad=0.5;
  m_hit=false;

}

Sphere::Sphere()
{
  m_hit=false;
}

void Sphere::loadMatricesToShader( ngl::Transformation &_tx, const ngl::Mat4 &_globalMat, ngl::Camera *_cam  ) const
{
  ngl::ShaderLib *shader=ngl::ShaderLib::instance();

  ngl::Mat4 MV;
  ngl::Mat4 MVP;
  ngl::Mat3 normalMatrix;
  MV=_cam->getViewMatrix()  *_globalMat* _tx.getMatrix();
  MVP=_cam->getProjectionMatrix()*MV;
  normalMatrix=MV;
  normalMatrix.inverse().transpose();
  shader->setUniform("MVP",MVP);
  shader->setUniform("normalMatrix",normalMatrix);
}


void Sphere::draw( const std::string &_shaderName, const ngl::Mat4 &_globalMat,  ngl::Camera *_cam )const
{

  // draw wireframe if hit
  if(m_hit)
  {
    glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
  }
  else
  {
    glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
  }


  ngl::ShaderLib *shader=ngl::ShaderLib::instance();
  shader->use(_shaderName);
  // grab an instance of the primitives for drawing
  ngl::VAOPrimitives *prim=ngl::VAOPrimitives::instance();
  ngl::Transformation t;

  t.setPosition(m_pos);
  t.setScale(m_rad,m_rad,m_rad);
  loadMatricesToShader(t,_globalMat,_cam);
  prim->draw("boids");

glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
}



void Sphere::set(ngl::Vec3 _pos, ngl::Vec3 _vel, GLfloat _rad)
{
  m_pos=_pos;
  m_vel=_vel;
  m_rad=_rad;
}

void Sphere::move()
{
  m_vel+=m_accel;
  m_vel.clamp(-m_maxSpeed,m_maxSpeed);
  // store the last position
  m_lastPos=m_pos;
  // update the current position
  m_pos+=m_vel;
  // get the next position
  m_nextPos=m_pos+m_vel;
  m_hit=false;
  m_accel*=0;
}

// give new direction to boids
void Sphere::seek(ngl::Vec3 _target)
{
  ngl::Vec3 desired=_target-m_pos;
  desired.normalize();
  desired=desired*m_maxSpeed;
  ngl::Vec3 steer=desired-m_vel;
  steer.clamp(m_maxForce);
  applyForce(steer);
}

void Sphere::arrive(ngl::Vec3 _target)
{
  ngl::Vec3 desired=_target-m_pos;
  float d=desired.length();
  desired.normalize();

  if(d<50)
  {
    desired*=d/10;
  }
  else
  {
    desired*=m_maxSpeed;
  }
  ngl::Vec3 steer=desired-m_vel;
  steer.clamp(m_maxForce);
  applyForce(steer);
}

void Sphere::applyForce(ngl::Vec3 _force)
{
  m_accel+=_force;
}

//separation value
void Sphere::separation(std::vector<Sphere> _sphereArray)
{
  float dSeparation=3.0f;
  ngl::Vec3 sum(0,0,0);
  int count=0;

  for(Sphere &s : _sphereArray)
  {
    ngl::Vec3 distance=m_pos-s.getPos();
    float d=distance.length();

    if((d>0)&&(d<dSeparation))
    {
      distance.normalize();
      distance/=d;
      sum+=distance;
      count++;
    }
  }
  if(count>0)
  {
    sum/=count;
    sum.normalize();
    sum*=m_maxSpeed;
    ngl::Vec3 steer=sum-m_vel;
    steer.clamp(m_maxForce);
    applyForce(steer);
  }
}

//aligment value
void Sphere::alignment(std::vector<Sphere> _sphereArray)
{
  float neighbourDistance=5.0f;
  ngl::Vec3 sum(0,0,0);
  int count=0;

  for(Sphere &s : _sphereArray)
  {
    ngl::Vec3 distance=m_pos-s.getPos();
    float d=distance.length();

    if((d>0)&&(d<neighbourDistance))
    {
      sum+=s.getVelocity();
      count++;
    }
  }
  if(count>0)
  {
    sum/=count;
    sum.normalize();
    sum*=m_maxSpeed;
    ngl::Vec3 steer=sum-m_vel;
    steer.clamp(m_maxForce);
    applyForce(steer);
  }
}

//cohesion value
void Sphere::cohesion(std::vector<Sphere> _sphereArray)
{
  float neighbourDistance=5.0f;
  ngl::Vec3 sum(0,0,0);
  int count=0;

  for(Sphere &s : _sphereArray)
  {
    ngl::Vec3 distance=m_pos-s.getPos();
    float d=distance.length();

    if((d>0)&&(d<neighbourDistance))
    {
      sum+=s.getPos();
      count++;
    }
  }
  if(count>0)
  {
    sum/=count;
    seek(sum);
  }
}

// set all influences
void Sphere::setBehaviour(GLfloat _sepW, GLfloat _aliW, GLfloat _cohW)
{
  m_sepW=_sepW;
  m_aliW=_aliW;
  m_cohW=_cohW;

  m_sep=m_rad*m_sepW;
  m_ali=m_rad*m_aliW;
  m_coh=m_rad*m_cohW;
}
