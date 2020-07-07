# Compilers
linux-compiler = g++
windows-compiler = x86_64-w64-mingw32-g++

# Directories
src-dir = src/
punchtime-dir = include/punchtime/
build-dir = build/

# Flags
i-flag = -I include

objects = time.o punchtime.o main.o

# Rules
punchtime: $(objects)
	$(linux-compiler) -o punchtime $(objects)

main.o: $(src-dir)main.cpp $(punchtime-dir)punchtime.h
	$(linux-compiler) $(i-flag) -c $(src-dir)main.cpp

punchtime.o: $(src-dir)punchtime.cpp $(punchtime-dir)punchtime.h
	$(linux-compiler) $(i-flag) -c $(src-dir)punchtime.cpp

time.o: $(src-dir)time.cpp $(punchtime-dir)time.h
	$(linux-compiler) $(i-flag) -c $(src-dir)time.cpp

clean:
	rm -f *.o punchtime
