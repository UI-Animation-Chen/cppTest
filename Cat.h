#include <ostream>

using namespace std;

class Cat {
public:
    Cat() {
        cout << "Cat" << endl;
    }
    ~Cat() {
        cout << "~Cat" << endl;
    }
    Cat(Cat &c) {
        cout << "Cat copy constructor" << endl;
    }
    Cat(Cat &&c) {
        cout << "Cat move constructor" << endl;
    }
    Cat & operator=(Cat &c) {
        cout << "Cat assign operator" << endl;
        return *this;
    }
    Cat & operator=(Cat &&c) {
        cout << "Cat move operator" << endl;
        return *this;
    }
};
