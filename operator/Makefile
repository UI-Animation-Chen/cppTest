main: main.o FnObj.o FnObj.h
	g++ main.o FnObj.o -o main
main.o: main.cpp FnObj.h
	g++ -c main.cpp -o main.o
FnObj.o: FnObj.cpp FnObj.h
	g++ -c FnObj.cpp -o FnObj.o
