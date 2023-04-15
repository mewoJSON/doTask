#include "createtask.h"
#include "ui_createtask.h"
#include "global.h"


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
    QString f_name = ui->namereq->text();
    std::string t_name = f_name.toStdString();
    std::string t_date = std::to_string(month) + ' ' +day.toStdString();

    job.date = t_date;
    job.name = t_name;
    job.type = t_type;

    all_tasks.push_back(job);

    this->hide();


}

