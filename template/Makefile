main: main.o List.o
	g++ main.o List.o -o main
main.o: main.cpp List.h Cat.h
	g++ -c main.cpp -o main.o
List.o: List.cpp List.h
	g++ -c List.cpp -o List.o
