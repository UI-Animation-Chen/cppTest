main: main.o Animal.o Cat.o SmallCat.o
	g++ main.o Animal.o Cat.o SmallCat.o -o main
main.o: main.cpp Animal.h Cat.h
	g++ -c main.cpp -o main.o
Animal.o: Animal.cpp Animal.h
	g++ -c Animal.cpp -o Animal.o
Cat.o: Cat.cpp Cat.h Animal.h
	g++ -c Cat.cpp -o Cat.o
SmallCat.o: SmallCat.cpp SmallCat.h Cat.h Animal.h
	g++ -c SmallCat.cpp -o SmallCat.o

