### Database Design Specs/Code

## Details

The tasks will be implemented using various tables. Each task will be stored in a 
task "master" table which will also hold its type, and the id of that task stored 
in its associated task specific table. The task specific tables
hold additional details about the tasks relevent to its type.

## Tables

# Tasks Master Table
CREATE TABLE IF NOT EXISTS tasks (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    type TEXT CHECK ( type IN ('', '', '') ) NOT NULL DEFAULT '',
    type_id INTEGER NOT NULL,
    FOREIGN KEY (type_id)

);

#