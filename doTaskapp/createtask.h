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
    void setScore();
    void setCheckbox();
    void setTask();

private:
    std::string t_type = "Checkbox";
    Ui::createTask *ui;
};

#endif // CREATETASK_H
