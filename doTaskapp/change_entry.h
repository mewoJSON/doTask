#ifndef CHANGE_ENTRY_H
#define CHANGE_ENTRY_H

#include <QMainWindow>
#include "global.h"


namespace Ui {
class Change_entry;
}

class Change_entry : public QMainWindow
{
    Q_OBJECT

public:
    explicit Change_entry(QWidget *parent = nullptr);
    ~Change_entry();

private slots:
    void delete_entry();
    void edit_entry();
private:
    Ui::Change_entry *ui;
};

#endif // CHANGE_ENTRY_H
