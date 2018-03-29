main: main.o FnObj.o
	g++ main.o FnObj.o -o main
main.o: main.cpp FnObj.h PtrGen.h
	g++ -c main.cpp -o main.o
FnObj.o: FnObj.cpp FnObj.h
	g++ -c FnObj.cpp -o FnObj.o
