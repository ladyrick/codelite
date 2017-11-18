#include <stack>
#include <queue>
#include <list>
#include <iostream>

using namespace std;

void e1() {
    stack<int, list<int>> s;
    cout << s.top() << endl;
    queue<int, list<int>> q;
    cout << q.front() << q.back() << endl;
}

int main() {
    e1();
    return 0;
}