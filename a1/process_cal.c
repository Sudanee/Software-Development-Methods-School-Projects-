#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX_LINE_LEN 200
#define MAX_EVENTS 1000

struct{
    char description[50];
    char timezone[50];
    char time[50];
    char location[50];
    int day;
    int month;
    int year;
    char dweek[50];
    char start_time[50];
    char end_time[50];
    int num_events;
} Event;

struct{
    int year;
    int month;
    int day;
} Date_input_start;

struct{
    int year;
    int month;
    int day;
} Date_input_end;

struct{
    int day;
    int month;
    int year;
} check_dates;

struct{
    char start_time[50];
    char end_time[50];
} formated_times;

typedef struct{
    char one[50];
    char two[50];
    char three[50];
    char four[50];
    char five[50];
    char six[50];
    char seven[50];
    char eight[50];
    char nine[50];
    char ten[50];
    char eleven[50];
    char twelve[50];
} Calendar;

struct{
    int event_day;
    int event_month;
    int event_year;
} temp_event_date;

int valid_months[50];
int valid_days[50];
int valid_years[50];
int all_months[50];
int all_days[50];
int all_years[50];
int print_all[100][100];
int all_events = 0;
int print_count = 0;
char message[50];

Calendar m = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};


int printlines(int length){
    for(int i = 0; i < length+2; i++){
        printf("-");
    }
    printf("\n");
}

int get_input_dates(char start[], char end[]){

    char start_date[50];
    char end_date[50];

    char delim[] = "--start=";
    char *ptr = strtok(start, delim);

    while(ptr != NULL){
        
        strcpy(start_date, ptr);
        ptr = strtok(NULL, delim);

    }

    char delim2[] = "--end=";
    ptr = strtok(end, delim2);

    while(ptr != NULL){
        
        strcpy(end_date, ptr);
        ptr = strtok(NULL, delim2);

    }
    
    char delim3[] = "/";
    ptr = strtok(start_date, delim3);

    while (ptr != NULL){
        
        int get = atoi(ptr);
        Date_input_start.year = get;
        ptr = strtok(NULL, delim3);

        get = atoi(ptr);
        Date_input_start.month = get;
        ptr = strtok(NULL, delim3);
        
        get = atoi(ptr);
        Date_input_start.day = get;
        ptr = strtok(NULL, delim3);
    }

    ptr = strtok(end_date, delim3);

    while (ptr != NULL){

        int get = atoi(ptr);
        Date_input_end.year = get;
        ptr = strtok(NULL, delim3);

        get = atoi(ptr);
        Date_input_end.month = get;
        ptr = strtok(NULL, delim3);
        
        get = atoi(ptr);
        Date_input_end.day = get;
        ptr = strtok(NULL, delim3);
    }

    return 0;

}

int compare_dates(int a[], int b[]){

    if (a[2] < b[2]){
        return 1;
    }
    
    if (a[2] == b[2]){
        
        if (a[1] < b[1]){
            return 1;
        }

        if (a[1] == b[1]){
            
            if (a[0] < b[0]){
                return 1;
            }
            
            if (a[0] == b[0]){
                return 1;
            }

        }

    }  
    
    return 0;


}

int convert_time(int time){

    char format[50];

    if (time > 12){
        int convert = time - 12;
        time = convert;
    }

    return time;
    
}

int time_format(){

    int convert_start_time = atoi(Event.start_time);
    int convert_end_time = atoi(Event.end_time);

    char find_start[50];
    char find_end[50];
    char add_zero[] = "0";

    convert_start_time = convert_time(convert_start_time);
    convert_end_time = convert_time(convert_end_time);
    
    sprintf(find_start, "%d", convert_start_time);
    sprintf(find_end, "%d", convert_end_time);

    
    if (strlen(find_start) == 1){
        
        strncat(formated_times.start_time, add_zero, 50);
        strncat(formated_times.start_time, find_start, 50);
       

    }
    
    if (strlen(find_start) != 1){
        strncat(formated_times.start_time, find_start, 50);
    }
    
    
    if (strlen(find_end) == 1){
            
        strncat(formated_times.end_time, add_zero, 50);
        strncat(formated_times.end_time, find_end, 50);
    }
    
    if (strlen(find_end) != 1){

        strncat(formated_times.end_time, find_end, 50); 


    }
        

    return 0;

}

