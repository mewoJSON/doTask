#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "daywindow.h"

// global variables
const QSize B_SIZE(20,20);

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    // set year
    ui->year_l->setText("2023");
    syncQt();
    // signals
    QObject::connect(ui->quit_b, SIGNAL(clicked()),
                     this, SLOT(quit()));
    QObject::connect(ui->left_b, SIGNAL(clicked()),
                     this, SLOT(decreaseMonth()));
    QObject::connect(ui->right_b, SIGNAL(clicked()),
                     this, SLOT(increaseMonth()));



}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::quit() {
    QApplication::quit();
}

void MainWindow::syncQt() {
    ui->month_l->setText(month_range[month]);

    if (month == 0) {
        ui->left_b->setFlat(true);
    }
    else if (month == 11) {
        ui->right_b->setFlat(true);
    }
    else {
        ui->left_b->setFlat(false);
        ui->right_b->setFlat(false);
    }
    m_buttons.clear();
    generateGrid();

}

void MainWindow::decreaseMonth() {
    if (month != 0) {
        --month;
        syncQt();
        return;
    }
    qDebug() << "Cannot decrease month further!";
}

void MainWindow::increaseMonth() {
    if (month != 11) {
        ++month;
        syncQt();
        return;
    }
    qDebug() << "Cannot increase month further!";
}

void MainWindow::generateGrid() {

    int current_month = day_range[month];
    int j = 0;
    int i = 0;

    for (int k = 0; k < current_month; k++) {
        auto button = std::make_unique<QPushButton>(this);
        button->setIconSize(B_SIZE);
        button->setFlat(false);
        button->setObjectName(QString::number(k));
        button->setText(QString::number(k+1));
        m_buttons.push_back(std::move(button));
        if (i % 7 == 0) {
            ++j;
            i = 0;
        }
        ui->gridLayout->addWidget(m_buttons.back().get(), j, i);
        ++i;
        QObject::connect(m_buttons.back().get(), SIGNAL(clicked()), this, SLOT(openDay()));
    }
}

void MainWindow::openDay() {
    QPushButton* dayClicked = qobject_cast< QPushButton* >( sender() );
    day = dayClicked->objectName();
    qDebug() << "Day is: "<<day;
    QWidget *window = new daywindow;
    window->show();
    this->hide();
}

