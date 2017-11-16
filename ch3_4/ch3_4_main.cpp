#include <iostream>
#include <iterator>
#include <stack>
using namespace std;

stack<int> s;

void test_istream() {
    cout << "please input some integer:" << endl;
    istream_iterator<int> a(cin);
    istream_iterator<int> b;
    while(a != b) {
        cout << *a << endl;
        s.push(*a);
        a++;
    }
}

void test_ostream() {
    cout << "output iterator:" << endl;
    ostream_iterator<int> a(cout, "\t");
    while(!s.empty()) {
        *a = s.top();
        s.pop();
    }
}

int main(int argc, char *argv[]) {
    test_istream();
    test_ostream();
    return 0;
}