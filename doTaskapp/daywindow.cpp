#include "daywindow.h"
#include "ui_daywindow.h"
#include "mainwindow.h"
#include <QLabel>

daywindow::daywindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::daywindow)
{
    ui->setupUi(this);
    ui->year_l->setText("2023");
    ui->empty_l->setGeometry(200,300,ui->empty_l->width(),ui->empty_l->height());


    syncQt();

    QObject::connect(ui->back_b, SIGNAL(clicked()),
                     this, SLOT(goBack()));
    QObject::connect(ui->right_b, SIGNAL(clicked()),
                     this, SLOT(increaseMonth()));
    QObject::connect(ui->left_b, SIGNAL(clicked()),
                     this, SLOT(decreaseMonth()));
    QObject::connect(ui->add_b, SIGNAL(clicked()),
                     this, SLOT(addTask()));

}

daywindow::~daywindow()
{
    delete ui;
}

void daywindow::addTask()
{

}

void daywindow::goBack() {
    QWidget *wdg = new MainWindow;
    this->hide();
    wdg->show();
}

void daywindow::syncQt() {


    ui->year_l->setText("2023");
    ui->month_l->setText(month_range[month]);
    ui->day_l->setText(QString::number(day_i+1));

    if (day_i == 0) {
        ui->left_b->setFlat(true);
    }
    else if (day_i == day_range[month]-1) {
        ui->right_b->setFlat(true);
    }
    else {
        ui->left_b->setFlat(false);
        ui->right_b->setFlat(false);
    }

    if (true == true) {
        ui->empty_l->setText("This entry is empty! Start by creating some tasks!");
    }
    else {
        ui->empty_l->setText("");
\
    }
}
void daywindow::decreaseMonth() {
    if (day_i != 0) {
        --day_i;
        syncQt();
        return;
    }
    qDebug() << "Cannot decrease month further!";
}

void daywindow::increaseMonth() {
    if (day_i != day_range[month]-1) {
        ++day_i;
        syncQt();
        return;
    }
    qDebug() << "Cannot increase month further!";
}
