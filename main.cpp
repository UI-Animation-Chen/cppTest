/**
 * c++ demo.
 */

#include<iostream>
#include<string>

using namespace std;

void printCLIArgs(int argc, char *argv[]) {
    for (int i = 0; i < argc; i++) {
        cout << "arg" << i << ": " << argv[i] << ".\n";
    }
}

void stdIO() {
    cout << "please input a num:\n";
    int i;
    cin >> i;
    cout << "the num is:" << i << '\n';
}

void inputLine() {
    cout << "please input a str:\n";
    string str;
    getline(cin, str);
    cout << "the str is:" << str << '\n';
}

/**
 * typedef defines a type, not a variable, so can't be use as a variable.
 */
typedef void (*PRINTLN)();

int main(int argc, char *argv[]) {
	int i = 1;
	// c++中，前缀结果是左值，后缀不是。c中前后缀都不是左值。
	cout << "(++)i++: " << (++i)++ << ".\n";
    //printCLIArgs(argc, argv);
    //stdIO();
    //inputLine();
    //[](int i) -> void {cout << "closure i: " << i << ".\n";}(7);
    
    //PRINTLN println = inputLine;
    //println();

	int autovar;
	cout << "autovar:" << autovar << ".\n";

	int *ip = new int();
	cout << "*ip:" << *ip << ".\n";

	int arr[] = {1};
	int (*parr)[1] = &arr;
	cout << " arr:" << arr << ".\n";
	cout << "parr:" << &arr << ".\n";
    
    return 0;
}






