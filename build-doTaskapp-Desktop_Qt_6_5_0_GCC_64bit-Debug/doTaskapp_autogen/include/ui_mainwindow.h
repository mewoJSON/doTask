/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *quit_b;
    QPushButton *left_b;
    QPushButton *right_b;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *vboxLayout;
    QLabel *year_l;
    QLabel *month_l;
    QLabel *label_3;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1091, 726);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        gridLayoutWidget = new QWidget(centralwidget);
        gridLayoutWidget->setObjectName("gridLayoutWidget");
        gridLayoutWidget->setGeometry(QRect(60, 160, 971, 451));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayoutWidget = new QWidget(centralwidget);
        horizontalLayoutWidget->setObjectName("horizontalLayoutWidget");
        horizontalLayoutWidget->setGeometry(QRect(60, 620, 971, 51));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        quit_b = new QPushButton(horizontalLayoutWidget);
        quit_b->setObjectName("quit_b");

        horizontalLayout->addWidget(quit_b);

        left_b = new QPushButton(centralwidget);
        left_b->setObjectName("left_b");
        left_b->setGeometry(QRect(10, 250, 41, 291));
        right_b = new QPushButton(centralwidget);
        right_b->setObjectName("right_b");
        right_b->setGeometry(QRect(1040, 260, 41, 291));
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(310, 20, 461, 131));
        vboxLayout = new QVBoxLayout(verticalLayoutWidget);
        vboxLayout->setObjectName("vboxLayout");
        vboxLayout->setContentsMargins(0, 0, 0, 0);
        year_l = new QLabel(verticalLayoutWidget);
        year_l->setObjectName("year_l");
        QFont font;
        font.setPointSize(46);
        year_l->setFont(font);
        year_l->setAlignment(Qt::AlignCenter);

        vboxLayout->addWidget(year_l);

        month_l = new QLabel(verticalLayoutWidget);
        month_l->setObjectName("month_l");
        QFont font1;
        font1.setPointSize(20);
        month_l->setFont(font1);
        month_l->setAlignment(Qt::AlignCenter);

        vboxLayout->addWidget(month_l);

        label_3 = new QLabel(verticalLayoutWidget);
        label_3->setObjectName("label_3");
        label_3->setAlignment(Qt::AlignCenter);

        vboxLayout->addWidget(label_3);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1091, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "doTask", nullptr));
        quit_b->setText(QCoreApplication::translate("MainWindow", "Quit", nullptr));
        left_b->setText(QString());
        right_b->setText(QString());
        year_l->setText(QCoreApplication::translate("MainWindow", "PlaceHolder", nullptr));
        month_l->setText(QCoreApplication::translate("MainWindow", "PlaceHolder", nullptr));
        label_3->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
