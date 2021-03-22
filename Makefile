# Compilers
ifeq ($(OS),Windows_NT)
	CXX=x86_64-w64-mingw32-g++
	target=punchtime.exe`
else
	CXX=g++
	target=punchtime
endif

ifdef CXX
$(info Compiler tools and variables)
$(info CXX: $(CXX) - working)
$(info target: $(target))
$(info Compiling...)
endif


# Directories
src-dir = src/
punchtime-dir = include/punchtime/
build-dir = build/

# Flags
i-flag = -I include

source = time.cpp punchtime.cpp main.cpp
objects = time.o punchtime.o main.o

# Rules
$(target): $(objects)
	@$(CXX) -o $(target) $(objects)
	@printf "\nCompilation success!"
	@printf "\n  %-34s -> %s\n" "Executable file" $@

main.o: $(src-dir)main.cpp $(punchtime-dir)punchtime.h
	@$(CXX) $(i-flag) -c $(src-dir)main.cpp
	@printf "%5s %-30s -> %s\n" $(CXX) $< $@

punchtime.o: $(src-dir)punchtime.cpp $(punchtime-dir)punchtime.h
	@$(CXX) $(i-flag) -c $(src-dir)punchtime.cpp
	@printf "%5s %-30s -> %s\n" $(CXX) $< $@

time.o: $(src-dir)time.cpp $(punchtime-dir)time.h
	@$(CXX) $(i-flag) -c $(src-dir)time.cpp
	@printf "%5s %-30s -> %s\n" $(CXX) $< $@

clean:
	rm -f *.o *.exe $(target) test_result

test:
	$(CXX) -I /usr/local/boost_1_73_0 -I include tests/test_all.cpp -o test_result