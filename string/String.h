#ifndef String_h
#define String_h

#include<iostream>

using namespace std;

class String {
	struct Srep;
	Srep *rep;
public:
	class Cref;
	
	String();
	String(const char *);
	String(const String &);
	String & operator=(const char *);
	String & operator=(const String &);
	~String();
	
	String & operator+=(const char *);
	String & operator+=(const String &);

	friend ostream & operator<< (ostream &, const String &);
	friend istream & operator>> (istream &, String &);
	
	// 想访问私有部分，但不想以成员函数形式，那就只有友元了。
	friend bool operator==(const String &x, const String &y);
	friend bool operator==(const String &s, const char *);
	// 当然也可以用成员函数形式。
	bool operator==(const String &);
	bool operator==(const char *);
};

#endif //String_h

