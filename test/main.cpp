#include <iostream>
using namespace std;

struct bit_8 {
    unsigned char b0 : 1;
    unsigned char b1 : 1;
    unsigned char b2 : 1;
    unsigned char b3 : 1;
    unsigned char b4 : 1;
    unsigned char b5 : 1;
    unsigned char b6 : 1;
    unsigned char b7 : 1;
};

union int_32 {
    bit_8 int_bit[4];
    int integer;
};

int main(int argc, char *argv[]) {
    int_32 test;
    test.integer = (((64 + 16 + 4 + 1) * 256 + (64 + 16 + 4 + 1)) * 256 + (64 + 16 + 4 + 1)) * 256 + (64 + 16 + 4 + 1);
    test.integer <<= 1;
    cout << test.integer << endl;
    for(int i = 3; i > -1; i--) {
        bit_8 *this_byte = test.int_bit + i;
        cout << int(this_byte->b7);
        cout << int(this_byte->b6);
        cout << int(this_byte->b5);
        cout << int(this_byte->b4);
        cout << int(this_byte->b3);
        cout << int(this_byte->b2);
        cout << int(this_byte->b1);
        cout << int(this_byte->b0);
    }
    cout << endl;
    return 0;
}