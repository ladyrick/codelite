#include <functional>
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <iterator>

using namespace std;

class Student {
    string strNO;
    string strName;
public:
    Student(string &&strNO, string &&strName) {
        this->strNO = strNO;
        this->strName = strName;
    }

    void show() {
        cout << strNO << " : " << strName << endl;
    }
};

int main() {
    plus<int> p;
    minus<int> m;
    multiplies<int> m2;
    divides<int> d;
    modulus<int> m3;
    negate<int> n;
    int a = 1;
    int b = 3;
    cout << p(a, b) << endl;
    cout << m(a, b) << endl;
    cout << m2(a, b) << endl;
    cout << d(a, b) << endl;
    cout << m3(a, b) << endl;
    cout << n(a) << endl;

    vector<int> va = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    // 用lambda表达式也可以做得很好啊。
    auto result = accumulate(va.begin(), va.end(), 0, [](int x, int y) { return x + y; });
    cout << result << endl;
    cout << not_equal_to<int>()(2, 4) << endl;

    // 函数适配器
    vector<int> aa = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
    // 统计大于5的数目。
    cout << "greater than 5: " << count_if(aa.begin(), aa.end(), bind2nd(greater<int>(), 5)) << endl;
    cout << "not greater than 5: " << count_if(aa.begin(), aa.end(), not1(bind2nd(greater<int>(), 5))) << endl;


    Student s1("1001", "Alice");
    Student s2("1002", "Bob");
    vector<Student> vstu = {s1, s2};
    for_each(vstu.begin(), vstu.end(), mem_fun_ref(Student::show));
    Student *ps1 = &s1;
    Student *ps2 = &s2;
    vector<Student*> vpstu = {ps1, ps2};
    for_each(vpstu.begin(), vpstu.end(), mem_fun(Student::show));
    return 0;
}