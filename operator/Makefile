main: main.o FnObj.o Subscript.o
	g++ main.o FnObj.o Subscript.o -o main
main.o: main.cpp FnObj.h PtrGen.h
	g++ -c main.cpp -o main.o
FnObj.o: FnObj.cpp FnObj.h
	g++ -c FnObj.cpp -o FnObj.o
Subscript.o: Subscript.cpp Subscript.h
	g++ -c Subscript.cpp -o Subscript.o
