#ifndef DAYWINDOW_H
#define DAYWINDOW_H

#include <QMainWindow>
#include "mainwindow.h"
#include "objective.cpp"
#include <QPushButton>
#include <QCheckBox>
#include <QDialogButtonBox>
#include <QDialog>

namespace Ui {
class daywindow;
}

class daywindow : public QMainWindow
{

    Q_OBJECT

public:
    explicit daywindow(QWidget *parent = nullptr);
    ~daywindow();

private slots:
    void goBack();
    void modify();
    void syncQt();
    void decreaseMonth();
    void increaseMonth();
    void addTask();
    void pushTask();
    void edit();
    void is_done();

private:
    Ui::daywindow *ui;
    int day_i = day.toInt();
    int day_range[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    QString month_range[12] = {"January","February","March","April","May","June","July","August","September","October","November","December"};

    std::vector<std::unique_ptr<QPushButton>> m_buttons;
    std::vector<std::unique_ptr<QCheckBox>> m_check;

    //std::vector<myObjective> m_tasks;

    std::vector<myObjective> today_tasks;
};

#endif // DAYWINDOW_H
