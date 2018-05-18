#ifndef SPHERE_H_
#define SPHERE_H_


#include <ngl/Camera.h>
#include <ngl/ShaderLib.h>
#include <ngl/Transformation.h>
#include <ngl/Vec3.h>

/*! \brief a simple sphere class */
class Sphere
{
public :
  /// @brief ctor
  /// @param pos the position of the sphere
  /// @param rad the radius of the sphere */
  Sphere(ngl::Vec3 _pos, ngl::Vec3 _vel, GLfloat _rad);
  Sphere();
  /// draw method
  void draw(const std::string &_shaderName,const ngl::Mat4 &_globalMat, ngl::Camera *_cam )const ;
  void loadMatricesToShader(ngl::Transformation &_tx, const ngl::Mat4 &_globalMat,ngl::Camera *_cam )const;
  inline void reverse(){m_dir=m_dir*-1.0;}
  // detect collisions for boids
  inline void setHit(){m_hit=true;}
  inline void setNotHit(){m_hit=false;}
  inline bool isHit()const {return m_hit;}

  // set parameters
  inline ngl::Vec3 getPos() const {return m_pos;}
  inline ngl::Vec3 getNextPos() const {return m_nextPos;}
  inline GLfloat getRadius() const {return m_rad;}
  inline void setDirection(ngl::Vec3 _d){m_dir=_d;}
  inline ngl::Vec3 getDirection() const { return m_dir;}
  inline void setVelocity(ngl::Vec3 _v){m_vel=_v;}
  inline ngl::Vec3 getVelocity() const { return m_vel;}

  //movement
  void move();
  void set(ngl::Vec3 _pos, ngl::Vec3 _vel, GLfloat _rad);
  void seek(ngl::Vec3 _target);
  void arrive(ngl::Vec3 _target);
  void applyForce(ngl::Vec3 _force);

  // steer behaviour
  void separation(std::vector<Sphere> _sphereArray);
  void alignment(std::vector<Sphere> _sphereArray);
  void cohesion(std::vector<Sphere> _sphereArray);
  void setBehaviour(GLfloat _sepW, GLfloat _aliW, GLfloat _cohW);



private :
  /*! the position of the sphere */
  ngl::Vec3 m_pos;
  /*! the radius of the sphere */
  GLfloat m_rad;
  /*! flag to indicate if the sphere has been hit by ray */
  bool m_hit;
  // the direction of the sphere
  ngl::Vec3 m_dir;
  // the velocity of the sphere
  ngl::Vec3 m_vel;
  // the acceleration of the sphere
  ngl::Vec3 m_accel;
  // the last position of the sphere
  ngl::Vec3 m_lastPos;
  // the next position of the sphere
  ngl::Vec3 m_nextPos;
  float m_maxSpeed=1.0f;
  float m_maxForce=0.02f;
  //three rules of the sphere
  GLfloat m_sep;
  GLfloat m_ali;
  GLfloat m_coh;
  // three rules weight of the sphere
  GLfloat m_sepW;
  GLfloat m_aliW;
  GLfloat m_cohW;


};





#endif
