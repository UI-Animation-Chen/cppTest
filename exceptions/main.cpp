#include "MyException.h"

#include<iostream>
#include<exception>

using namespace std;

void g() {
	try {
		throw exception();
	} catch (exception &e) {
		g();
		cout << e.what();
	}
}

int main(int argc, char *argv[]) {
	//g();
	try {
		//throw MyException();
		
		int buffer = 7;
		cout << "buffer addr: " << &buffer << ".\n";
		
		int *alloc = new(&buffer) int;
		cout << "alloc  addr: " << alloc << ".\n";
		
		cout << "*alloc: " << *alloc << ".\n";
		
	} catch(MyException &e) {
		cout << "catch e\n";
	}
	return 0;
}
