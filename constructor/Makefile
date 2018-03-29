main: main.o Person.o Hobby.o
	g++ main.o Person.o Hobby.o -o main
main.o: main.cpp Person.h
	g++ -c main.cpp -o main.o
Person.o: Person.cpp Person.h
	g++ -c Person.cpp -o Person.o
Hobby.o: Hobby.cpp Hobby.h
	g++ -c Hobby.cpp -o Hobby.o
