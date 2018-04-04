#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

void e1() {
    vector<int> t = {1, 2, 3, 4, 5, 6, 7, 8, 9, 4, 5, 4, 3, 4, 4, 4, 4};
    cout << count(t.begin(), t.end(), 4) << endl;
}

void e2() {
    vector<int> t = {1, 2, 3, 4, 5, 6, 7, 8, 9, 4, 5, 4, 3, 4, 4, 4, 4};
    cout << count_if(t.begin(), t.end(), bind2nd(greater<int>(), 3)) << endl;
}

int main() {
    e1();
    e2();
}
