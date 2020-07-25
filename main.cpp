/**
 * c++ demo.
 */

#include <iostream>
#include <string>
#include <utility> // std::move
#include <memory> // shared_ptr, unique_ptr
#include "Cat.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

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

/**
 * macros:
 * ##: 连接两边内容
 * #:  将后面的内容两边加上双引号，转为字符串
 * #@: 将后面的内容两边加上单引号，转为字符
 */
#define Connect(x,y) x##y
#define ToString(x) #x
//#define ToChar(x) #@x // 编译器不支持？？？

/**
 * 通过函数重载验证这个值是被当左值还是右值处理。
 * std::move
 */
void processValue(int &i) {
    cout << "left value: " << i << endl;
}
void processValue(int &&i) {
    cout << "right value: " << i << endl;
}

/**
 * 父子进程共享文件，读写位置(pos)也会共享。
 */
void shareFileInChildProc() {
    int fd;
    int c;

    fd = open("./Cat.h", O_RDONLY, O_APPEND);
    if (fd < 0) {
        cout << "open file: notes.h err, errmsg: " << strerror(errno) << endl;
        return;
    } else {
        cout << "fd: " << fd << endl;
    }

    if (fork() == 0) {
        read(fd, &c, 1);
        char ch = c;
        cout << "child:" << ch << endl;
        close(fd);
        return;
    }

    read(fd, &c, 1);
    char ch = c;
    cout << "parent:" << ch << endl;
    close(fd);
}

template<typename... ARGS>
inline void my_log(const char *format_str, ARGS... args) noexcept {
    printf(format_str, args...);
}

int main(int argc, char *argv[]) {
#ifdef MACRO_FROM_CMD
    cout << "macro from cmd" << endl;
#endif

    // my_log("--==-- %d\n", 7);

    //shareFileInChildProc();

    /*
    Cat c;
    Cat c1;
    c1 = std::move(c);
    const Cat &c2 = std::move(c1);
    */

    /*
    // 智能指针shared_ptr表示可以有多个变量指向同一个对象
    // 因此，该指针变量本身可以被拷贝
    shared_ptr<Cat> pCat = make_shared<Cat>();

    shared_ptr<Cat> *pCat1 = (shared_ptr<Cat> *)malloc(sizeof(shared_ptr<Cat>));
    *pCat1 = pCat;

    // *pCat1 = nullptr;
    pCat1->reset();

    free(pCat1);
    pCat1 = nullptr;
    */

    // 智能指针unique_ptr表示只能有一个变量指向该对象
    // 因此，该指针变量本身不能被拷贝，只能移动
    unique_ptr<Cat> puCat = unique_ptr<Cat>(new Cat());
    // unique_ptr<Cat> puCat1 = puCat; // err，不能被拷贝
    unique_ptr<Cat> puCat1 = move(puCat); // ok，可以移动
    puCat = nullptr; // 移动后，puCat不再关联对象，置为nullptr也不会销毁对象。

    cout << "---" << endl;

    /*
    int i = 7;
    int &j = i;
    processValue(j);
    processValue(move(j));
    */

    /*
    cout << "1##2: " << Connect(1, 2) << endl;
    cout << "#123+1: " << ToString(123) + 1 << endl; */
//    cout << "#@x:" << ToChar(2) << endl;

    /*
    char c = (char)255; // 255的低8位都是1，不管赋给什么类型，二进制位都不会变化。
                        // 也就是c这个变量不管是什么类型，低8位都是1。
    printf("c: %d\n", (signed char)c);
    printf("c: %d\n", (unsigned char)c);

    // 在运算之前，如果有不同的符号，首先全部转成无符号。
    int i = -1;
    unsigned int ui = 1;
    cout << i << " > " << ui << " : "  << (i > ui) << endl;
    */

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

