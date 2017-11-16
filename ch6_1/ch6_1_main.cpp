#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class CSum {
private:
    int sum;
public:
    CSum() : sum(0) { cout << "constructor" << endl; }

    void operator()(int n) {
        sum += n;
    }

    int getSum() {
        return sum;
    }
};

int main() {
    vector<int> v(100);
    for (int i = 0; i < 100; ++i) {
        v[i] = i + 1;
    }
    CSum obj = for_each(v.begin(), v.end(), CSum());
    cout << obj.getSum() << endl;
    return 0;
}