#include <iostream>
#include <list>
#include <vector>
#include <random>
#include <algorithm>

using namespace std;
typedef list<int> lint;

template <class T>
void display(T t) {
    for (auto &item : t) {
        cout << item;
    }
    cout << endl;
}

void e1() {
    vector<int> v = {1, 2, 3};
    lint l(v.begin(), v.end());
    display<lint>(l);
}

void e2() {
    lint l = {1, 2, 2, 3, 3, 4, 4, 5, 5, 6, 5, 5, 4, 4, 3, 3, 2, 2, 1};
    l.remove(3);
    display<lint>(l);
    l.unique();
    display<lint>(l);
}

void e3() {
    lint l = {1, 2, 2, 3, 3, 4, 4, 5, 5, 6, 5, 5, 4, 4, 3, 3, 2, 2, 1};
    l.sort();
    display<lint>(l);
    default_random_engine dre((unsigned) time(nullptr));
    uniform_int_distribution<int> randi(0, 1);
    l.sort([&randi, &dre](int x, int y) { return randi(dre); });
    display<lint>(l);
    vector<int> v = {1, 2, 3, 4, 5, 6, 7};
    shuffle(v.begin(), v.end(), dre);
    display<vector<int>>(v);
}

void e4() {
    lint l = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    lint m = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    l.splice(l.begin(), m, m.begin(), --m.end());
    display<lint>(l);
    display<lint>(m);
    l.end()--;
    display<lint>(l);
    l.reverse();
    display<lint>(l);
}

int main() {
    e1();
    e2();
    e3();
    e4();
    return 0;
}