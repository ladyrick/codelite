#include <iostream>
#include <vector>

using namespace std;

void e1() {
    vector<int> a(10);
    a.reserve(100);
    cout << a.size() << endl;

    cout << *(a.begin()) << endl;

    a.assign(5, 1);

    cout << a.capacity() << endl;

    for (auto item:a) {
        cout << item << " ";
    }
    cout << endl;
}

void e2() {
    vector<int> b;
    cout << "init size: " << b.size() << "\tcapacity: " << b.capacity() << endl;
    for (int i = 0; i < 65; i++) {
        b.push_back(i);
        cout << "push size: " << b.size() << "\tcapacity: " << b.capacity() << endl;
    }
}

int main() {

//    e1();
    e2();
    return 0;
}