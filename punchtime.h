#ifndef PUNCHTIME_H
#define PUNCHTIME_H

class Punchtime {

    public:
        int hour = 0;
        int minute = 0;
        int workingHours = 9;
        void setTimeout(int, int);
        void timeout();
        void setBreaktime(int, int, int, int);
        void breaktime();
        void setOvertime(int);
};

#endif // PUNCHTIME_H
