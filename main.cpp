/**
 * c++ demo.
 */

#include <iostream>
#include <string>
#include <utility> // std::move

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

void shuffle() {
    int len = 10;
    int arr[len];
    for (int i = 0; i < len; i++) {
        arr[i] = i;
    }

    printf("rand_max: %d\n", RAND_MAX);

    for (int i = len - 1; i >= 0; i--) {
        // len - (len - 1 - i) : len -> 1
        int rand_index = rand() % (len - (len - 1 - i));
        int tmp = arr[i];
        arr[i] = arr[rand_index];
        arr[rand_index] = tmp;
    }

    for (int i = 0; i < len; i++) {
        printf("%d, ", arr[i]);
    }
    printf("\n");
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

    char c = (char)255; // 255的低8位都是1，不管赋给什么类型，二进制位都不会变化。
                        // 也就是c这个变量不管是什么类型，低8位都是1。
    printf("c: %d\n", (signed char)c);
    printf("c: %d\n", (unsigned char)c);

    // shuffle();

    /*
	char num_str[] = "123e2", *after_end;
	int num = strtod(num_str, &after_end);
	cout << "num:" << num << "." << endl;
	cout << "after_end:" << *after_end << "." << endl;
	cout << "numstr:" << num_str << "." << endl;
	cout << "offset:" << after_end - num_str << "." << endl;
    */

    /*
    string str = "Hello, world";
    string str1 = move(str);
    str1 = "hello";
    cout << "str: " << str << ", str1: " << str1 << endl;
    */

    /*
    signed char sc = 1; // 补码为0000 0001
    // ~sc: 针对sc的补码取反得1111 1110
    // 反码(-1) - 原码：1111 1101 -> 1000 0010 -> -2
    cout << "sc: " << ~sc << endl;
    // 取-1的补码，不管左边变量是什么类型，直接接收这个二进制形式。
    unsigned int ui = -1;
    printf("ui: %ud\n", ui);
    */

	/*
	char *null = nullptr;
	if (!null) {
		cout << "nullptr is false" << endl;
	}
	*/

    //bubbleSort();
    //quickSort();
    
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

