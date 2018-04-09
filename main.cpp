/**
 * c++ demo.
 */

#include<iostream>
#include<string>

using namespace std;

void inputLine() {
    cout << "please input a str:\n";
    string str;
    getline(cin, str);
    cout << "the str is:" << str << '\n';
}

class Fu {
public:
    virtual void print() {cout << "Fu\n";}
};

class Zi: public Fu {
public:
    //void print() {cout << "Zi\n";}
};

/**
 * typedef defines a type, not a variable, so can't be use as a variable.
 */
typedef void (*PRINTLN)();

int main(int argc, char *argv[]) {
    
    Zi z;
    Fu &f = z;
    f.print();
    
    //inputLine();
    //[](int i) -> void {cout << "closure i: " << i << ".\n";}(7);
    
    //PRINTLN println = inputLine;
    //println();

	//int arr[] = {1};
	//int (*parr)[1] = &arr; // 指向数组的指针。
	//cout << " arr:" << arr << ".\n";
	//cout << "parr:" << &arr << ".\n";
    
    return 0;
}






