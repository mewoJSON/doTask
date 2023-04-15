#include "daywindow.h"
#include "createtask.h"
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
    QWidget *window = new createTask;
    window->show();
}

void daywindow::goBack() {
    QWidget *wdg = new MainWindow;
    this->hide();
    wdg->show();
}

void daywindow::syncQt() {

    today_tasks.clear();

    for (int i = 0; i < all_tasks.size(); i++) {
        if (all_tasks[i].date == std::to_string(month) + ' ' + day.toStdString())
        {
            today_tasks.push_back(all_tasks[i]);
        }
    }

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

    }

    pushTask();
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

void daywindow::pushTask() {
    for (int i = 0; i < today_tasks.size(); i++) {
        auto button = std::make_unique<QPushButton>(this);
        button->setObjectName(today_tasks[i].date);
        m_buttons.push_back(std::move(button));
        ui->gridLayout->addWidget(m_buttons.back().get(), 1, i);
        //QObject::connect(m_buttons.back().get(), SIGNAL(clicked()), this, SLOT(edit()));
    }

}

void daywindow::edit() {

}
