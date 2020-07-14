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
};
