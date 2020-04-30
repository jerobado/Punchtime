punchtime: punchtime.o
	g++ punchtime.o -o punchtime

punchtime.o: punchtime.cpp
	g++ -c punchtime.cpp

clean:
	rm *.o punchtime
