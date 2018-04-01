#ifndef String_h
#define String_h

#include<iostream>

using namespace std;

class String {
	struct Srep;
	Srep *rep;
public:
	class Cref {
		friend class String; // all String mem fns.
		String &s;
		int i;
		Cref(String &ss, int ii): s(ss), i(ii) {}
	public:
		operator char() const {return s.read(i);}
		void operator= (char c) {s.write(i, c);}
	};
	
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
	
	char read(int) const;
	void write(int, char);
	
	Cref operator[] (int);
	char operator[] (int) const;
	
	int size() const;
};

#endif //String_h







