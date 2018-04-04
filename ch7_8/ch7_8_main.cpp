#include <iostream>
#include <string>
#include <set>

using namespace std;

void e1() {
    multiset<double> a;
    double b[] = {1, 2, 3, 4, 4, 4, 4, 4, 5, 6, 7, 8, 9};
    a.insert(b, b + 9);
    cout << a.size();
    auto r = a.erase(--a.end());
    cout << a.size();
    auto t = a.erase(4);

    cout << *r << endl;
    cout << *a.begin() << *a.end() << endl;
    for (auto &item : a) {
        cout << item << endl;
    }
}

void e2() {
    int arr[] = {1, 2, 2, 2, 1, 1, 3, 4, 4, 5, 6, 6, 4, 3, 2, 5};
    multiset<int> ms(arr, arr + 16);
    auto range = ms.equal_range(1);
    auto i = range.first;
    for (; i != range.second; ++i) {
        cout << *i << endl;
    }

    auto f = ms.find(1);
    cout << *f << *(++f) << *(++f) << *(++f);
}

class test {
    int a[10] = {0};
public:
    test() {
        a[0] = 1;
    }
};

class Student {
public:
    string name;
    test t;

    explicit Student(const string &name) : t() {
        this->name = name;
    }

    friend bool operator<(const Student &s1, const Student &s2) {
        return s1.name < s2.name;
    }

    friend bool operator==(const Student &s1, const Student &s2) {
        return false;
    }
};

void e3() {
    set<Student> ss;
    ss.insert(Student("1"));
    ss.insert(Student("2"));
    ss.insert(Student(string("2")));
    for (auto &item : ss) {
        cout << item.name << endl;
    }
}

int main() {
//    e1();
//    e2();
    e3();
}