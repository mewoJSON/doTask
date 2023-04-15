'''
Authors: Julian Bottero, Joey Stasiulis, Noah Goins
Date: Apr 14, 19:28

Concept: 
1. ask user for months
2. ask user for day of month
3. open entry for month from database
4.2 (???) Create a task class to properly display each task (tasks may be different)
4. display entry's for data

5. allow user to add data, edit, remove, or go back to page
6. update database info
'''

import sys
from helper import *
from task import *

def main(): 
    # initalize 'global' vals
    total_tasks = 0
    # min size of task prints
    TASK_MIN_LIM_DISP = 6
    
    # init empty list
    task_l = []
    task = Task('Finish','CHECKBOX','13')
    task_l.append(task)
    
    #opening message
    print("Welcome to doTask, choose a month to start! ")
    
    # generate month arrays
    # TO-DO: GENERATE ALL MONTHS
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

    # add months to all months list HARD-CODED
    months = jan,feb,march,april,may,june,july,august,september,october,november,december

    # ask for user input
    io_month = int(input('Enter month (number): '))
    
    # display month days
    month_str = num_to_month(io_month)

    print('\nDisplaying',month_str)
    print('--------------------------------------------------------')
    for entry in months[io_month-1]:
        print(entry,'\t', end=' ')
        if entry % 7 == 0:
            print()
    print('\n--------------------------------------------------------')

    io_day = int(input('\nEnter day (number): '))

    # Collect task input from the user
    io_task = input('\nEnter name of the task, press (Q) to Quit: ')
    
    # While loop to manage user input
    while io_task != 'Q' or 'q':
        print('Thank you for adding task. Task is now added to list!')
        task_l += [[io_task]]
        total_tasks += 1
        print('There are currently', total_tasks, 'tasks.')
        io_task = input('Would you like to add any more tasks? Press (A) to Add or (Q) to Quit: ')

        if io_task == 'Q' or io_task == 'q':
            print('Quitting program, have a wonderful day!')
            exit()
        
        # Reloop if prompted
        while io_task == 'A' or 'a':
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
            task_l += [[io_task]]
            total_tasks += 1
            print('There are currently', total_tasks, 'tasks.')
            io_task = input('Would you like to add any more tasks? Press (A) to Add or (Q) to Quit: ')
            if io_task == 'Q' or  io_task == 'q':
                print('Quitting program. Have a wonderful day!')
                exit()
        if io_task == 'Q' or io_task == 'q':
            print('Quitting program. Have a wonderful day!')
            exit()

main()