#include <iostream>
#include <map>

using namespace std;

void e1() {
    multimap<int, int> m;
    m.insert(pair<int, int>(1, 1));
    m.insert(pair<int, int>(1, 2));
    m.insert(pair<int, int>(2, 2));
    m.insert(pair<int, int>(2, 3));
    auto it = m.equal_range(1);
    for (auto its = it.first; its != it.second; ++its) {
        cout << its->first << ":" << its->second << endl;
    }
}

int main() {
    e1();
}
