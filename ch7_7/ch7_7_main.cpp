#include <iostream>
#include <bitset>

using namespace std;

void e1() {
    bitset<32> b(123);
    bitset<32> c(string("10101010"),0, 3);
    cout << b << endl;
    cout << c << endl;
    cout << bitset<32>() << endl;
}

void e2(){
    cout << bitset<32>().set().to_ulong() << endl;
    cout << bitset<64>().set().to_ullong() << endl;
}

int main() {
    e1();
    e2();
    return 0;
}