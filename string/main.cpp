#include<cstring>

#include "String.h"

int main(int argc, char *argv[]) {
	String s("hello world!");
	String s1 = s;
	s += s1;
	cout << "s:" << s << '\n';
	return 0;
}
