#include "daywindow.h"
#include "createtask.h"
#include "ui_daywindow.h"
#include "mainwindow.h"
#include <QLabel>
#include <QCheckBox>
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
    syncQt();
}

void daywindow::goBack() {
    QWidget *wdg = new MainWindow;
    this->hide();
    wdg->show();
}

void daywindow::syncQt() {
    qDebug() << day << "vs " << day_i;

    today_tasks.clear();

    for (int i = 0; i < all_tasks.size(); i++) {
        if (all_tasks[i].date == std::to_string(month) + ' ' + day.toStdString())

        {
            qDebug() << all_tasks[i].date << " vs " << std::to_string(month) + ' ' + day.toStdString();
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

    if (today_tasks.empty()) {
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
        day = QString::number(day_i);
        syncQt();
        return;
    }
    qDebug() << "Cannot decrease month further!";
}

void daywindow::increaseMonth() {
    if (day_i != day_range[month]-1) {
        ++day_i;
        day = QString::number(day_i);
        syncQt();
        return;
    }
    else {
        day_i = 0;
    }
    qDebug() << "Cannot increase month further!";
}

void daywindow::pushTask() {
    qDebug() << "Size of tasks today: " << std::size(today_tasks);


    // code referenced from Nejat, stackoverflow (Mar 25, 2014)
    // go through widget list, delete all items in widget
    while ( QLayoutItem* item = ui->gridLayout->layout()->takeAt( 0 ) )
    {
        Q_ASSERT( ! item->layout() ); // otherwise the layout will leak
        delete item->widget();
        delete item;
    }
    int j = 0;
    for (int i = 0; i < all_tasks.size(); i++) {
        if (all_tasks[i].date == std::to_string(month) + ' ' + day.toStdString()) {
            auto button = std::make_unique<QPushButton>(this);
            button->setFlat(false);
            button->setObjectName(today_tasks[i].date);
            QString b_txt = QString::fromStdString(today_tasks[i].name);
            if (today_tasks[i].description != "")
                b_txt += "      Description: " + QString::fromStdString(today_tasks[i].description);
            button->setText(b_txt);


            m_buttons.push_back(std::move(button));
            ui->gridLayout->addWidget(m_buttons.back().get(),j,0);
            if (today_tasks[i].type == "Checkbox") {
                auto check = std::make_unique<QCheckBox>(this);
                check->setObjectName(QString::number(i));
                check->setChecked(all_tasks[i].done);
                m_check.push_back(std::move(check));


                ui->gridLayout->addWidget(m_check.back().get(),j,1);
                QObject::connect(m_check.back().get(), SIGNAL(clicked()), this, SLOT(is_done()));
            }
            ++j;
            QObject::connect(m_buttons.back().get(), SIGNAL(clicked()), this, SLOT(edit()));
        }
    }

}

void daywindow::edit() {

    last_clicked = qobject_cast< QPushButton* >( sender() );
    last_index = last_clicked->objectName().toInt();


    // save
    all_tasks.erase(all_tasks.begin()+last_index);
    syncQt();
}

void daywindow::modify() {

    this->hide();

}

void daywindow::is_done() {
    QCheckBox* checkClicked = qobject_cast< QCheckBox* >( sender() );
    all_tasks[(checkClicked->objectName().toInt())].done = checkClicked->isChecked();
    qDebug() << "is done: ";
}
