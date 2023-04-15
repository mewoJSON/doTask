'''
Authors: Julian Bottero, Joey Stasiulis
Date: Apr 14, 19:28

Concept: 
1. ask user for month
2. ask user for day of month
3. ask user for task name
4. add info to list
5. Ask user if they want to add more
6. If user exits program, output of all tasks + dates are added
'''
import sys
from helper import *
from task import *

def main():

    # Initalize task counter
    total_tasks = 0
    
    # Initalize empty list
    task_l = []
    
    #opening message
    print("Welcome to doTask, choose a month to start! ")
    
    # generate month arrays
    jan = list(range(1,32))
    feb = list(range(1,29))
    march = list(range(1,32))
    april = list(range(1,31))
    may = list(range(1,32))
    june = list(range(1,31))
    july = list(range(1,32))
    august = list(range(1,32))
    september = list(range(1,31))
    october = list(range(1,32))
    november = list(range(1,31))
    december = list(range(1,32))

    # Add months to variable
    months = jan,feb,march,april,may,june,july,august,september,october,november,december

    # Ask for month of task
    io_month = int(input('Enter month (number): '))
    
    # Display month and days
    month_str = num_to_month(io_month)

    print('\nDisplaying',month_str)
    print('--------------------------------------------------------')
    
    # Ror loop to output the calendar formatting
    for entry in months[io_month-1]:
        print(entry,'\t', end=' ')
        if entry % 7 == 0:
            print()
    print('\n--------------------------------------------------------')

    # Recieve the day input from user
    io_day = int(input('\nEnter day (number): '))

    # Collect task input from the user
    io_task = input('\nEnter name of the task, press (Q) to Quit: ')
    
    # While loop to manage user input
    while io_task != 'Q' or io_task != 'q':
        print('Thank you for adding task. Task is now added to list!')
        # Add input to list
        task_l += [io_task]
        
        # Add to total task counter
        total_tasks += 1
        print('There are currently', total_tasks, 'tasks.')
        io_task = input('Would you like to add any more tasks? Press (A) to Add or (Q) to Quit: ')

        # If statement to check if user wants to exit program
        if io_task == 'Q' or io_task == 'q':
            print('Quitting program, have a wonderful day!')
            print('Tasks created: ')
            # For loop to traverse and output the table of tasks
            for row in task_l:
                print(io_month,'/',io_day, ' - ',row)
            exit()
        
        # Reloop if prompted
        while io_task == 'A' or io_task == 'a':
            io_month = int(input('Enter month (number): '))
            month_str = num_to_month(io_month)
            print('\nDisplaying',month_str)
            print('--------------------------------------------------------')
            for entry in months[io_month-1]:
                print(entry,'\t', end=' ')
                if entry % 7 == 0:
                    print()
            print('\n--------------------------------------------------------')
            io_day = int(input('\nEnter day (number): '))
            io_task = input('\nEnter name of the task, press (Q) to Quit: ')
            print('Thank you for adding task. Task is now added to list!')
            task_l += [io_task]
            total_tasks += 1
            print('There are currently', total_tasks, 'tasks.')
            io_task = input('Would you like to add any more tasks? Press (A) to Add or (Q) to Quit: ')

        for row in task_l:
            print(io_month,'/',io_day, ' - ',row)    
        exit()

main()