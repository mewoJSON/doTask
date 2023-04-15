'''
Task Class

When the database loads the items, based on their information it will assign it to a type of class
'''


'''
Purpose: create a task and define its type. How it is define will affect how it is displayed when ultimately 
'''
class Task():
    def __init__(self, name, type, date) -> None:
        # primary values
        self.name = name
        self.date = date
        self.type = type

        # secondary values (either optimal or generated the same no matter the outcome)
        self.priority = ''
        self.note = ''
        self.done = False

    def __str__(self):
        match type:
            case 'CHECKBOX':
                if self.done == True:
                    return str(self.name) + '[V]\t' + str(self.note)
                else:
                    return (str(self.name) + '[V]\t' + str(self.note))
                        



        