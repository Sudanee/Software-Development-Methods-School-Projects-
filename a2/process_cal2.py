#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Tue Feb 01 08:35:33 2022
@author: rivera

This is a text processor that allows to translate XML-based events to YAML-based events.
CAREFUL: You ARE NOT allowed using (i.e., import) modules/libraries/packages to parse XML or YAML
(e.g., yaml or xml modules). You will need to rely on Python collections to achieve the reading of XML files and the
generation of YAML files.
"""
import sys
import datetime
import re
    
def format_file2(file):
    # define the collections to be used
    broadcasters_list = []
    filtered_lines = []
    f = 0
    # read the file line by line
    with open(file) as file:
        for line in file:
            # use regular expressions to collect relevant data
            line = re.findall(r'<(.*?)>(.*?)</\1>', line)
    #         # only include tags with information
            if len(line) > 0:
                filtered_lines.append(line[0])
            else:
                f += 1
    broadcaster_dic = {}
    d = (f/2) - 1
    g = len(filtered_lines) / d
    k = 0
    
    
    # create the dictionaries
    
    for i in range(len(filtered_lines)):
        tup = filtered_lines[i]
        broadcaster_dic[tup[0]] = tup[1]
        k += 1
        # separate the information for each broadcaster
        if k == g:
            broadcasters_list.append(broadcaster_dic)
            broadcaster_dic = {}
            k = 0
    # print the list of dictionaries
    return broadcasters_list

def get_all(file):
    # counts all the times in given list of tuples and returns the total number
    count = 0
    for i in range(0,len(file)):
        for elem in file[i]:
            count += 1

    return count

def format_dates(date):
    # converts the given date in the form of a string to a datetime module and returns it
    year = ""
    month = ""
    day = ""
    count = 0

    for char in date:
        
        if (count == 0 and char != "/"):
            year += char
        
        if (count == 1 and char != "/"):
            month += char
        
        if (count == 2 and char != "/"):
            day += char
            
        if (char == "/"):
            count += 1

    formated_date = datetime.datetime(int(year), int(month), int(day))
    return formated_date

def get_all_inputs(start_time, end_time, event, circuit, broadcaster):
    # gets all the users inputs and takes away the excess (ie. --start=) and places the result into the given lists then returns the lists

    input_start_time = sys.argv[1]
    input_end_time = sys.argv[2]
    input_event = sys.argv[3]
    input_circuits = sys.argv[4]
    input_broadcaster = sys.argv[5]
    input = ""
    
    i = 0
    for char in input_start_time:
        if (i >= 8):
            input += char
        i += 1

    start = format_dates(input)
    start_time.append(start)
    input = ""
    i = 0
    
    for char in input_end_time:
        if (i >= 6):
            input += char
        i += 1

    end = format_dates(input)
    end_time.append(end)
    input = ""
    i = 0
    
    for char in input_event:
        
        if (i >= 9):
            input += char
        i += 1

    event.append(input)
    input = ""
    i = 0
    
    for char in input_circuits:
        if (i >= 11):
            input += char
        i += 1

    circuit.append(input)
    input = ""
    i = 0
    
    for char in input_broadcaster:
        if (i >= 15):
            input += char
        i += 1

    
    broadcaster.append(input)

    return start_time, end_time, event, circuit, broadcaster
    
def get_circuits_and_broadcasters(all_broadcasters, all_circuits, input_file, broadcaster, circuit, event):
    # takes file names and empty lists, saves all the information from a file and saves it to one of the given lists then returns those lists
    broadcasters_file = format_file2(broadcaster[0])
    circuit_file = format_file2(circuit[0])
    file = format_file2(event[0])
    
    for i in range(0, len(broadcasters_file)):
        all_broadcasters.append(broadcasters_file[i])
    
    for i in range(0, len(circuit_file)):
        all_circuits.append(circuit_file[i])

    for i in range(0, len(file)):
        input_file.append(file[i])

    return all_broadcasters, all_circuits, input_file

def compare_dates(start_time, end_time, input_file):
    # takes the users start and end time as well as a input file that contains another date. Then the function compares the dates from the file to the other two dates.
    # If the dates from the file is between the other dates then it is added to a list, once all the dates have been compared returns the list of dates
    date_list = []
    count = 0
    for elem in input_file:
        date = datetime.datetime(int(elem["year"]), int(elem["month"]), int(elem["day"]))
        if (start_time[0] <= date <= end_time[0]):
            if (count == 0 or date_list[count - 1] != date):
                date_list.append(date)
                count += 1
    return date_list

def compare_times(valid_dates, input_file):
    # Takes a list of dates and the input file. Then the function searches through the file to find the times that matches the list of dates then forms them into a tuple (start_time, end_time).
    # Then takes the tuple and adds them to a list, then returns said list.
    
    time_list = []
    time_tup = []
    for i in range (0, len(valid_dates)):
        for elem in input_file:
            current_month_list  = valid_dates[i].strftime("%m")
            current_day_list = valid_dates[i].strftime("%d")
            current_year_list = valid_dates[i].strftime("%Y")

            current_month = elem["month"]
            current_day = elem["day"]
            current_year = elem["year"]

            start = elem["start"]
            end = elem["end"]
            time_s = datetime.time(hour=int(start[0:2]), minute=int(start[3:5]))
            time_e = datetime.time(hour=int(end[0:2]), minute=int(end[3:5]))

            if (current_month == current_month_list and current_day == current_day_list and current_year == current_year_list):
                time = time_s, time_e

                time_tup.append(time)
        time_tup.sort()
        time_list.append(time_tup)
        time = 0, 0
        time_tup = []
    
    
    


    return time_list

def get_circuit(id, all_circuits):
    # Takes an id of the circuit (string) and a list then searches through the list to find the matching id and adds it to a list. Then returns that list
    formated = []

    for elem in all_circuits:
        if (id == elem["id"]):
            formated.append(elem)
    
    return formated

def get_brodcaster(id, all_broadcasters):
    # Takes a id (string) and a list then searches through the list to find the matching id and adds it to a list. Then returns that list
    formated = []
    ids = []
    temp = ""
    count = 0
    if (len(id) != 4):
        for char in id:
            if (char != ","):
                temp += char
                count += 1
            else:
                ids.append(temp)
                temp = ""
        ids.append(temp)
    else:
        ids.append(id)
        for elem in all_broadcasters:
            if (ids[0] == elem["id"]):
                formated.append(elem)
        return formated
                
    
    i = 0

    for elem in all_broadcasters:
        if (len(ids) == len(formated)):
            return formated
        if (ids[i] == elem["id"]):
            formated.append(elem)
            i += 1
    
    return formated

def print_answer(start_time, end_time, broadcaster, all_broadcasters, all_circuits, input_file):
    # Takes list of start times, list of end times, list of info from broadcaster file, list of info from circuit file, and a event file name.
    # Takes all the info and writes to output.yaml file.
    final_answer = []
    final_answer.append("events:\n")
    
    dates = compare_dates(start_time, end_time, input_file)
    dates.sort()
    times = compare_times(dates, input_file)
    all_events = get_all(times)
    
    s = 0

    if (all_events == 0):
        f = open("output.yaml", "w")    
        f.write("events:")
        f.close()
        return 0
    
    
    for i in range (0, len(dates)):
        k = 0
    
        final_answer.append("  - ")
        final_answer.append(dates[i].strftime("%d-%m-%Y"))
        final_answer.append(":\n")

        count = 0
        print_count = 0
        for l in range (0, len(times[i])):
            if (k != len(times[i])):
                for v in range(0, len(input_file)):
                    
                    if (s == len(times[i])):
                        break
                    if (print_count == all_events):
                        return 0
                    

                    elem = input_file[v]

                    current_month_list  = dates[i].strftime("%m")
                    current_day_list = dates[i].strftime("%d")
                    current_year_list = dates[i].strftime("%Y")

                    current_month = elem["month"]
                    current_day = elem["day"]
                    current_year = elem["year"]
                    
                    ids = elem["id"]
                    description = elem["description"]
                    location = get_circuit(elem["location"], all_circuits)
                    time = times[i]
                    broadcasters = get_brodcaster(elem["broadcaster"], all_broadcasters)

                    if (len(location) == 1):
                        count = 0

                    current_start_min_list = time[s][0].strftime("%I:%M")
                    current_end_time_list = time[s][1].strftime("%I:%M")

                    current_start_time_hr = elem["start"][0:2]
                    current_start_time_min = elem["start"][3:5]
                    convert_start_time = datetime.time(hour=int(current_start_time_hr), minute=int(current_start_time_min))
                    current_start_time = convert_start_time.strftime("%I:%M")
                    
                    current_end_time_hr = elem["end"][0:2]
                    current_end_time_min = elem["end"][3:5]
                    convert_end_time = datetime.time(hour=int(current_end_time_hr), minute=int(current_end_time_min))
                    current_end_time = convert_end_time.strftime("%I:%M")

                    

                    if (current_month == current_month_list and current_day == current_day_list and current_year == current_year_list and current_start_min_list == current_start_time and current_end_time_list == current_end_time ):
                       
                        final_answer.append("    - id: ")
                        final_answer.append(ids)
                        final_answer.append("\n")
                        
                        final_answer.append("      description: ")
                        final_answer.append(description)
                        final_answer.append("\n")
                        
                        final_answer.append("      circuit: ")
                        final_answer.append(location[count]["name"])
                        final_answer.append(" (")
                        final_answer.append(location[count]["direction"])
                        final_answer.append(")")
                        final_answer.append("\n")
                        
                        final_answer.append("      location: ")
                        final_answer.append(location[count]["location"])
                        final_answer.append("\n")
                        
                        final_answer.append("      when: ")
                        final_answer.append(time[s][0].strftime("%I:%M %p"))
                        final_answer.append(" - ")
                        final_answer.append(time[s][1].strftime("%I:%M %p"))
                        final_answer.append(dates[i].strftime(" %A, %B %d, %Y"))
                        final_answer.append(" (")
                        final_answer.append(location[count]["timezone"])
                        final_answer.append(")")
                        final_answer.append("\n")
                        final_answer.append("      broadcasters:\n")

                        for k in range (0, len(broadcasters)):
                            
                            final_answer.append("        - ")
                            final_answer.append(broadcasters[k]["name"])
                            if (k != len(broadcasters)-1 or print_count != all_events-1):
                                final_answer.append("\n")
    
                        s += 1
                        print_count += 1
 
                count += 1
                if (s == len(times[i])):
                    s = 0   
                    k = len(times[i])
    
    f = open("output.yaml", "w")
    for i in range(0, len(final_answer)):
        f.write(final_answer[i])

    f.close()

            
def main():
    """The main entry point for the program.
    """
    # USER INPUTS 
    start_time = []
    end_time = []
    event = []
    circuit = []
    broadcaster = []

    # INPUT FILES
    all_broadcasters = []
    all_circuits = []
    input_file = []

    get_all_inputs(start_time, end_time, event, circuit, broadcaster)
    get_circuits_and_broadcasters(all_broadcasters, all_circuits, input_file, broadcaster, circuit, event)
    print_answer(start_time, end_time, broadcaster, all_broadcasters, all_circuits, input_file)
    

if __name__ == '__main__':
    main()