/*
#include <iostream>
#include <vector>
#include <sqlite3.h>
#include "objective.cpp"

class Database {
public:
    static sqlite3* open(const char *path);
    static std::vector<myObjective> getAllObjectives();
    static int insertEntry(myObjective obj);
    static int updateEntry(myObjective obj);
private:
    static sqlite3* database;
    static std::vector<myObjective> objectiveBuffer;
    static int taskQueryCallback(void *notUsed, int argc, char **argv, char **azColName);
};

*/
