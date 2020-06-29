#include <stdio.h>
#include "punchtime.h"

using namespace std;

void Punchtime::setTimeout(int h, int m) {

    hour = workingHours + h;
    if (hour > 12)
        hour -= 12;
    minute = m;

}

void Punchtime::timeout() {

    printf("%d:%d\n", hour, minute);

}

void Punchtime::setBreaktime(int h, int m, int duration_hour, int duration_minute) {

    hour = h + duration_hour;
    minute = m + duration_minute;
    if (minute >= 60) {
        hour += 1;
        minute -= 60;
    }

}

void Punchtime::breaktime() {

    printf("%d:%d\n", hour, minute);

}

void Punchtime::setOvertime(int h) {

    hour = hour + h;
    // minute = minute + m;

}