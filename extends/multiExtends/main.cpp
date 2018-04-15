#include<iostream>

using namespace std;

class S {
public:
	int mem;
	S() {cout << "S constructor.\n";}
	virtual void show() {
		cout << "S.\n";
	}
};

class X: virtual public S {
public:
	virtual void show() {
		cout << "X.\n";
	};
};

class Y: virtual public S {
public:
	virtual void show() {
		cout << "Y.\n";
	};
};

class Z: virtual public S {
	virtual void show() {
		cout << "Z.\n";
	}
};

class XYZ: public X, public Y, public Z {
public:
	void show() {
		cout << "XYZ.\n";
	}
};

int main(int argc, char *argv[]) {
	XYZ xyz;
	S &s = xyz;
	s.show();
}

