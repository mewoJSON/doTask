import database as db


cn = db.connect("db_test.sqlite")

eq_create_table_tasks = """
CREATE TABLE IF NOT EXISTS tasks (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    type TEXT CHECK ( type IN ('checkbox', 'event', 'note') ) NOT NULL DEFAULT 'note',
    type_id INTEGER NOT NULL
);
"""

eq_insert_test_tasks = """
INSERT INTO tasks(type, type_id) VALUES
()
"""

db.execute_query(cn, eq_create_table_tasks)