#include <iostream>
#include <string>
#include <getopt.h>
#include "punchtime.h"

#define VERSION "develop-0.1.4"

using namespace std;

// Global variables
string user_input;
string timein_str;
string breaktime_str;
string overtime_str;
string hour_str;
string minute_str;
int colon_pos;
bool isTimeIn;
bool isBreaktime;
bool isOvertime;

int main(int argc, char **argv) {

    int opt;
    int index;
    Punchtime todayPunchtime;

    // Optional arguments
    while ((opt = getopt(argc, argv, ":b:o:-v")) != -1) {
        switch(opt) {
            case 'b':
                breaktime_str = optarg;
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
        isTimeIn = true;
        break;  // exit for loop, we only need to process 1 positional argument
    }
   
    if (isTimeIn) {
        colon_pos = timein_str.find(":"); // -1 value means not found
        hour_str = timein_str.substr(0, colon_pos);
        minute_str = timein_str.substr(colon_pos + 1, timein_str.length());

        todayPunchtime.setTimeout(stoi(hour_str), stoi(minute_str));
        
        cout << "Time-out: ";
        todayPunchtime.timeout();
    }

    if (isBreaktime) {
        colon_pos = breaktime_str.find(":"); // -1 value means not found
        hour_str = breaktime_str.substr(0, colon_pos);
        minute_str = breaktime_str.substr(colon_pos + 1, breaktime_str.length());

        todayPunchtime.setBreaktime(stoi(hour_str), stoi(minute_str), 1, 30);

        cout << "Break until: ";
        todayPunchtime.breaktime();
    }

    // [] TODO: properly compute timeout when isOvertime 
    if (isOvertime) {
        
        todayPunchtime.setOvertime(stoi(overtime_str));
        // todayPunchtime.timeout();
    }

    return 0;
}
