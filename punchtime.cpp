/*
Punchtime is a simple console application that can compute for your time out, breaks and overtime.

Usage:
$ punchtime 7:47    # time-in
Time-out: 16:47

$ punchtime 7:47 -b 11:00   # time-in with breaktime (-b), break is 1 hour 30 minutes
Break until: 12:30
Time-out: 16:47

$ punctime 7:47 -b 11:00 -o 1   # time-in with breaktime and 1 hour overtime (-o)
Break until: 12:30
Time-out: 17:47

*/

#include <iostream>
#include <ctime>
#include <ratio>
#include <chrono>
#include <string>
#include <getopt.h>
#include <stdlib.h>
#include <cstring>

using namespace std;


// Declaring global variables
int colon_pos;
int hour_int;
int min_int;
int overtime_int = 0;
string input;
string hour_str;
string min_str;
bool isOvertime;


void display_current_time(void) {

    // current date/time on current system
    time_t now = time(0);

    // convert now to string form
    char* dt = ctime(&now);

    tm *local_time = localtime(&now);

    cout << "Now: " << dt;
    cout << "Hour: " << local_time->tm_hour + 9 << endl; // result is 30, fix this
    cout << "Minutes: " << local_time->tm_min << endl;
}


void display_current_time2(void) {

    using std::chrono::system_clock;

    system_clock::time_point today = system_clock::now();

    std::time_t tt;

    tt = system_clock::to_time_t(today);
    // print time today
    std::cout << "today is " << ctime(&tt);
    
    display_current_time();    

}

// Function declaration
void parse_input(string input);
void convert_input(void);


int main(int argc, char **argv)
{
    int index;
    int positional = 1;
    int opt;
    int out_hour_int;
    int out_min_int;
   
    // Parse optional arguments
    while ((opt = getopt(argc, argv, ":b:o:-v")) != -1)
    {
        switch (opt)
        {           
            case 'b':
                // Get user input
                input = optarg;
                
                // Parse input, get hours and minutes
                parse_input(input);
               
                // Convert hour and minutes to digits
                convert_input();

                // Add default working hours (1 hour 30 minutes)
                out_hour_int = hour_int + 1;
                out_min_int = min_int + 30;

                // Display result
                cout << "Break until: " << out_hour_int << ":" << out_min_int << endl;
                break;
            
            case 'o':
                // Get user input
                input = optarg;
                
                // Convert input to int
                overtime_int = stoi(input);
                break;

            case 'v':
                cout << "0.1.3" << endl;
                break;
            
            case ':':
                cout << "'" << opt << "," <<  " requires a value" << endl;
                break;

            case '?':
                // exit if invalid command
                printf("unknown option\n");
                return 1;
        }
    
    }

    // Parse non-option argument
    for (index = optind; index < argc; index++)
    {
        // Get user input
        input = argv[index];   
            
        // Parse input, get hours and minutes
        parse_input(input);

        // Convert hour and minutes to digits
        convert_input();

        // Validate input
        if ((hour_int > 23) || (min_int > 59))
        {
            cout << "Not a valid time-format." << endl;
            break;
        }

        // Add default working hours (9) and overtime
        out_hour_int = hour_int + 9 + overtime_int;
        out_min_int = min_int;

        // Display result
        cout << "Time-out: " << out_hour_int << ":" << out_min_int << endl;

        // Exit for loop, we only need to process 1 positional non-argument
        break;

    }
    
    return 0;
}

// Function definition
void parse_input(string input)
{
    /* Parse input getting hours and minutes */

    colon_pos = input.find(":");                            // find colon
    hour_str = input.substr(0, colon_pos);                  // get hour
    min_str = input.substr(colon_pos + 1, input.length());  // get minutes    
}

void convert_input()
{
    /* Convert parsed hour and minutes from string to int */
    
    hour_int = stoi(hour_str);
    min_int = stoi(min_str);
}


