#include <iostream>
#include <deque>

using namespace std;

class test {
public:
    test() {
        cout << "constructor" << endl;
    }

    test(const test &) {
        cout << "copy constructor" << endl;
    }

    ~test() {
        cout << "destructor" << endl;
    }
};

void e1() {
    deque<int> d;
    for (int i = 0; i < 10; i++) {
        if (i % 2) {
            d.push_front(0);
        } else {
            d.push_back(0);
        }
        cout << "push" << (i % 2 ? "front" : "back") << "\tmemory: ";
        for (int &item : d) {
            auto p = ((signed long long) (&item) / sizeof(int)) % 1000;
            cout << p << " ";
        }
        cout << endl;
    }
}

void e2() {
    deque<test> t;
    test tt;
    t.push_back(tt);
    for (auto &item : t) {
        cout << "item" << endl;
    }
}

int main() {
    e1();
//    e2();
    return 0;
}