int printanswer(int print[][3]){
    
    char space[] = " ";
    char comma[] = ",";
    char empty[] = "";
    char temp[50];
    
    
    if (print_count != all_events){
        
        if (print[print_count][1] == Event.month && print[print_count][0] == Event.day && print[print_count][2] == Event.year){
            
            if ((temp_event_date.event_month != Event.month || temp_event_date.event_day != Event.day) || print_count == 0){
                
                if (Event.month == 1){
                    printf("%s %d, %d ", m.one, Event.day, Event.year);
                    strncat(message, m.one, 50);
                    strncat(message, space, 50);
                    sprintf(temp, "%d", Event.day);
                    strncat(message, temp, 50);
                    strncat(message, comma, 50);
                    strncat(message, space, 50);
                    sprintf(temp, "%d", Event.year);
                    strncat(message, temp, 50);
                    strncat(message, space, 50);
                    strncat(message, Event.dweek, 50);
                }

                if (Event.month == 2){
                    printf("%s %d, %d ", m.two, Event.day, Event.year);
                    strncat(message, m.two, 50);
                    strncat(message, space, 50);
                    sprintf(temp, "%d", Event.day);
                    strncat(message, temp, 50);
                    strncat(message, comma, 50);
                    strncat(message, space, 50);
                    sprintf(temp, "%d", Event.year);
                    strncat(message, temp, 50);
                    strncat(message, space, 50);
                    strncat(message, Event.dweek, 50);
                }

                if (Event.month == 3){
                    printf("%s %d, %d ", m.three, Event.day, Event.year);
                    strncat(message, m.three, 50);
                    strncat(message, space, 50);
                    sprintf(temp, "%d", Event.day);
                    strncat(message, temp, 50);
                    strncat(message, comma, 50);
                    strncat(message, space, 50);
                    sprintf(temp, "%d", Event.year);
                    strncat(message, temp, 50);
                    strncat(message, space, 50);
                    strncat(message, Event.dweek, 50);
                }

                if (Event.month == 4){
                    printf("%s %d, %d ", m.four, Event.day, Event.year);
                    strncat(message, m.four, 50);
                    strncat(message, space, 50);
                    sprintf(temp, "%d", Event.day);
                    strncat(message, temp, 50);
                    strncat(message, comma, 50);
                    strncat(message, space, 50);
                    sprintf(temp, "%d", Event.year);
                    strncat(message, temp, 50);
                    strncat(message, space, 50);
                    strncat(message, Event.dweek, 50);
                }

                if (Event.month == 5){
                    printf("%s %d, %d ", m.five, Event.day, Event.year);
                    strncat(message, m.five, 50);
                    strncat(message, space, 50);
                    sprintf(temp, "%d", Event.day);
                    strncat(message, temp, 50);
                    strncat(message, comma, 50);
                    strncat(message, space, 50);
                    sprintf(temp, "%d", Event.year);
                    strncat(message, temp, 50);
                    strncat(message, space, 50);
                    strncat(message, Event.dweek, 50);
                }

                if (Event.month == 6){
                    printf("%s %d, %d ", m.six, Event.day, Event.year);
                    strncat(message, m.six, 50);
                    strncat(message, space, 50);
                    sprintf(temp, "%d", Event.day);
                    strncat(message, temp, 50);
                    strncat(message, comma, 50);
                    strncat(message, space, 50);
                    sprintf(temp, "%d", Event.year);
                    strncat(message, temp, 50);
                    strncat(message, space, 50);
                    strncat(message, Event.dweek, 50);
                }

                if (Event.month == 7){
                    printf("%s %d, %d ", m.seven, Event.day, Event.year);
                    strncat(message, m.seven, 50);
                    strncat(message, space, 50);
                    sprintf(temp, "%d", Event.day);
                    strncat(message, temp, 50);
                    strncat(message, comma, 50);
                    strncat(message, space, 50);
                    sprintf(temp, "%d", Event.year);
                    strncat(message, temp, 50);
                    strncat(message, space, 50);
                    strncat(message, Event.dweek, 50);
                }

                if (Event.month == 8){
                    printf("%s %d, %d ", m.eight, Event.day, Event.year);
                    strncat(message, m.eight, 50);
                    strncat(message, space, 50);
                    sprintf(temp, "%d", Event.day);
                    strncat(message, temp, 50);
                    strncat(message, comma, 50);
                    strncat(message, space, 50);
                    sprintf(temp, "%d", Event.year);
                    strncat(message, temp, 50);
                    strncat(message, space, 50);
                    strncat(message, Event.dweek, 50);
                }

                if (Event.month == 9){
                    printf("%s %d, %d ", m.nine, Event.day, Event.year);
                    strncat(message, m.nine, 50);
                    strncat(message, space, 50);
                    sprintf(temp, "%d", Event.day);
                    strncat(message, temp, 50);
                    strncat(message, comma, 50);
                    strncat(message, space, 50);
                    sprintf(temp, "%d", Event.year);
                    strncat(message, temp, 50);
                    strncat(message, space, 50);
                    strncat(message, Event.dweek, 50);
                }

                if (Event.month == 10){
                    printf("%s %d, %d ", m.ten, Event.day, Event.year);
                    strncat(message, m.ten, 50);
                    strncat(message, space, 50);
                    sprintf(temp, "%d", Event.day);
                    strncat(message, temp, 50);
                    strncat(message, comma, 50);
                    strncat(message, space, 50);
                    sprintf(temp, "%d", Event.year);
                    strncat(message, temp, 50);
                    strncat(message, space, 50);
                    strncat(message, Event.dweek, 50);
                }

                if (Event.month == 11){
                    printf("%s %d, %d ", m.eleven, Event.day, Event.year);
                    strncat(message, m.eleven, 50);
                    strncat(message, space, 50);
                    sprintf(temp, "%d", Event.day);
                    strncat(message, temp, 50);
                    strncat(message, comma, 50);
                    strncat(message, space, 50);
                    sprintf(temp, "%d", Event.year);
                    strncat(message, temp, 50);
                    strncat(message, space, 50);
                    strncat(message, Event.dweek, 50);
                }

                if (Event.month == 12){
                    printf("%s %d, %d ", m.twelve, Event.day, Event.year);
                    strncat(message, m.twelve, 50);
                    strncat(message, space, 50);
                    sprintf(temp, "%d", Event.day);
                    strncat(message, temp, 50);
                    strncat(message, comma, 50);
                    strncat(message, space, 50);
                    sprintf(temp, "%d", Event.year);
                    strncat(message, temp, 50);
                    strncat(message, space, 50);
                    strncat(message, Event.dweek, 50);
                }
                
            }


            int convert_start_time = atoi(Event.start_time);
            int convert_end_time = atoi(Event.end_time);
            char AM[] = "AM";
            char PM[] = "PM";
            char blank[] = "";

            char minute_start[50];
            char minute_end[50];
            
            char delim[] = ":";
            char *ptr = strtok(Event.start_time, delim);

            while (ptr != NULL){
                
                ptr = strtok(NULL, delim);
                strcpy(minute_start, ptr);
                ptr = strtok(NULL, delim);
            }

            
            ptr = strtok(Event.end_time, delim);

            while (ptr != NULL){
                
                ptr = strtok(NULL, delim);
                strcpy(minute_end, ptr);
                ptr = strtok(NULL, delim);
            }

            if (convert_end_time >= 0){ 
                if (convert_end_time <= 11){

                    if (convert_start_time >= 0){                                 
                        if (convert_start_time <= 11){
                            
                            time_format();

                            if (temp_event_date.event_year == Event.year){
                                if (temp_event_date.event_month == Event.month){
                                    if (temp_event_date.event_day == Event.day){
                                        printf("%s:%s %s to %s:%s %s: %s{{%s}} | %s", formated_times.start_time, minute_start, AM, formated_times.end_time, minute_end, AM, Event.description, Event.location, Event.time);
                                        if (print_count+1 != all_events){
                                            printf("\n");
                                            if ((print[print_count+1][1] != Event.month && print[print_count+1][0] != Event.day)){
                                                printf("\n");
                                            }
                                        }
                                        print_count += 1;
                                    }
                                    else{
                                        printf("(%s)\n", Event.dweek);
                                        printlines(strlen(message));
                                        printf("%s:%s %s to %s:%s %s: %s{{%s}} | %s", formated_times.start_time, minute_start, AM, formated_times.end_time, minute_end, AM, Event.description, Event.location, Event.time);
                                        if (print_count+1 != all_events){
                                            printf("\n");
                                            if ((print[print_count+1][1] != Event.month && print[print_count+1][0] != Event.day)){
                                                printf("\n");
                                            }
                                        }
                                        print_count += 1;
                                    }
                                }
                                else{
                                    printf("(%s)\n", Event.dweek);
                                    printlines(strlen(message));
                                    printf("%s:%s %s to %s:%s %s: %s{{%s}} | %s", formated_times.start_time, minute_start, AM, formated_times.end_time, minute_end, AM, Event.description, Event.location, Event.time);
                                    if (print_count+1 != all_events){
                                        printf("\n");
                                        if ((print[print_count+1][1] != Event.month && print[print_count+1][0] != Event.day)){
                                            printf("\n");
                                        }
                                    }
                                    print_count += 1;
                                }
                            }

                            
                            else{
                                printf("(%s)\n", Event.dweek);
                                printlines(strlen(message));
                                printf("%s:%s %s to %s:%s %s: %s{{%s}} | %s", formated_times.start_time, minute_start, AM, formated_times.end_time, minute_end, AM, Event.description, Event.location, Event.time);
                                if (print_count+1 != all_events){
                                    printf("\n");
                                    if ((print[print_count+1][1] != Event.month && print[print_count+1][0] != Event.day)){
                                        printf("\n");
                                    }
                                }
                                print_count += 1;
                            }       
                                
                            
                        }       
                    }
                    
                    if (convert_start_time >= 12){                                 
                        if (convert_start_time <= 24){

                            time_format();

                            if (temp_event_date.event_year == Event.year){
                                if (temp_event_date.event_month == Event.month){
                                    if (temp_event_date.event_day == Event.day){
                                        printf("%s:%s %s to %s:%s %s: %s{{%s}} | %s", formated_times.start_time, minute_start, PM, formated_times.end_time, minute_end, AM, Event.description, Event.location, Event.time);
                                        if (print_count+1 != all_events){
                                            printf("\n");
                                            if ((print[print_count+1][1] != Event.month && print[print_count+1][0] != Event.day)){
                                                printf("\n");
                                            }
                                        }
                                        print_count += 1;
                                    }
                                    else{
                                        printf("(%s)\n", Event.dweek);
                                        printlines(strlen(message));
                                        printf("%s:%s %s to %s:%s %s: %s{{%s}} | %s", formated_times.start_time, minute_start, PM, formated_times.end_time, minute_end, AM, Event.description, Event.location, Event.time);
                                        if (print_count+1 != all_events){
                                            printf("\n");
                                            if ((print[print_count+1][1] != Event.month && print[print_count+1][0] != Event.day)){
                                                printf("\n");
                                            }
                                        }
                                        print_count += 1;
                                    }
                                }
                                else{
                                    printf("(%s)\n", Event.dweek);
                                    printlines(strlen(message));
                                    printf("%s:%s %s to %s:%s %s: %s{{%s}} | %s", formated_times.start_time, minute_start, PM, formated_times.end_time, minute_end, AM, Event.description, Event.location, Event.time);
                                    if (print_count+1 != all_events){
                                        printf("\n");
                                        if ((print[print_count+1][1] != Event.month && print[print_count+1][0] != Event.day)){
                                            printf("\n");
                                        }
                                    }
                                    print_count += 1;
                                }
                            }

                            else{
                                printf("(%s)\n", Event.dweek);
                                printlines(strlen(message));
                                printf("%s:%s %s to %s:%s %s: %s{{%s}} | %s", formated_times.start_time, minute_start, PM, formated_times.end_time, minute_end, AM, Event.description, Event.location, Event.time);
                                if (print_count+1 != all_events){
                                    printf("\n");
                                    if ((print[print_count+1][1] != Event.month && print[print_count+1][0] != Event.day)){
                                        printf("\n");
                                    }
                                }
                                print_count += 1;
                            }

                        }       
                    }
                }
            }


            if (convert_end_time >= 12){
                if (convert_end_time <= 24){

                    if (convert_start_time >= 0){                                 
                        if (convert_start_time <= 11){
                            
                            time_format();

                            if (temp_event_date.event_year == Event.year){
                                if (temp_event_date.event_month == Event.month){
                                    if (temp_event_date.event_day == Event.day){
                                        printf("%s:%s %s to %s:%s %s: %s{{%s}} | %s", formated_times.start_time, minute_start, AM, formated_times.end_time, minute_end, PM, Event.description, Event.location, Event.time);
                                        if (print_count+1 != all_events){
                                            printf("\n");
                                            if ((print[print_count+1][1] != Event.month && print[print_count+1][0] != Event.day)){
                                                printf("\n");
                                            }
                                        }
                                        print_count += 1;
                                    }
                                    else{
                                        printf("(%s)\n", Event.dweek);
                                        printlines(strlen(message));
                                        printf("%s:%s %s to %s:%s %s: %s{{%s}} | %s", formated_times.start_time, minute_start, AM, formated_times.end_time, minute_end, PM, Event.description, Event.location, Event.time);
                                        if (print_count+1 != all_events){
                                            printf("\n");
                                            if ((print[print_count+1][1] != Event.month && print[print_count+1][0] != Event.day)){
                                                printf("\n");
                                            }
                                        }
                                        print_count += 1;
                                    }
                                }
                                else{
                                    printf("(%s)\n", Event.dweek);
                                    printlines(strlen(message));
                                    printf("%s:%s %s to %s:%s %s: %s{{%s}} | %s", formated_times.start_time, minute_start, AM, formated_times.end_time, minute_end, PM, Event.description, Event.location, Event.time);
                                    if (print_count+1 != all_events){
                                        printf("\n");
                                        if ((print[print_count+1][1] != Event.month && print[print_count+1][0] != Event.day)){
                                            printf("\n");
                                        }
                                    }
                                    print_count += 1;
                                }
                            }
                            
                            else{
                                printf("(%s)\n", Event.dweek);
                                printlines(strlen(message));
                                printf("%s:%s %s to %s:%s %s: %s{{%s}} | %s", formated_times.start_time, minute_start, AM, formated_times.end_time, minute_end, PM, Event.description, Event.location, Event.time);
                                if (print_count+1 != all_events){
                                    printf("\n");
                                    if ((print[print_count+1][1] != Event.month && print[print_count+1][0] != Event.day)){
                                        printf("\n");
                                    }
                                }
                                print_count += 1;
                            }

                        }       
                    }
                    
                    if (convert_start_time >= 12){                                 
                        if (convert_start_time <= 24){

                            time_format();

                            if (temp_event_date.event_year == Event.year){
                                if (temp_event_date.event_month == Event.month){
                                    if (temp_event_date.event_day == Event.day){
                                        printf("%s:%s %s to %s:%s %s: %s{{%s}} | %s", formated_times.start_time, minute_start, PM, formated_times.end_time, minute_end, PM, Event.description, Event.location, Event.time);
                                        if (print_count+1 != all_events){
                                            printf("\n");
                                            if ((print[print_count+1][1] != Event.month && print[print_count+1][0] != Event.day)){
                                                printf("\n");
                                            }
                                        }
                                        print_count += 1;
                                    }
                                    else{
                                        printf("(%s)\n", Event.dweek);
                                        printlines(strlen(message));
                                        printf("%s:%s %s to %s:%s %s: %s{{%s}} | %s", formated_times.start_time, minute_start, PM, formated_times.end_time, minute_end, PM, Event.description, Event.location, Event.time);
                                        if (print_count+1 != all_events){
                                            printf("\n");
                                            if ((print[print_count+1][1] != Event.month && print[print_count+1][0] != Event.day)){
                                                printf("\n");
                                            }
                                        }
                                        print_count += 1;
                            
                                    }
                                }
                                else{
                                    printf("(%s)\n", Event.dweek);
                                    printlines(strlen(message));
                                    printf("%s:%s %s to %s:%s %s: %s{{%s}} | %s", formated_times.start_time, minute_start, PM, formated_times.end_time, minute_end, PM, Event.description, Event.location, Event.time);
                                    if (print_count+1 != all_events){
                                        printf("\n");
                                        if ((print[print_count+1][1] != Event.month && print[print_count+1][0] != Event.day)){
                                            printf("\n");
                                        }
                                    }
                                    print_count += 1;
                            
                                }
                            }
            
                            else{
                                printf("(%s)\n", Event.dweek);
                                printlines(strlen(message));
                                printf("%s:%s %s to %s:%s %s: %s{{%s}} | %s", formated_times.start_time, minute_start, PM, formated_times.end_time, minute_end, PM, Event.description, Event.location, Event.time);
                                if (print_count+1 != all_events){
                                    printf("\n");
                                    if ((print[print_count+1][1] != Event.month && print[print_count+1][0] != Event.day)){
                                        printf("\n");
                                    }
                                }
                                print_count += 1;
                            
                            }

                        }       
                    }
                }   
            }

        }
        
    }  
    
    
    
    strcpy(message, empty);
    strcpy(temp, empty);
    temp_event_date.event_year = print[print_count-1][2];
    temp_event_date.event_month = print[print_count-1][1];
    temp_event_date.event_day = print[print_count-1][0];
    

    return 0;
}

