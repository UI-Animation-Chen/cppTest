#include<iostream>

using namespace std;

class B; // forward declaration.

class A {
    int i;
public:
    A(int paramI) {i = paramI;}
    int genI(B &b);
};

class B {
    int j;
public:
    B(int paramJ) {j = paramJ;}
    friend int A::genI(B &b);
};

// friend can access B private mem j.
int A::genI(B &b) {
    return this->i + b.j;
}

int main(int argc, char *argv[]) {
    A a(3);
    B b(4);
    int result = a.genI(b);
    cout << "result:" << result << ".\n";
    return 0;
}
