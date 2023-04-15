#ifndef DAYWINDOW_H
#define DAYWINDOW_H

#include <QMainWindow>
#include "mainwindow.h"
#include "objective.h"

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
    void syncQt();
    void decreaseMonth();
    void increaseMonth();
    void addTask();
private:
    Ui::daywindow *ui;
    int day_i = day.toInt();
    int day_range[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    QString month_range[12] = {"January","February","March","April","May","June","July","August","September","October","November","December"};
    std::vector<std::unique_ptr<QPushButton>> m_buttons;

};

#endif // DAYWINDOW_H