int get_event_info(int print[][3], char file[]){
    
    
    char line[100];
    char space[] = " ";
    char empty[] = "";
    
    char tempfile[50];
    strncpy(tempfile, file+7, 50);
    tempfile[32] = '\0';
    
    strcpy(Event.description, empty);
    strcpy(Event.timezone, empty);
    strcpy(Event.location, empty);
    Event.day = 0;
    Event.month = 0;
    Event.year = 0;
    strcpy(Event.dweek, empty);
    strcpy(Event.start_time, empty);
    strcpy(Event.end_time, empty);
        
    

    FILE* input_file = fopen(tempfile, "r");

    while (print_count != all_events){
        
        FILE* input_file = fopen(tempfile, "r");

        while (fgets(line, 100, input_file) != NULL){
                
            char delim[] = "> <";
            char *ptr = strtok(line, delim);
            
            
            
            

            if (strcmp(ptr,"description") == 0){
                
                ptr = strtok(NULL, delim);
                

                while (strcmp(ptr,"/description") != 0){
                    
                
                    
                    strncat(Event.description, ptr, strlen(ptr));
                    strncat(Event.description, space, strlen(ptr));
                    ptr = strtok(NULL, delim);

                }
                
                ptr = strtok(NULL, delim);
                
            }
            
            
            if (strcmp(ptr,"timezone") == 0){
                        
                ptr = strtok(NULL, delim);

                while (strcmp(ptr,"/timezone") != 0){
                    
                    strncat(Event.time, ptr, 50);
                    ptr = strtok(NULL, delim);

                }
                
                ptr = strtok(NULL, delim);
                
            }
            
            if (strcmp(ptr,"location") == 0){
                    
                ptr = strtok(NULL, delim);

                while (strcmp(ptr,"/location") != 0){
                    
                    strncat(Event.location, ptr, 50);
                    ptr = strtok(NULL, delim);

                    if (strcmp(ptr,"/location") != 0){
                        strncat(Event.location, space, 50);
                    }
                    
                    

                }
                
                ptr = strtok(NULL, delim);
                
            }

            if (strcmp(ptr,"day") == 0){
                
                ptr = strtok(NULL, delim);

                while (strcmp(ptr,"/day") != 0){
                    
                    int get = atoi(ptr);
                    check_dates.day = atoi(ptr);
                    Event.day = get;
                    ptr = strtok(NULL, delim);
                }
                
                ptr = strtok(NULL, delim);
                
            }

            if (strcmp(ptr,"month") == 0){
                
                ptr = strtok(NULL, delim);

                while (strcmp(ptr,"/month") != 0){
                    
                    int get = atoi(ptr);
                    Event.month = get;
                    check_dates.month = atoi(ptr);
                    ptr = strtok(NULL, delim);
                }
                
                ptr = strtok(NULL, delim);
                
            }

            if (strcmp(ptr,"year") == 0){
                
                ptr = strtok(NULL, delim);

                while (strcmp(ptr,"/year") != 0){
                    
                    int get = atoi(ptr);
                    Event.year = get;
                    check_dates.year = atoi(ptr);
                    ptr = strtok(NULL, delim);
                }
                
                ptr = strtok(NULL, delim);
                
            }

            if (strcmp(ptr,"dweek") == 0){
                
                ptr = strtok(NULL, delim);

                while (strcmp(ptr,"/dweek") != 0){
                    
                    strncat(Event.dweek, ptr, 50);
                    ptr = strtok(NULL, delim);

                }
                
                ptr = strtok(NULL, delim);
                
            }

            if (strcmp(ptr,"start") == 0){
                
                ptr = strtok(NULL, delim);

                while (strcmp(ptr,"/start") != 0){
                    
                    strncat(Event.start_time, ptr, 50);
                    ptr = strtok(NULL, delim);

                }
                
                ptr = strtok(NULL, delim);
                
            }

            if (strcmp(ptr,"end") == 0){
                
                ptr = strtok(NULL, delim);

                while (strcmp(ptr,"/end") != 0){
                    
                    strncat(Event.end_time, ptr, 50);
                    ptr = strtok(NULL, delim);

                }
                
                ptr = strtok(NULL, delim);
                
            }

            if (strcmp(ptr,"/event") == 0){
                    
                ptr = strtok(NULL, delim);
                printanswer(print);

                strcpy(Event.description, empty);
                strcpy(Event.time, empty);
                strcpy(Event.location, empty);
                Event.day = 0;
                Event.month = 0;
                Event.year = 0;
                strcpy(Event.dweek, empty);
                strcpy(Event.start_time, empty);
                strcpy(Event.end_time, empty);
                strcpy(formated_times.start_time, empty);
                strcpy(formated_times.end_time, empty);
                
                ptr = strtok(NULL, delim);
                
            }
            

           
            
            
            
            
            
            ptr = strtok(NULL, delim);
        }
    

        

        fclose(input_file);
    }
    
    
            

}

