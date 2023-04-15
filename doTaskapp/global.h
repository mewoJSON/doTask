#include <QString>
#include <stdio.h>
#include <vector>
#include "objective.cpp"
#include "qpushbutton.h"
#include <QFileInfo>


/*
 *
 * Global file that contains variables that will be used across all programs.
 * Contains an objective class for initializing a single task, and a vector to locally and temporarily cover all the tasks
 *
 */
extern int month;
extern QString day;

extern myObjective job;
extern std::vector<myObjective> all_tasks;
extern int last_index;
extern QPushButton* last_clicked;

