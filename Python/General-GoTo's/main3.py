# Time Calculator - Military Times
try:
    def Time_Diff(a, b):
        difference_hours = b // 100 - a // 100
        difference_minutes = b % 100 - a % 100
        hours_to_minutes = difference_hours * 60
        difference = hours_to_minutes + difference_minutes
        final_hours = difference // 60
        final_minutes = difference % 60

        if final_hours != 0:
            if final_minutes != 0:
                print(f'{final_hours} hour(s) and {final_minutes} minute(s)')
            else:
                print(f'{final_hours} hour(s)')
        if final_hours == 0:
            if final_minutes != 0:
                print(f'{final_minutes} minute(s)')
            else:
                print('Both the times are the same.')


    time1 = int(input('Please enter the first time: '))
    time2 = int(input('Please enter the second time: '))
    Time_Diff(time1, time2)

except ValueError:
    print('Input Error')
    print('Military Time is an integer...')
