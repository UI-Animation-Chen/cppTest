#include <iostream>

using namespace std;

enum Fruit { apple, pear };

int main(int argc, char *argv[], char *env[]) {
    Fruit f = pear; // 不需要加enum了，c里必须加。
    cout << f << endl;
    return 0;
}

