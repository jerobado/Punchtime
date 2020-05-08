# [] TODO: use x86_64-w64-mingw32-g++ command to compile for Windows 64 bit

punchtime: punchtime.o
	g++ punchtime.o -o punchtime

punchtime.o: punchtime.cpp
	g++ -c punchtime.cpp

clean:
	rm -f *.o *.exe punchtime
