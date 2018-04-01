#include<cstring>

#include "String.h"

struct String::Srep {
	char *s;
	int sz; // length without '\0'.
	int n;  // ref counts.
	Srep(int nsz, const char *p) {
		n = 1;
		sz = nsz;
		s = new char[sz+1];
		strcpy(s, p);
	}
	~Srep() {delete[] s;}
	Srep * get_own_copy() {
		if (n == 1) {
			return this;
		}
		n--;
		return new Srep(sz, s);
	}
	void assign(int nsz, const char *p) {
		if (sz != nsz) {
			delete[] s;
			sz = nsz;
			s = new char[sz+1];
		}
		strcpy(s, p);
	}
private:
	Srep(const Srep &);
	Srep & operator=(const Srep &);
};

String::String() {
	rep = new Srep(0, "");
}

String::String(const String &s) {
	s.rep->n++;
	rep = s.rep;
}

String::~String() {
	if (--rep->n == 0) {
		delete rep;
	}
}

String & String::operator=(const String &s) {
	s.rep->n++; // maybe assin to itself.
	if (--rep->n == 0) {
		delete rep;
	}
	rep = s.rep;
	return *this;
}

String::String(const char *cstr) {
	rep = new Srep(strlen(cstr), cstr);
}

String & String::operator=(const char *cstr) {
	if (rep->n == 1) {
		rep->assign(strlen(cstr), cstr);
	} else {
		rep->n--;
		rep = new Srep(strlen(cstr), cstr);
	}
	return *this;
}

String & String::operator+=(const char *cstr) {
	int newSz = rep->sz + strlen(cstr);
	char newStr[newSz + 1];
	strcpy(newStr, rep->s);
	strcat(newStr, cstr); // strcat will add a '\0' automatically.
	if (--rep->n == 0) {
		delete rep;
	}
	rep = new Srep(newSz, newStr);
	return *this;
}

String & String::operator+=(const String &s) {
	int newSz = rep->sz + s.rep->sz;
	char newStr[newSz + 1];
	strcpy(newStr, rep->s);
	strcat(newStr, s.rep->s);
	if (--rep->n == 0) {
		delete rep;
	}
	rep = new Srep(newSz, newStr);
	return *this;
}

ostream & operator<< (ostream &cout, const String &s) {
	cout << s.rep->s;
}

istream & operator>> (istream &cin, String &s) {
	const int len = 128;
	char cstr[len];
	cin >> cstr; // cin will add a '\0' automatically.
	s = cstr;
}

bool operator==(const String &x, const String &y) {
	return strcmp(x.rep->s, y.rep->s) == 0;
}

bool operator==(const String &s, const char *cstr) {
	return strcmp(s.rep->s, cstr) == 0;
}

bool String::operator==(const char *cstr) {
	return strcmp(this->rep->s, cstr) == 0;
}

bool String::operator==(const String &s) {
	return strcmp(this->rep->s, s.rep->s) == 0;
}

char String::read(int index) const {
	return rep->s[index];
	//return *(rep->s+index);
}

void String::write(int index, char c) {
	rep = rep->get_own_copy();
	rep->s[index] = c;
}

int String::size() const {
	return rep->sz;
}

String::Cref String::operator[] (int i) {
	return Cref(*this, i);
}

char String::operator[] (int i) const {
	return rep->s[i];
}




