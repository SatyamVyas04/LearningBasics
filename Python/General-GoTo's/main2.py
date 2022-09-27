# MMDDYYYY to <Month><Date><Year> converter
try:
    date_input = input('Enter date in MMDDYYYY format: ')
    months = {'01': 'January', '02': 'February', '03': 'March',
              '04': 'April', '05': 'May', '06': 'June',
              '07': 'July', '08': 'August', '09': 'September',
              '10': 'October', '11': 'November', '12': 'December'}
    days_in_month = {'January': 31, 'February': 28, 'March': 31,
                     'April': 30, 'May': 31, 'June': 30,
                     'July': 31, 'August': 31, 'September': 30,
                     'October': 31, 'November': 30, 'December': 31}
    # ALL POSSIBILITIES
    if date_input.isdigit() and len(date_input) == 8:
        date = int(date_input[2:4])
        month = months.get(date_input[:2])
        year = int(date_input[4:])
        # CHECK MONTH BEING LESS THAN 12 AND DATE LESS THAN 31
        if month is not None and date <= days_in_month.get(month):
            print(f'{month} {date}, {year}')
        else:
            print('Non-existent Date')

    if len(date_input) == 9 and date_input[4:5] == '-':
        date = int(date_input[2:4])
        month = months.get(date_input[:2])
        year = int(date_input[5:])
        # CHECKING FOR DATE BEING DIGITS ONLY
        list1 = list(date_input)
        list1.remove('-')
        x = ''.join(list1)
        # CHECK MONTH BEING LESS THAN 12 AND DATE LESS THAN 31
        if x.isdigit() and month is not None and date <= days_in_month.get(month):
            print(f'{month} {date}, {year}BCE')
        else:
            print('Non-existent Date')
    # POSSIBLE ERROR
    elif len(date_input) > 9 or (len(date_input) == 9 and '-' not in date_input):
        print('Input Error... MMDDYYYY must contain only 8 digits'
              '\nFor writing BCE date, Enter MMDD-YYYY')
except ValueError:
    print('Input Error... MMDDYYYY must contain only 8 digits'
          '\nFor writing BCE date, Enter MMDD-YYYY')
