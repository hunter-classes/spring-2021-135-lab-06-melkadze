main: main.o funcs.o
	g++ -o main main.o funcs.ot
	
test-ascii: test-ascii.o
	g++ -o test-ascii test-ascii.o

tests: tests.o funcs.o
	g++ -o tests tests.o funcs.o



test-ascii.o: test-ascii.cpp

funcs.o: funcs.cpp funcs.h

main.o: main.cpp funcs.h

tests.o: tests.cpp doctest.h funcs.h

clean:
	rm -f main.o funcs.o tests.o test-ascii.o