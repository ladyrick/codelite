#include <iostream>
#include <bitset>

using namespace std;

void e1() {
    bitset<32> b(123);
    bitset<32> c("2222222233322222", 10, '3', '2');
    cout << b << endl;
    cout << c << endl;
    cout << bitset<32>() << endl;
}

int main() {
    e1();
    return 0;
}