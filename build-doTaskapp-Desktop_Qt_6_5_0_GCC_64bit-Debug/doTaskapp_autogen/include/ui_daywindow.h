/********************************************************************************
** Form generated from reading UI file 'daywindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DAYWINDOW_H
#define UI_DAYWINDOW_H

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

class Ui_daywindow
{
public:
    QWidget *centralwidget;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *add_b;
    QPushButton *back_b;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_3;
    QLabel *year_l;
    QLabel *month_l;
    QLabel *day_l;
    QPushButton *left_b;
    QPushButton *right_b;
    QLabel *empty_l;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *daywindow)
    {
        if (daywindow->objectName().isEmpty())
            daywindow->setObjectName("daywindow");
        daywindow->resize(1091, 726);
        centralwidget = new QWidget(daywindow);
        centralwidget->setObjectName("centralwidget");
        horizontalLayoutWidget = new QWidget(centralwidget);
        horizontalLayoutWidget->setObjectName("horizontalLayoutWidget");
        horizontalLayoutWidget->setGeometry(QRect(80, 610, 941, 61));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        add_b = new QPushButton(horizontalLayoutWidget);
        add_b->setObjectName("add_b");

        horizontalLayout->addWidget(add_b);

        back_b = new QPushButton(horizontalLayoutWidget);
        back_b->setObjectName("back_b");

        horizontalLayout->addWidget(back_b);

        verticalLayoutWidget_2 = new QWidget(centralwidget);
        verticalLayoutWidget_2->setObjectName("verticalLayoutWidget_2");
        verticalLayoutWidget_2->setGeometry(QRect(110, 0, 881, 197));
        verticalLayout_3 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        year_l = new QLabel(verticalLayoutWidget_2);
        year_l->setObjectName("year_l");
        QFont font;
        font.setPointSize(46);
        year_l->setFont(font);
        year_l->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(year_l);

        month_l = new QLabel(verticalLayoutWidget_2);
        month_l->setObjectName("month_l");
        QFont font1;
        font1.setPointSize(20);
        month_l->setFont(font1);
        month_l->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(month_l);

        day_l = new QLabel(verticalLayoutWidget_2);
        day_l->setObjectName("day_l");
        day_l->setFont(font1);
        day_l->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(day_l);

        left_b = new QPushButton(centralwidget);
        left_b->setObjectName("left_b");
        left_b->setGeometry(QRect(20, 184, 41, 411));
        right_b = new QPushButton(centralwidget);
        right_b->setObjectName("right_b");
        right_b->setGeometry(QRect(1030, 190, 41, 411));
        empty_l = new QLabel(centralwidget);
        empty_l->setObjectName("empty_l");
        empty_l->setGeometry(QRect(0, -60, 711, 111));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Umpush")});
        font2.setPointSize(22);
        font2.setBold(true);
        font2.setKerning(true);
        font2.setStyleStrategy(QFont::PreferDefault);
        empty_l->setFont(font2);
        empty_l->setAlignment(Qt::AlignCenter);
        gridLayoutWidget = new QWidget(centralwidget);
        gridLayoutWidget->setObjectName("gridLayoutWidget");
        gridLayoutWidget->setGeometry(QRect(70, 190, 951, 411));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        daywindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(daywindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1091, 22));
        daywindow->setMenuBar(menubar);
        statusbar = new QStatusBar(daywindow);
        statusbar->setObjectName("statusbar");
        daywindow->setStatusBar(statusbar);

        retranslateUi(daywindow);

        QMetaObject::connectSlotsByName(daywindow);
    } // setupUi

    void retranslateUi(QMainWindow *daywindow)
    {
        daywindow->setWindowTitle(QCoreApplication::translate("daywindow", "MainWindow", nullptr));
        add_b->setText(QCoreApplication::translate("daywindow", "Add", nullptr));
        back_b->setText(QCoreApplication::translate("daywindow", "Back", nullptr));
        year_l->setText(QCoreApplication::translate("daywindow", "Placeholder", nullptr));
        month_l->setText(QCoreApplication::translate("daywindow", "Placeholder", nullptr));
        day_l->setText(QCoreApplication::translate("daywindow", "Placeholder", nullptr));
        left_b->setText(QString());
        right_b->setText(QString());
        empty_l->setText(QCoreApplication::translate("daywindow", "This entry is empty! Start by creating some tasks!", nullptr));
    } // retranslateUi

};

namespace Ui {
    class daywindow: public Ui_daywindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DAYWINDOW_H
