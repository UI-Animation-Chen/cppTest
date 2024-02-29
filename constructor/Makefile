main: main.o Czf.o Person.o Hobby.o
	g++ main.o Czf.o Person.o Hobby.o -o main
main.o: main.cpp Person.h
	g++ -c main.cpp -o main.o
Czf.o: Czf.cpp Czf.h
	g++ -c Czf.cpp -o Czf.o
Person.o: Person.cpp Person.h
	g++ -c Person.cpp -o Person.o
Hobby.o: Hobby.cpp Hobby.h
	g++ -c Hobby.cpp -o Hobby.o
