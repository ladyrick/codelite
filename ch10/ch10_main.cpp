#include <vector>
#include <list>
#include <algorithm>
#include <iterator>
#include <iostream>
#include <random>
#include <ctime>

using namespace std;

template<class T>
void display(T a) {
    copy(a.begin(), a.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
}

void e1() {
    vector<int> a = {1, 4, 3, 5, 2};
    sort(a.begin(), a.end());
    display(a);
    list<int> b = {1, 4, 3, 5, 2};
    b.sort();
    display(b);
    vector<int> c = {1, 4, 3, 5, 2};
    partial_sort(c.begin(), c.begin() + 3, c.end());
    display(c);
}

void e2() {
    uniform_int_distribution<> r(0,100);
    default_random_engine re((unsigned int)time(nullptr));
    for (int i = 0; i < 12; i++) {
        vector<int> d;
        generate_n(back_inserter(d), 10, [&r, &re]() { return r(re); });
        auto e = d;
        sort(e.begin(), e.end());
        nth_element(d.begin(), d.begin() + i, d.end());
        cout << i << endl;
        display(d);
        display(e);
    }
}

void e3() {
    vector<int> a = {1, 1, 1, 1, 1, 2, 2, 2, 2, 3, 3, 3, 4, 4};
    cout << lower_bound(a.begin(), a.end(), 2) - a.begin() << endl;
    cout << upper_bound(a.begin(), a.end(), 2) - a.begin() << endl;
    auto p = equal_range(a.begin(), a.end(), 2);
    cout << p.first - a.begin() << p.second - a.begin() << endl;
}

int main() {
//    e1();
    e2();
//    e3();
}