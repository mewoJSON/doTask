import database as db


cn = db.connect("db_test.sqlite")

eq_create_table_tasks = """
CREATE TABLE IF NOT EXISTS tasks (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    type TEXT CHECK ( type IN ('checkbox', 'event', 'note') ) NOT NULL DEFAULT 'note',
    type_id INTEGER NOT NULL
);
"""

db.execute_query(cn, eq_create_table_tasks)