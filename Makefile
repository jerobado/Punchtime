# [] TODO: make this readeable as English
# [] TODO: use x86_64-w64-mingw32-g++ command to compile for Windows 64 bit

CC = g++
CFLAGS = -I.
DEPS = punchtime.h
OBJ = punchtime.o main.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

main: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

clean:
	rm -f *.o main
