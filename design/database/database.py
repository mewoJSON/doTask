
import sqlite3

from sqlite3 import Error

# Connects to the sqlite3 database at the given path or create one if it does not exist. Returns the connection object.
def connect(path):
    # Create a connection object to hold the established connection.
    connection = None

    # Attempt to connect to the database with the given path.
    try:
        connection = sqlite3.connect(path)
        print("Connection to database successful.")
    except Error as e:
        print("Connection Error: {}".format(e))
    
    # Return the connection object.
    return connection

# Performs a query on the database which does not return any results.
def execute_query(connection, query):
    cursor = connection.cursor()
    try:
        cursor.execute(query)
        connection.commit()
        print("Execution query executed successfully.")
    except Error as e:
        print("Execution Query Error: {}".format(e))

# Performs a query on the database that returns the results of the query.        
def retrieve_query(connection, query):
    cursor = connection.cursor()
    result = None
    try:
        cursor.execute(query)
        result = cursor.fetchall()
        print("Retrieval query executed successfully.")
    except Error as e:
        print("Retrieval Query Error: {}".format(e))
    return result