#include "MyException.h"
#include "X.h"

#include<iostream>

using namespace std;

int main(int argc, char *argv[]) {
	try {
        X x;
        //throw MyException();
	} catch(MyException &e) {
		cout << "catch e\n";
	}
	return 0;
}
