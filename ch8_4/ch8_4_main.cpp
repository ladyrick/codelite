#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

void e1() {
    vector<int> t = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    cout << equal(t.begin(), --t.end(), t.begin() + 1) << endl;
}

void e2() {
    vector<int> t1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    vector<int> t2 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
    pair<vector<int>::iterator, vector<int>::iterator> &&result = mismatch(t1.begin(), t1.end(), t2.begin());
    cout << *(result.first) << " | " << *(result.second) << endl;
}

int main() {
    e1();
    e2();
}
