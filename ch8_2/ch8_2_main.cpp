#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> v = {1, 2, 3, 4, 4, 3, 2, 1, 1, 2, 3, 4, 4, 3, 2, 1};

void e1() {
    cout << "find\t" << find(v.begin(), v.end(), 3) - v.begin() << endl;
}

void e2() {
    cout << "find_if\t" << find_if(v.begin(), v.end(), bind2nd(greater<int>(), 3)) - v.begin() << endl;
}

void e3() {
    vector<int> vf = {3, 6, 9, 12};
    cout << "find_first_of\t" << find_first_of(v.begin(), v.end(), vf.begin(), vf.end()) - v.begin() << endl;
}

void e4() {
    cout << "adjacent_find\t" << adjacent_find(v.begin(), v.end()) - v.begin() << endl;
}

void e5() {
    vector<int> vf = {3, 4, 4, 3, 2};
    cout << "find_end\t" << find_end(v.begin(), v.end(), vf.begin(), vf.end()) - v.begin() << endl;
}

void e6() {
    vector<int> vf = {3, 4, 4, 3, 2};
    cout << "search\t" << search(v.begin(), v.end(), vf.begin(), vf.end()) - v.begin() << endl;
}

void e7() {
    cout << "search_n\t" << search_n(v.begin(), v.end(), 2, 4) - v.begin() << endl;
}

int main() {
    e1();
    e2();
    e3();
    e4();
    e5();
    e6();
    e7();
}