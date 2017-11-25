#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void printCube(int n) {
    cout << n * n * n << endl;
}

void e1() {
    vector<int> v = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    auto f = for_each(v.begin(), v.end(), printCube);
    f(-1);
    int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    f = for_each(arr, arr + 10, printCube);
    f(-1);
}

int main() {
    e1();
}