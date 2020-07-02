#ifndef PUNCHTIME_H
#define PUNCHTIME_H

class Punchtime {

    public:
        int in_hour = 0;
        int in_minute = 0;

        int out_hour = 0;
        int out_minute = 0;

        int break_hour = 0;
        int break_minute = 0;

        // [] TODO: create a Time class
        // Usage:
        // Time inTime(0, 0);
        // Time outTime(0, 0);
        // Time breakTime(0, 0);

        int workingHours = 9;
        void setTimeout(int, int);
        void timeout();
        void setBreaktime(int, int, int, int);
        void breaktime();
        void setOvertime(int);
};

#endif // PUNCHTIME_H
