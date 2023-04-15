'''
Authors: Julian Bottero, Joey Stasiulis
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


    #
    # WHILE LOOP (sent. logic)
    #

    # choose day
    print('--------------------------------------------------------')
    print('\t\t','2023,',month_str,io_day,'\t\t\t')

    for task in task_l:
        print(task)
    
    if (len(task_l) < 3):

        for task in range(TASK_MIN_LIM_DISP-len(task_l)):
            print()

    # add, edit, remove

    print('\n--------------------------------------------------------')
    print('(a) to Add task  (e) to Edit task  (r) to remove task')
    print('\t  (b) to go Back, (q) to Quit')
    print('--------------------------------------------------------')


main()