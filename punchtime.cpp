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


TODO: 
1. get user input
2. parse user input, get minutes and seconds
3. add defualt 9 working hours
4. print result

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




int main(int argc, char **argv)
{
    int index;
    int positional = 1;
    int opt;
    int colon_pos;
    int hour_int;
    int min_int;
    int out_hour_int;
    int out_min_int;
    string input;
    string hour_str;
    string min_str;
   
    // Parse optional arguments
    while ((opt = getopt(argc, argv, ":b:o:-v")) != -1)
    {
        switch (opt)
        {           
            case 'b':
                cout << "optarg = " << optarg << endl;
                cout << "[] TODO: compute breaktime" << endl;
                break;
            
            case 'o':
                cout << "optarg = " << optarg << endl;
                cout << "[] TODO: compute overtime" << endl;
                break;

            case 'v':
                cout << "0.1.1" << endl;
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
        colon_pos = input.find(":");                            // find colon
        hour_str = input.substr(0, colon_pos);                  // get hour
        min_str = input.substr(colon_pos + 1, input.length());  // get minutes    

        // Convert hour and minutes to digits
        hour_int = stoi(hour_str);
        min_int = stoi(min_str);    

        // Add default working hours (9)
        out_hour_int = hour_int + 9;
        out_min_int = min_int;

        // Display result
        cout << "Time-in: " << hour_int << ":" << min_int << endl;
        cout << "Time-out: " << out_hour_int << ":" << out_min_int << endl;

        // Exit for loop, we only need to process 1 positional non-argument
        break;

    }
    
    return 0;
}
