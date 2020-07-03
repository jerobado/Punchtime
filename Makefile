# Compilers
linux-compiler = g++
windows-compiler = x86_64-w64-mingw32-g++

objects = time.o punchtime.o main.o

# Rules
punchtime: $(objects)
	$(linux-compiler) -o punchtime $(objects)

main.o: main.cpp punchtime.h
	$(linux-compiler) -c main.cpp

punchtime.o: punchtime.cpp punchtime.h
	$(linux-compiler) -c punchtime.cpp 

time.o: time.cpp time.h
	$(linux-compiler) -c time.cpp

clean:
	rm -f *.o punchtime
