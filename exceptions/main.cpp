#include "MyException.h"
#include "X.h"

#include<iostream>
#include<exception>

using namespace std;

void recursive(int i) {
    if (i < 5) {
        // 堆栈回退会销毁指针变量e，但e所指的存储不会释放。
        // 这种情况很难找到合适的地方进行销毁，使用'资源申请即初始化'技术会方便很多。
        MyException *e = new MyException;
        //MyException e; // ok, stack mem.
        recursive(++i);
    } else {
        throw exception();
    }
}

int main(int argc, char *argv[]) {
	try {
        //recursive(0);
        //X x;
        //throw MyException();
	} catch(MyException &e) {
		cout << "catch MyException\n";
    } catch(exception &ee) {
        cout << "catch exception\n";
    }
	return 0;
}
