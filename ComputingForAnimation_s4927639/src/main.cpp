/****************************************************************************
basic OpenGL demo modified from http://qt-project.org/doc/qt-5.0/qtgui/openglwindow.html
****************************************************************************/
#include <QtGui/QGuiApplication>
#include <QApplication>
#include <iostream>
#include "MainWindow.h"



int main(int argc, char **argv)
{
  QApplication a(argc, argv);
  // Create a new MainWindow
  MainWindow w;
  w.resize(1024, 720);
  // show it
  w.show();
  // hand control over to Qt framework
  return a.exec();

}



