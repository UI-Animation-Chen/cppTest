#include<iostream>

using namespace std;

class X {
public:
	virtual void show() {
		cout << "X.\n";
	};
};

class Y {
public:
	virtual void show() {
		cout << "Y.\n";
	};
};

class XY: public X, public Y {
public:
	void show() {
		cout << "XY.\n";
	}
};

int main(int argc, char *argv[]) {
	XY xy;
	X &x = xy;
	x.show();
}

