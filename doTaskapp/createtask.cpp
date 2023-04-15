#include "createtask.h"
#include "ui_createtask.h"
#include "global.h"
#include <QDebug>

createTask::createTask(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::createTask)
{
    ui->setupUi(this);
    QObject::connect(ui->add_b, SIGNAL(clicked()),
                     this, SLOT(setTask()));
    QObject::connect(ui->scorereq, SIGNAL(clicked()),
                     this, SLOT(setScore()));
    QObject::connect(ui->checkboxreq, SIGNAL(clicked()),
                     this, SLOT(setCheckbox()));
    QObject::connect(ui->exit_q, SIGNAL(clicked()),
                     this, SLOT(exit()));
}

createTask::~createTask()
{
    delete ui;
}

void createTask::setScore() {
    ui->checkboxreq->setChecked(false);
    t_type = "Score";
}

void createTask::setCheckbox() {
    ui->scorereq->setChecked(false);
    t_type = "Checkbox";
}

void createTask::setTask()
{
    job.id = all_tasks.size();
    QString f_name = ui->namereq->text();
    std::string t_name = f_name.toStdString();
    std::string t_date = std::to_string(month) + ' ' +day.toStdString();
    std::string t_description = (ui->notereq->text()).toStdString();

    job.date = t_date;
    if (t_name == "") {
        t_name = "Task " + std::to_string(all_tasks.size());
    }

    job.name = t_name;
    job.type = t_type;
    job.description = t_description;
    qDebug() << job.date;

    all_tasks.push_back(job);

    this->hide();


}

void createTask::exit() {
    this->hide();
}
