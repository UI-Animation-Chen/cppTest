#include "FnObj.h"
#include "PtrGen.h"

#include<iostream>

using namespace std;

int main(int argc, char *argv[]) {
	FnObj fo(7);
	fo(77);
	PtrGen<int> pi(7);
	cout << "*pi.operator->():" << *pi.operator->() << ".\n";
	return 0;
}
