main: main.o
	g++ -std=c++11 main.cpp -o main
main.o: main.cpp
	g++ -std=c++11 -c main.cpp -o main.o