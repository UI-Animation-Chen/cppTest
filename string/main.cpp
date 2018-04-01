#include<cstring>

#include "String.h"

int main(int argc, char *argv[]) {
	String s("hello world!");
	String s1 = s;
	s += s1;
	cout << "s:" << s << '\n';
	cout << "s[1]:" << s.read(1) << ".\n";
	s.write(5, '_');
	s[17] = '_';
	cout << "write 5,_ s[17]:" << s << ".\n";
	cout << "s.size:" << s.size() << ".\n";
	return 0;
}
