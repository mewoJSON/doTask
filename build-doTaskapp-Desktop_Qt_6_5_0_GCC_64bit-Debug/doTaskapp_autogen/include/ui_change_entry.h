/********************************************************************************
** Form generated from reading UI file 'change_entry.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHANGE_ENTRY_H
#define UI_CHANGE_ENTRY_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Change_entry
{
public:
    QMenuBar *menubar;
    QWidget *centralwidget;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Change_entry)
    {
        if (Change_entry->objectName().isEmpty())
            Change_entry->setObjectName("Change_entry");
        Change_entry->resize(800, 600);
        menubar = new QMenuBar(Change_entry);
        menubar->setObjectName("menubar");
        Change_entry->setMenuBar(menubar);
        centralwidget = new QWidget(Change_entry);
        centralwidget->setObjectName("centralwidget");
        Change_entry->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(Change_entry);
        statusbar->setObjectName("statusbar");
        Change_entry->setStatusBar(statusbar);

        retranslateUi(Change_entry);

        QMetaObject::connectSlotsByName(Change_entry);
    } // setupUi

    void retranslateUi(QMainWindow *Change_entry)
    {
        Change_entry->setWindowTitle(QCoreApplication::translate("Change_entry", "MainWindow", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Change_entry: public Ui_Change_entry {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHANGE_ENTRY_H
