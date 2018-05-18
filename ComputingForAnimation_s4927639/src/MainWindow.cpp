#include "MainWindow.h"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent) :QMainWindow(parent), m_ui(new Ui::MainWindow)
{
  m_ui->setupUi(this);
  m_gl=new  NGLScene(m_numSphere, this);
  m_ui->mLayout->addWidget(m_gl,0,0,2,1);

  connect(m_ui->add, SIGNAL(clicked(bool)), this, SLOT(addBoid()));
  connect(m_ui->remove, SIGNAL(clicked(bool)), this, SLOT(removeBoid()));
  connect(m_ui->exitB, SIGNAL(clicked(bool)), this, SLOT(close()));


}

MainWindow::~MainWindow()
{
    delete m_ui;
}

void MainWindow::addBoid()
{
  m_gl->addSphere();
}

void MainWindow::removeBoid()
{
  m_gl->removeSphere();
}
