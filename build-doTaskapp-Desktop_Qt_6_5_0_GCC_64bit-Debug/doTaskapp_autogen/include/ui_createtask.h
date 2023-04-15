/********************************************************************************
** Form generated from reading UI file 'createtask.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATETASK_H
#define UI_CREATETASK_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>

QT_BEGIN_NAMESPACE

class Ui_createTask
{
public:
    QLabel *label;
    QLineEdit *namereq;
    QLabel *label_2;
    QRadioButton *checkboxreq;
    QRadioButton *scorereq;
    QLabel *label_3;
    QLabel *label_4;
    QLineEdit *notereq;
    QLabel *label_5;
    QRadioButton *isUrgent;
    QPushButton *add_b;
    QLabel *label_6;
    QPushButton *pushButton;

    void setupUi(QDialog *createTask)
    {
        if (createTask->objectName().isEmpty())
            createTask->setObjectName("createTask");
        createTask->resize(535, 498);
        label = new QLabel(createTask);
        label->setObjectName("label");
        label->setGeometry(QRect(40, 80, 111, 51));
        QFont font;
        font.setFamilies({QString::fromUtf8("Umpush")});
        font.setBold(true);
        label->setFont(font);
        namereq = new QLineEdit(createTask);
        namereq->setObjectName("namereq");
        namereq->setGeometry(QRect(150, 90, 241, 31));
        label_2 = new QLabel(createTask);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(170, 20, 211, 51));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Ubuntu Light")});
        font1.setPointSize(16);
        font1.setBold(true);
        label_2->setFont(font1);
        checkboxreq = new QRadioButton(createTask);
        checkboxreq->setObjectName("checkboxreq");
        checkboxreq->setGeometry(QRect(40, 190, 121, 51));
        scorereq = new QRadioButton(createTask);
        scorereq->setObjectName("scorereq");
        scorereq->setGeometry(QRect(40, 240, 121, 51));
        label_3 = new QLabel(createTask);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(40, 140, 211, 51));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Ubuntu Light")});
        font2.setPointSize(13);
        font2.setBold(true);
        label_3->setFont(font2);
        label_4 = new QLabel(createTask);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(40, 310, 211, 51));
        label_4->setFont(font2);
        notereq = new QLineEdit(createTask);
        notereq->setObjectName("notereq");
        notereq->setGeometry(QRect(40, 360, 441, 31));
        label_5 = new QLabel(createTask);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(200, 140, 211, 51));
        label_5->setFont(font2);
        isUrgent = new QRadioButton(createTask);
        isUrgent->setObjectName("isUrgent");
        isUrgent->setGeometry(QRect(200, 180, 121, 51));
        add_b = new QPushButton(createTask);
        add_b->setObjectName("add_b");
        add_b->setGeometry(QRect(150, 420, 231, 61));
        label_6 = new QLabel(createTask);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(320, 160, 191, 171));
        label_6->setSizeIncrement(QSize(0, 0));
        pushButton = new QPushButton(createTask);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(460, 10, 61, 61));
        QFont font3;
        font3.setPointSize(26);
        pushButton->setFont(font3);
        pushButton->setStyleSheet(QString::fromUtf8("border-color: rgb(255, 255, 255);\n"
"background-color: rgb(246, 97, 81);"));

        retranslateUi(createTask);

        QMetaObject::connectSlotsByName(createTask);
    } // setupUi

    void retranslateUi(QDialog *createTask)
    {
        createTask->setWindowTitle(QCoreApplication::translate("createTask", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("createTask", "Name:", nullptr));
        label_2->setText(QCoreApplication::translate("createTask", "Manage a task!", nullptr));
        checkboxreq->setText(QCoreApplication::translate("createTask", "Checkbox", nullptr));
        scorereq->setText(QCoreApplication::translate("createTask", "Score", nullptr));
        label_3->setText(QCoreApplication::translate("createTask", "Type:", nullptr));
        label_4->setText(QCoreApplication::translate("createTask", "Notes (optional):", nullptr));
        label_5->setText(QCoreApplication::translate("createTask", "Urgent:", nullptr));
        isUrgent->setText(QCoreApplication::translate("createTask", "Yes", nullptr));
        add_b->setText(QCoreApplication::translate("createTask", "Add", nullptr));
        label_6->setText(QCoreApplication::translate("createTask", "<html><head/><body><p><img src=\":/logo_small.png\"/></p></body></html>", nullptr));
        pushButton->setText(QCoreApplication::translate("createTask", "x", nullptr));
    } // retranslateUi

};

namespace Ui {
    class createTask: public Ui_createTask {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATETASK_H
