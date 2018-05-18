#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "NGLScene.h"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *m_ui;
    /// @brief our openGL widget
    NGLScene *m_gl;

    int m_numSphere=20;

private slots:
    void addBoid();
    void removeBoid();
};

#endif // MAINWINDOW_H
