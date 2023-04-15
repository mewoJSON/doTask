#include "createtask.h"
#include "ui_createtask.h"

createTask::createTask(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::createTask)
{
    ui->setupUi(this);
    QObject::connect(ui->add_b, SIGNAL(clicked()),
                     this, SLOT(quit()));
}

createTask::~createTask()
{
    delete ui;
}

void createTask::setTask() {

}

