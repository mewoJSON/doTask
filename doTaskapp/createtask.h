#ifndef CREATETASK_H
#define CREATETASK_H

#include <QDialog>

namespace Ui {
class createTask;
}

class createTask : public QDialog
{
    Q_OBJECT

public:
    explicit createTask(QWidget *parent = nullptr);
    ~createTask();
private slots:
    void setTask();

private:
    Ui::createTask *ui;
};

#endif // CREATETASK_H
