#include <iostream>
#include <string>

using namespace std;

class test {
public:
    int t;

     test(int tt) : t(tt) {
        cout << "test constructor" << endl;
    }

    test(const test &tt) : t(tt.t) {
        cout << "test copy constructor" << endl;
    }
};

class Student {
public:
    string name;
    int grade;
    test t3;
public:
    Student(/*string name,*/ int grade, const test &tt) : /*name(name),*/ grade(grade), t3(tt) {}

    bool operator<(const Student &s) {
        return grade < s.grade;
    }
};

int main() {
    test t(20);
    Student s(100, 20);
    return 0;
}