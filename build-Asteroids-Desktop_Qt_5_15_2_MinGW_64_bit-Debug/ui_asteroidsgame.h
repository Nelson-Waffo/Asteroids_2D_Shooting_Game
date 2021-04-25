/********************************************************************************
** Form generated from reading UI file 'asteroidsgame.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ASTEROIDSGAME_H
#define UI_ASTEROIDSGAME_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>
#include "mainwidget.h"

QT_BEGIN_NAMESPACE

class Ui_AsteroidsGame
{
public:
    QAction *actionStart;
    QAction *actionExit;
    QAction *actionHelp;
    QWidget *centralwidget;
    MainWidget *gameBoard;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuAbout;
    QStatusBar *statusbar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *AsteroidsGame)
    {
        if (AsteroidsGame->objectName().isEmpty())
            AsteroidsGame->setObjectName(QString::fromUtf8("AsteroidsGame"));
        AsteroidsGame->resize(827, 703);
        actionStart = new QAction(AsteroidsGame);
        actionStart->setObjectName(QString::fromUtf8("actionStart"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/assets/assets/icons/start.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionStart->setIcon(icon);
        actionExit = new QAction(AsteroidsGame);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/assets/assets/icons/exit.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionExit->setIcon(icon1);
        actionHelp = new QAction(AsteroidsGame);
        actionHelp->setObjectName(QString::fromUtf8("actionHelp"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/assets/assets/icons/about.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionHelp->setIcon(icon2);
        centralwidget = new QWidget(AsteroidsGame);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gameBoard = new MainWidget(centralwidget);
        gameBoard->setObjectName(QString::fromUtf8("gameBoard"));
        gameBoard->setGeometry(QRect(10, 10, 802, 602));
        AsteroidsGame->setCentralWidget(centralwidget);
        menubar = new QMenuBar(AsteroidsGame);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 827, 25));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuAbout = new QMenu(menubar);
        menuAbout->setObjectName(QString::fromUtf8("menuAbout"));
        AsteroidsGame->setMenuBar(menubar);
        statusbar = new QStatusBar(AsteroidsGame);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        AsteroidsGame->setStatusBar(statusbar);
        toolBar = new QToolBar(AsteroidsGame);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        AsteroidsGame->addToolBar(Qt::TopToolBarArea, toolBar);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuAbout->menuAction());
        menuFile->addAction(actionStart);
        menuFile->addAction(actionExit);
        menuAbout->addAction(actionHelp);
        toolBar->addAction(actionStart);
        toolBar->addAction(actionExit);
        toolBar->addAction(actionHelp);

        retranslateUi(AsteroidsGame);

        QMetaObject::connectSlotsByName(AsteroidsGame);
    } // setupUi

    void retranslateUi(QMainWindow *AsteroidsGame)
    {
        AsteroidsGame->setWindowTitle(QCoreApplication::translate("AsteroidsGame", "MainWindow", nullptr));
        actionStart->setText(QCoreApplication::translate("AsteroidsGame", "Start", nullptr));
        actionExit->setText(QCoreApplication::translate("AsteroidsGame", "Exit", nullptr));
        actionHelp->setText(QCoreApplication::translate("AsteroidsGame", "Help", nullptr));
        menuFile->setTitle(QCoreApplication::translate("AsteroidsGame", "File", nullptr));
        menuAbout->setTitle(QCoreApplication::translate("AsteroidsGame", "About", nullptr));
        toolBar->setWindowTitle(QCoreApplication::translate("AsteroidsGame", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AsteroidsGame: public Ui_AsteroidsGame {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ASTEROIDSGAME_H
