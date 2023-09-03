// A file EVENTS consists of records of events that have occurred during one calendar year. 
// Each record describes one event and starts with a date field giving the number of the day
// in the year during which the event occurred. The file is ordered in ascending order by 
// this day number. A file SELECT consists of single-field records, the field being a day no.
// The file too is ordered in ascending sequence by this field. Write a program which reads
// these 2 files and produces a report which shows, for each date in SELECT, the no. of events 
// which occurred on that date.

#include <stdio.h>

int main() {
    FILE *events_file, *select_file;
    int events_day, select_day, events_count, select_count;
    
    events_file = fopen("events.txt", "r");
    select_file = fopen("select.txt", "r");
    
    if (events_file == NULL || select_file == NULL) {
        printf("Error opening files.");
        return 1;
    }
    
    fscanf(select_file, "%d", &select_day);
    events_count = 0;
    
    printf("Day \tEvents\n");
    while (fscanf(events_file, "%d", &events_day) != EOF) {
        if (events_day == select_day) {
            events_count++;
        }else if (events_day > select_day) {
            printf("%-4d\t%-4d\n", select_day, events_count);
            select_count = fscanf(select_file, "%d", &select_day);
            if (select_count == EOF) {
                break;
            }
            events_count = 0;
        }
    }
    
    while (fscanf(select_file, "%d", &select_day) != EOF) {
        printf("%-4d\t0\n", select_day);
    }
    
    fclose(events_file);
    fclose(select_file);
    
    return 0;
}
