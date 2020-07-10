#include <iostream>
#include <string>
#include <getopt.h>
#include "punchtime/punchtime.h"
#include "punchtime/time.h"

#define VERSION "develop-0.1.4"

using namespace std;

// Global variables
string user_input;
string timein_str;
string breaktime_str;
string overtime_str;
string hour_str;
string minute_str;
int hour_int;
int minute_int;
int colon_pos;
bool isTimeIn;
bool isBreaktime;
bool isOvertime;

// Function declaration
void parse_input(string);
void convert_input(string, string);
bool isValidTimeFormat(string);


int main(int argc, char **argv) {

    int opt;
    int index;
    Punchtime todayPunchtime;

    // Optional arguments
    while ((opt = getopt(argc, argv, ":b:o:-v")) != -1) {
        switch(opt) {
            case 'b':
                breaktime_str = optarg;
                if (isValidTimeFormat(breaktime_str))
                    isBreaktime = true;
                break;
            case 'o':
                overtime_str = optarg;
                isOvertime = true;
                break;
            case 'v':
                cout << VERSION << endl;
                break;
            case ':':
                cout << opt << " requires a value" << endl;
                break;
            case '?':
                printf("unknown option\n");
                return 1;
        }
    }

    // Non-optional argument
    for (index = optind; index < argc; index++) {
        
        timein_str = argv[index];
        if (isValidTimeFormat(timein_str))
            isTimeIn = true;
        break;  // exit for loop, we only need to process 1 positional argument

    }
   
    if (isTimeIn) {

        parse_input(timein_str);
        try {
            convert_input(hour_str, minute_str);
            Time timein(hour_int, minute_int);
            todayPunchtime.setTimeout(timein.hour, timein.minute);
            
            cout << "Time-out: ";
            todayPunchtime.timeout();
        }
        catch (std::invalid_argument& e) {
            cout << "Not a valid time format --> " << hour_str << ":" << minute_str << endl;
        }

    }

    if (isBreaktime) {

        parse_input(breaktime_str);
        convert_input(hour_str, minute_str);
        todayPunchtime.setBreaktime(hour_int, minute_int, 1, 30);

        cout << "Break until: ";
        todayPunchtime.breaktime();
    }
 
    if (isOvertime) {
        
        todayPunchtime.setOvertime(stoi(overtime_str));
        cout << "Overtime until: ";
        todayPunchtime.timeout();
    }

    return 0;
}

// Function definition
void parse_input(string str) {

    colon_pos = str.find(":"); // -1 value means not found
    hour_str = str.substr(0, colon_pos);
    minute_str = str.substr(colon_pos + 1, str.length());

}

void convert_input(string hour, string minute) {

    hour_int = stoi(hour);
    minute_int = stoi(minute);

}

bool isValidTimeFormat(string input) {

    if (input.find(":") != -1)
        return true;
    else
        cout << "Not a valid time format --> " << input << endl;
        return false;

}