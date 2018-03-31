main: main.o String.o
	g++ main.o String.o -o main
main.o: main.cpp String.h
	g++ -c main.cpp -o main.o
String.o: String.cpp String.h
	g++ -c String.cpp -o String.o
