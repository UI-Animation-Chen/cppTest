/**
 * c++ demo.
 */

#include<iostream>
#include<string>

using namespace std;

void quickSort() {
    int count = 0;
    int n = 8;
    int arr[n];
    for (int gap=n/2; 0<gap; gap/=2) {
        for (int i=gap; i<n; i++) {
            for (int j=i-gap; 0<=j; j-=gap) {
                count++;
            }
        }
    }
    cout << "count:" << count << ".\n";
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

    quickSort();
    
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






