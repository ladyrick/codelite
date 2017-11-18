#include <iostream>
#include <bitset>

using namespace std;

void e1(){
    bitset<32> b(123);
    bitset<32> c("23223222322223222223",7, 7, '2', '3');
    cout << b << endl;
    cout << c << endl;
    cout << bitset<32>() << endl;
}

int main(){
    e1();
    return 0;
}