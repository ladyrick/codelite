#include <iostream>
#include <vector>
#include <list>
#include <deque>

using namespace std;

void e1() {
    vector<int> vi;
    back_insert_iterator<vector<int>> bii(vi);
    bii = 1;
    bii = 2;
    bii = 6;
    bii = 7;
    bii = 8;
    for (auto &item : vi) {
        cout << item << endl;
    }
    insert_iterator<vector<int>> ii(vi, vi.begin() + 2);
    ii = 3;
    ii = 4;
    ii = 5;
    for (auto &item : vi) {
        cout << item << endl;
    }
}

void e2() {
    list<int> li;
    auto fi = front_inserter(li);
    fi = 3;
    fi = 2;
    fi = 1;
    auto bi = back_inserter(li);
    bi = 4;
    bi = 5;
    for (auto &item : li) {
        cout << item;
    }
}

void e3() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector<int> v(arr, arr + 9);
    reverse_iterator<vector<int>::iterator> first(v.end());
    reverse_iterator<vector<int>::iterator> last(v.begin());
    for (auto it = first; it != last; ++it) {
        cout << *it << endl;
    }
}

void e4() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    deque<int> v(arr, arr + 9);
    auto it = v.begin();
    advance(it, 3);
    cout << distance(v.begin(), it) << endl;
    cout << distance(arr, arr + 6) << endl;
    auto itend = v.end();
    cout << ":" << *itend << endl; ++itend;
    cout << ":" << *itend << endl; ++itend;
    cout << ":" << *itend << endl; ++itend;
    cout << ":" << *itend << endl; ++itend;
    cout << ":" << *itend << endl; ++itend;
    cout << ":" << *itend << endl; ++itend;
    cout << ":" << *itend << endl; ++itend;
    cout << ":" << *itend << endl; ++itend;
    cout << ":" << *itend << endl; ++itend;
    cout << ":" << *itend << endl; ++itend;
}

int main() {
//    e1();
//    e2();
//    e3();
    e4();
}