#include <iostream>
#include <vector>
#include <list>

using namespace std;

int main() {
    vector<int> a = {1, 2, 3, 4, 5, 6, 7};
    a.reserve(10);
    int *a1 = &a[1];
    a.push_back(6);
    int *a2 = &a[1];
    cout << "a max_size: " << a.max_size() << endl;
    cout << "a capacity: " << a.capacity() << endl;
    cout << "use reserve:" << endl;
    cout << "a1: " << a1 << endl;
    cout << "a2: " << a2 << endl;

    vector<int> b = {1, 2, 3, 4, 5, 6, 7};

    int *b1 = &b[1];
    b.push_back(6);
    int *b2 = &b[1];
    cout << "b max_size: " << b.max_size() << endl;
    cout << "b capacity: " << b.capacity() << endl;
    cout << "no reserve:" << endl;
    cout << "b1: " << b1 << endl;
    cout << "b2: " << b2 << endl;
    list<int> la = {1, 3, 2};
    for (auto lait: la) {
        cout << lait << endl;
    }
    la.sort();
    for (auto lait: la) {
        cout << lait << endl;
    }
    return 0;
}