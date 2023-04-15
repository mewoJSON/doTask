#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include <QMainWindow>
#include <QPushButton>
#include <QDebug>
#include <vector>
#include "global.h"
#include "objective.cpp"



QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

    friend class Share;

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    // counter for current month and day

    // initialize an array to keep track of how many buttons to display per month
    int day_range[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    QString month_range[12] = {"January","February","March","April","May","June","July","August","September","October","November","December"};
    std::vector<std::unique_ptr<QPushButton>> m_buttons;

private slots:
    void quit();
    void syncQt();
    void generateGrid();
    void decreaseMonth();
    void increaseMonth();
    void openDay();

};
#endif // MAINWINDOW_H
