#include <stdio.h>
#include "punchtime/punchtime.h"

using namespace std;

void Punchtime::setTimeout(int h, int m) {

    out_hour = workingHours + h;
    if (out_hour > 12)
        out_hour -= 12;
    out_minute = m;

}

void Punchtime::timeout() {

    printf("%d:%d\n", out_hour, out_minute);

}

void Punchtime::setBreaktime(int h, int m, int duration_hour, int duration_minute) {

    break_hour = h + duration_hour;
    break_minute = m + duration_minute;

    if (break_hour > 12)
        break_hour -= 12;

    if (break_minute >= 60) {
        break_hour += 1;
        break_minute -= 60;
    }

}

void Punchtime::breaktime() {

    printf("%d:%d\n", break_hour, break_minute);

}

void Punchtime::setOvertime(int h) {

    out_hour = out_hour + h;

}