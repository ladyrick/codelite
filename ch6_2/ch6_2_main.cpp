#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

template<class _inPara, class _outPara>
class CSum {
private:
    _outPara sum;
public:
    CSum(_inPara init = 0) : sum(init) {}

    void operator()(_inPara n) {
        sum += n;
    }

    _outPara getSum() {
        return sum;
    }
};

int main() {
    vector<int> v;
    for (int i = 0; i < 100; i++) {
        v.push_back(i + 1);
    }
    auto obj = for_each(v.begin(), v.end(), CSum<int, double>(0));
    cout << obj.getSum() << endl;
    return 0;
}