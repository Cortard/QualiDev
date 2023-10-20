/********************************************************************************
** Form generated from reading UI file 'titanic.ui'
**
** Created by: Qt User Interface Compiler version 6.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TITANIC_H
#define UI_TITANIC_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Titanic
{
public:
    QWidget *centralwidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Titanic)
    {
        if (Titanic->objectName().isEmpty())
            Titanic->setObjectName("Titanic");
        Titanic->resize(800, 600);
        centralwidget = new QWidget(Titanic);
        centralwidget->setObjectName("centralwidget");
        Titanic->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Titanic);
        menubar->setObjectName("menubar");
        Titanic->setMenuBar(menubar);
        statusbar = new QStatusBar(Titanic);
        statusbar->setObjectName("statusbar");
        Titanic->setStatusBar(statusbar);

        retranslateUi(Titanic);

        QMetaObject::connectSlotsByName(Titanic);
    } // setupUi

    void retranslateUi(QMainWindow *Titanic)
    {
        Titanic->setWindowTitle(QCoreApplication::translate("Titanic", "Titanic", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Titanic: public Ui_Titanic {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TITANIC_H
