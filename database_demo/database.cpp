#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string.h>

#include "database.h"

sqlite3* Database::database = nullptr;
std::vector<myObjective> Database::objectiveBuffer;

// Opens the database from the given path.
sqlite3* Database::open(const char *path) {
    sqlite3_open(path, &database);

    auto sql = "CREATE TABLE IF NOT EXISTS Tasks ("
    "id INTEGER PRIMARY KEY AUTOINCREMENT,"
    "name TEXT NOT NULL DEFAULT 'New  Task',"
    "date TEXT NOT NULL,"
    "type TEXT CHECK ( type IN ('CHECKBOX', 'SCORE') ) NOT NULL DEFAULT 'CHECKBOX',"
    "completed BOOL NOT NULL DEFAULT false,"
    "note TEXT,"
    "score INTEGER NOT NULL DEFAULT 0"
    ");";

    auto rcq = sqlite3_exec(database, sql, taskQueryCallback, 0, nullptr);

    return database;
}

// Returns a new vector of ALL the tasks in the database as Objective objects.
std::vector<myObjective> Database::getAllObjectives() {
    // Check if the database is opened.
    if(database == nullptr)
        throw std::runtime_error("Database: Attempting to access database when no database has been loaded.");
    
    // Clear the vector buffer.
    objectiveBuffer.clear();

    // Query the database for all the tasks and get vector of Objectives.
    auto sql = "SELECT * FROM Tasks;";
    auto rcq = sqlite3_exec(database, sql, taskQueryCallback, 0, nullptr);

    // Copy the query results into a new vector.
    std::vector<myObjective> objectives;
    for(myObjective obj : objectiveBuffer)
        objectives.push_back(obj);
    
    return objectives;
}

// Callback function used for querying the database. All task results are stored in the objective buffer.
int Database::taskQueryCallback(void *notUsed, int argc, char **argv, char **colname) {
    
    myObjective obj;
    obj.id = -1;
    obj.name = "Testing A";
    obj.date = "";
    obj.type = "";
    obj.description = "";
    obj.done = false;
    obj.score = 0;

    
    for(int i=0; i<argc; i++) {
        if(strcmp(colname[i], "id") == 0) {
            obj.id = std::stoi(argv[i]);
        }
        else if(strcmp(colname[i], "name") == 0) {
            obj.name = argv[i];
        }
        else if(strcmp(colname[i], "date") == 0) {
            obj.date = argv[i];
        }
        else if(strcmp(colname[i], "type") == 0) {
            obj.type = argv[i];
        }
        else if(strcmp(colname[i], "completed") == 0) {
            obj.done = strcmp(argv[i], "1") == 0 ? true : false;
        }
        else if(strcmp(colname[i], "note") == 0) {
            obj.description = argv[i] != nullptr ? argv[i] : "";
        }
        else if(strcmp(colname[i], "score") == 0) {
            obj.score = std::stoi(argv[i]);
        }
    }
    
    objectiveBuffer.push_back(obj);
    return 0;
}

// Inserts a single objective entry into the database. Duplicates will be ignored.
int Database::insertEntry(myObjective obj) {
    // Check if the database is opened.
    if(database == nullptr)
        throw std::runtime_error("Database: Attempting to access database when no database has been loaded.");

    // Generate the insert query with the object values.
    std::stringstream sql;
    if(obj.id != 0) {
        sql << "INSERT INTO Tasks (id, name, date, type, note, score, completed) VALUES (";
        sql << obj.id << ", ";
        sql << "\"" << obj.name << "\", ";
        sql << "\"" << obj.date << "\", ";
        sql << "\"" << obj.type << "\", ";
        sql << "\"" << obj.description << "\", ";
        sql << obj.score << ", ";
        sql << obj.done;
        sql << ");";
    }
    else {
        sql << "INSERT INTO Tasks (name, date, type, note, score, completed) VALUES (";
        sql << "\"" << obj.name << "\", ";
        sql << "\"" << obj.date << "\", ";
        sql << "\"" << obj.type << "\", ";
        sql << "\"" << obj.description << "\", ";
        sql << obj.score << ", ";
        sql << obj.done;
        sql << ");";
    }

    std::cout << "Attempting SQL: " << std::endl;
    std::cout << sql.str().c_str() << std::endl;

    return sqlite3_exec(database, sql.str().c_str(), taskQueryCallback, 0, nullptr);
}

// Updates a single objective entry in the database.
int Database::updateEntry(myObjective obj) {
    // Check if the database is opened.
    if(database == nullptr)
        throw std::runtime_error("Database: Attempting to access database when no database has been loaded.");

    // Generate the insert query with the object values.
    std::stringstream sql;
    sql << "UPDATE Tasks SET ";
    sql << "name = \"" << obj.name << "\", ";
    sql << "date = \"" << obj.date << "\", ";
    sql << "type = \'" << obj.type << "\', ";
    sql << "note = \"" << obj.description << "\", ";
    sql << "score = " << obj.score << ", ";
    sql << "completed = " << obj.done << " ";
    sql << "WHERE id = " << obj.id << ";";

    std::cout << "Attempting SQL: " << std::endl;
    std::cout << sql.str().c_str() << std::endl;

    return sqlite3_exec(database, sql.str().c_str(), taskQueryCallback, 0, nullptr);
}