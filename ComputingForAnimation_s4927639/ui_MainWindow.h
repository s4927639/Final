/********************************************************************************
** Form generated from reading UI file 'MainWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *mLayout;
    QSpacerItem *horizontalSpacer_2;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QPushButton *remove;
    QPushButton *exitB;
    QPushButton *add;
    QMenuBar *menubar;
    QMenu *menub;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        mLayout = new QGridLayout(centralwidget);
        mLayout->setObjectName(QStringLiteral("mLayout"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        mLayout->addItem(horizontalSpacer_2, 0, 0, 1, 1);

        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        remove = new QPushButton(groupBox);
        remove->setObjectName(QStringLiteral("remove"));

        gridLayout->addWidget(remove, 2, 4, 1, 1);

        exitB = new QPushButton(groupBox);
        exitB->setObjectName(QStringLiteral("exitB"));

        gridLayout->addWidget(exitB, 3, 4, 1, 1);

        add = new QPushButton(groupBox);
        add->setObjectName(QStringLiteral("add"));

        gridLayout->addWidget(add, 0, 4, 1, 1);


        mLayout->addWidget(groupBox, 0, 1, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 26));
        menub = new QMenu(menubar);
        menub->setObjectName(QStringLiteral("menub"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menub->menuAction());

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Flocking Simulation", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("MainWindow", "options", Q_NULLPTR));
        remove->setText(QApplication::translate("MainWindow", "Remove Boid", Q_NULLPTR));
        exitB->setText(QApplication::translate("MainWindow", "Exit", Q_NULLPTR));
        add->setText(QApplication::translate("MainWindow", "Add Boid", Q_NULLPTR));
        menub->setTitle(QApplication::translate("MainWindow", "By s4927639", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
