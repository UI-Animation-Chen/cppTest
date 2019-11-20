/**
 * c++ demo.
 */

#include <iostream>
#include <string>

using namespace std;

// 一维数组做函数参数时，编译器总是把它解析成一个指向其首元素的指针(不是常量)。
// 实际传递的数组大小与形参指定的数组大小没关系。
// 这里编译器把arr解析为指向int的指针，方括号中的数字根本不看。这里等价于int *arr;
void printArr(int arr[], int len) {
    cout << "[";
    for (int i = 0; i < len; i++) {
        cout << arr[i];
        if (len == i+1) {
            cout << "]\n";
        } else {
            cout << ", ";
        }
    }
}

void bubbleSort() {
    int count = 0;
    int n = 800;
    //int arr[n] = {3, 2, 5, 4, 1, 0, 6, 7};
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < n-i; j++) {
            // cmp j and j+1
            //if (arr[j] > arr[j+1]) {
            //    int tmp = arr[j];
            //    arr[j] = arr[j+1];
            //    arr[j+1] = tmp;
            //}
            count++;
        }
    }
    cout << "bubble sort count:" << count << ".\n";
    //printArr(arr, n);
}

void quickSort() {
    int count = 0;
    int n = 800;
    //int arr[n];
    for (int gap=n/2; 0<gap; gap/=2) {
        for (int i=gap; i<n; i++) {
            for (int j=i-gap; 0<=j; j-=gap) {
                count++;
            }
        }
    }
    cout << "quick sort count:" << count << ".\n";
}

void inputLine() {
    cout << "please input a str:\n";
    string str;
    getline(cin, str);
    cout << "the str is:" << str << '\n';
}

/**
 * typedef defines a type, not a variable, so can't be used as a variable.
 */
typedef void (*PRINTLN)();

int main(int argc, char *argv[]) {
	string *str = new string("czf");
	cout << "size: " << sizeof(*str) << ", " << *str << endl;
	free(str);

	char *null = nullptr;
	if (!null) {
		cout << "nullptr is false" << endl;
	}

    bubbleSort();
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

