#include<iostream>
#include<vector>

using namespace std;

int main(int argc, char *argv[]) {
	vector<int> v;
	cout << "size:" << v.size() << ".\n";

	for (int i = 1; i <= 3; i++) {
		v.push_back(i);
	}

	vector<int>::reverse_iterator ri = v.rbegin();
	ri++;
	vector<int>::iterator base = ri.base();
	cout << "base:" << *base << ".\n";

	vector<int>::iterator insertI = v.insert(base, 4);

	//v.resize(0);

	cout << "front:" << v.front() << ".\n";
	cout << "back:" << v.back() << ".\n";
	cout << "maxSize:" << v.max_size() << ".\n";
	cout << "capacity:" << v.capacity() << ".\n";

	vector<int> v2;
	v.swap(v2);

	vector<int>::iterator i = v.begin();
	while(i != v.end()) {
		cout << *i << ".\n";
		i++;
	}
	return 0;
}
