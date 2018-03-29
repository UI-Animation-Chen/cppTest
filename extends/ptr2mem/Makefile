main: main.o Cat.o Cat.h
	g++ main.o Cat.o -o main
main.o: main.cpp Cat.h
	g++ -c main.cpp -o main.o
Cat.o: Cat.cpp Cat.h
	g++ -c Cat.cpp -o Cat.o
