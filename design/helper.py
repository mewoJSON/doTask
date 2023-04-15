'''
Misc. Functions to properly control code flow structure and display data

'''

# Purpose: Return month string given a number
# Pre:     Month @int
# Post:    Month @str

def num_to_month(month):
    match month:
        case 1:
            return 'January'
        case 2:
            return 'Feburary'
        case 3:
            return 'March'
        case 4:
            return 'April'
        case 5:
            return 'May'
        case 6:
            return 'June'
        case 7:
            return 'July'
        case 8:
            return 'August'
        case 9:
            return 'September'
        case 10:
            return 'October'
        case 11:
            return 'November'
        case 12:
            return 'December'
