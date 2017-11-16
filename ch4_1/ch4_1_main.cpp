#include <iostream>
#include <vector>
using namespace std;

typedef void (*pFunc)();

class Func {
public:
    static vector<pFunc> vfunc;
    Func() {
    }
    Func(pFunc f) {
        vfunc.push_back(f);
    }
};
vector<pFunc> Func::vfunc;
#define REG(func) Func f_##func(func)

void e1() {
    int i;
    float f;
    char str[20];

    cin >> i >> f >> str;

    cout << "i = " << i << endl;
    cout << "f = " << f << endl;
    cout << "str = " << str << endl;
}
//REG(e1);

void e2() {
    int i;
    char str[20];
    cin >> i >> str;
    cout << "i = " << i << endl;
    cout << "str = " << str << endl;
}
//REG(e2);

void e3() {
    char str1[60];
    char str2[60];
    char str3[60];
    cout << "input a string:" << endl;
    int n = cin.get();
    cin.get(str1, 10, '#');
    cin.getline(str2, 10, '$');
    cin.get(str3, 10, '#');
    //123456#123456$123456#123456$
    cout << n << endl;
    cout << str1 << endl;
    cout << str2 << endl;
    cout << str3 << endl;
}
//REG(e3);

void e4() {
    int a;
    cout << "need an integer:" << endl;
    cin >> a;
    cout << "cin.rdstate: " << cin.rdstate() << endl;
    if(cin.good()) {
        cout << "good" << endl;
    }
    if(cin.fail()) {
        cout << "fail" << endl;
    }
}
//REG(e4);

void e5() {
    int a;
    cout << "input an integer:" << endl;
    while(true) {
        cin >> a;
        if(cin.fail()) {
            cout << "error input!" << endl;
            cin.clear();
            cin.sync();
            //cin.ignore(4, '\n');
        } else {
            cout << a << endl;
            break;
        }
    }
}
REG(e5);

int main() {
    vector<pFunc>::iterator it;
    vector<pFunc> &f = Func::vfunc;
    for(it = f.begin(); it != f.end(); it++) {
        (*it)();
    }
    return 0;
}