int compare (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

int get_all(char file[]){

    int count = 0;
    int count2 = 0;
    int count3 = 0;
    char line[100];
    char tempfile[50];
    strncpy(tempfile, file+7, 50);
    tempfile[32] = '\0';
    
    FILE* input_file = fopen(tempfile, "r");

    while (fgets(line, 100, input_file) != NULL){
             
        char delim[] = "> <";
        char *ptr = strtok(line, delim);
        
        while(ptr != NULL){
            
            if (strcmp(ptr,"month") == 0){
                
                ptr = strtok(NULL, delim);
                

                while (strcmp(ptr,"/month") != 0){
                    
                    
                    all_months[count] = atoi(ptr);
                    ptr = strtok(NULL, delim);
                    count += 1;

                }
                
                ptr = strtok(NULL, delim);
                
            }

            if (strcmp(ptr,"day") == 0){
                
                ptr = strtok(NULL, delim);

                while (strcmp(ptr,"/day") != 0){
                    
                    
                    all_days[count2] = atoi(ptr);
                    ptr = strtok(NULL, delim);
                    count2 += 1;

                }
                
                ptr = strtok(NULL, delim);
                
            }

            if (strcmp(ptr,"year") == 0){
                
                ptr = strtok(NULL, delim);

                while (strcmp(ptr,"/year") != 0){
                    
                    
                    all_years[count3] = atoi(ptr);
                    ptr = strtok(NULL, delim);
                    count3 += 1;

                }
                
                ptr = strtok(NULL, delim);
                
            }

            if (strcmp(ptr,"event") == 0){
                
                ptr = strtok(NULL, delim);

                all_events += 1;
                
                ptr = strtok(NULL, delim);
                
            }

            ptr = strtok(NULL, delim);
        }
    }

    fclose(input_file);


    int valid_months_temp[50];
    int valid_days_temp[50];
    int valid_years_temp[50];

    int months = 0;
    int days = 0;
    int years = 0;

    for(int i = 0; i < 20; i++){
        if(all_months[i] != 0){
            months += 1;
        }
        if(all_days[i] != 0){
            days += 1;
        }
        if(all_years[i] != 0){
            years += 1;
        }
    }

    
    int start_date[] = {Date_input_start.day, Date_input_start.month , Date_input_start.year};
    int end_date[] = {Date_input_end.day, Date_input_end.month , Date_input_end.year};
    int k = 0;
    for (int i = 0; i < all_events; i++){
        
        int file_date[] = {all_days[i], all_months[i], all_years[i]};
        int a = compare_dates(start_date, file_date);
        int b = compare_dates(file_date, end_date);


        if (a == b){
            valid_days_temp[k] = all_days[i];
            valid_months_temp[k] = all_months[i];
            valid_years_temp[k] = all_years[i];
            k += 1;
        }
        
    


    }
    
    
    months = 0;
    days = 0;
    years = 0;

    for(int i = 0; i < all_events; i++){
        
        if (k != 0 && (valid_months_temp[i] > 1000 || valid_months_temp[i] > 0)){
            if(valid_months_temp[i] != 0){
                months += 1;
            }
            if(valid_days_temp[i] != 0){
                days += 1;
            }
            if(valid_years_temp[i] != 0){
                years += 1;
            }
        }
    }   

    int valid[months][3];

    for (int i = 0; i < months; i++) {
        
        valid[i][0] = valid_days_temp[i];
        valid[i][1] = valid_months_temp[i];
        valid[i][2] = valid_years_temp[i];

        
    }
    

    for(int i = 0; i < months; i++){
        for(int j = i+1; j < months; j++){
            
            if(valid[j][1] < valid[i][1]){
                int tmp = valid[i][1];
                valid[i][1] = valid[j][1];
                valid[j][1] = tmp;
                
                int tmp2 = valid[i][0];
                valid[i][0] = valid[j][0];
                valid[j][0] = tmp2;
            
            }

        }
    }
    
    
    all_events = months;
    get_event_info(valid, file);

    return 0;
}

int main(int argc, char *argv[]){

    
    get_input_dates(argv[1] , argv[2]);
    get_all(argv[3]);


    exit(0);

}
