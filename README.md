**Punchtime**
-----
_Punchtime_ is a simple console application that can compute for your time-out, breaks and overtime.

Usage
---
```
$ punchtime 7:47    # time-in
Time-out: 4:47

$ punchtime 7:47 -b 11:00   # time-in with breaktime (-b), break is 1 hour 30 minutes
Time-out: 4:47
Break until: 12:30

$ punchtime 7:47 -b 11:00 -o 1  # time-in with breaktime and 1 hour overtime (-o)
Time-out: 4:47
Break until: 12:30
Overtime until: 5:47
```

Build from source
---
```
$ make              # build using make
$ ./punchtime -v    # run the program by displaying the version number
```
