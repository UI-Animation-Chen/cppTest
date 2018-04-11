#ifndef X_h
#define X_h

// 资源申请即初始化技术。

#include "MyException.h"

#include<iostream>

using namespace std;

class File_ptr {
public:
    File_ptr() {
        cout << "open a file\n";
    }
    ~File_ptr() {
        cout << "close a file\n";
    }
};

class Lock_ptr {
public:
    Lock_ptr() {
        cout << "owned a lock\n";
        //throw MyException(); // 将不会掉用析构。
    }
    ~Lock_ptr() {
        cout << "release a lock\n";
    }
};

class X {
    File_ptr f;
    Lock_ptr l;
public:
    X(): f(), l() {
        cout << "X constructed\n";
    }
    ~X() {
        cout << "X deconstructed\n";
    }
};

#endif //X_h
