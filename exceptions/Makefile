main: main.o MyException.o
	g++ main.o MyException.o -o main
main.o: main.cpp MyException.h X.h
	g++ -c main.cpp -o main.o
MyException.o: MyException.cpp MyException.h
	g++ -c MyException.cpp -o MyException.o
