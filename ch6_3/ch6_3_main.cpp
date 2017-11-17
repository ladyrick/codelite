#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <iterator>

using namespace std;

class Student {
private:
    string name;
    int grade;
public:
    Student(const string &name, int grade) {
        this->name = name;
        this->grade = grade;
        cout << "lvalue name" << endl;
    }

    Student(string &&name, int grade) {
        this->name = name;
        this->grade = grade;
        cout << "rvalue name" << endl;
    }

    string &getName() { return name; }

    int getGrade() { return grade; }

    bool operator<(const Student &s) {
        return grade < s.grade;
    }

    friend ostream &operator<<(ostream &os, const Student &stu) {
        os << setw(10) << setiosflags(ios::left) << stu.name << stu.grade;
        return os;
    }
};

template<class T>
class binary_sort {
public:
    bool operator()(T &t1, const T &t2) {
        return t1 < t2;
    }
};

int main() {
    Student s1("Alice", 100);
    Student s2("Bob", 80);
    Student s3("Cat", 70);
    Student s4("Dog", 90);
    vector<Student> s;
    s.push_back(s1);
    s.push_back(s2);
    s.push_back(s3);
    s.push_back(s4);
    sort(s.begin(), s.end(), binary_sort<Student>());
    copy(s.begin(), s.end(), ostream_iterator<Student>(cout, "\n"));
    return 0;
}
