#include "FnObj.h"
#include "PtrGen.h"
#include "Subscript.h"

#include<iostream>

using namespace std;

int main(int argc, char *argv[]) {
	FnObj fo(7);
	fo(77);

	int arr[3] = {1, 2, 3};
	PtrGen<int> pi(arr);
	pi++;
	cout << "*pi.operator->():" << *pi.operator->() << ".\n";

	Subscript ss;
	ss.getI();

	int i = 7;
	const int &ir = i;
	//ir++; // wrong.
	return 0;
}
