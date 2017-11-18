#include <queue>
#include <iostream>


using namespace std;

void e1() {
    int a[] = {4, 2, 3, 6, 5, 7, 9, 1, 8};
    priority_queue<int, deque<int>, greater<int>> pq(a, a + 9);
    while (!pq.empty()) {
        cout << pq.top();
        pq.pop();
    }
    cout << endl;
}

int main() {
    e1();
    return 0;
}