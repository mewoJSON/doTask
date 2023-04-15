
#include "database.h"

void printObjs(std::vector<myObjective> objs) {
    for(myObjective obj : objs) {
        std::cout << "ID: " << obj.id << std::endl;
        std::cout << "Name: " << obj.name << std::endl;
        std::cout << "Date: " << obj.date << std::endl;
        std::cout << "Type: " << obj.type << std::endl;
        std::cout << "Description: " << obj.description << std::endl;
        std::cout << "Score: " << obj.score << std::endl;
        std::cout << "Done: " << obj.done << std::endl;
        std::cout << std::endl;
    }
}

int main(int argc, char** argv) {

    // Open the database with the 'test.db' file.
    Database::open("test.db");

    // Create a list of objectives to hold the query.
    std::vector<myObjective> objs;

    // Get all the objectives from the database.
    objs = Database::getAllObjectives();

    // Insert a new objective/task into the database.
    myObjective newObj;
    newObj.id = 0; // New tasks must have an id value of 0 otherwise an error will occur.
    newObj.name = "Out task!";
    newObj.date = "5 8";
    newObj.description = "";
    newObj.done = true;
    newObj.score = 7;
    newObj.type = "SCORE";
    
    // Insert the new objective. Also check for an error C-style.
    // The insert function will throw an error if you attempt to insert duplicate entry.
    // HOWEVER: the query goes off the id from the c++ object so if you repeat this it will
    // create duplicates anyways. The duplicate check is based on the id value in the object
    // which does not change. In order to update/change the id value you will need to 
    // query all the tasks again and then find the objective from that list. (very awful)
    if(Database::insertEntry(newObj) != 0)
        std::cout << "Insert Error!" << std::endl;

    // Update the tasks list with new task.
    objs = Database::getAllObjectives();

    //printObjs(objs);

    // Just to assure no duplications can be inserted, find the obj we just inserted and
    // try to insert it again.
    myObjective ourObj;
    for(myObjective obj : objs)
        if(obj.name == newObj.name)
            ourObj = obj;

    // newObj and ourObj are identical except for one thing: the id.
    // Because the id is assigned by the database software we MUST retrieve the new
    // object from the database which will actually have an id. newObj still does not have
    // an id so it is very risky to use, may cause duplications or risk incorrect updates.
    // Discard the obj used to insert after it is inserted.

    // Check if duplicate insertion works or not.
    if(Database::insertEntry(ourObj) != 0)
        std::cout << "Insert Duplication Prevented!" << std::endl;

    //printObjs(objs);

    // Now we are going to update outObj and change a couple fields then update the 
    // database. Same thing applies here, sync your objs with the database after update.
    if(Database::updateEntry(newObj) != 0)
        std::cout << "Update Error!" << std::endl;

    objs = Database::getAllObjectives();
    
    //printObjs(objs);
}