#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class cast2bits {
private:
    struct bits {
        unsigned char b7 : 1;
        unsigned char b6 : 1;
        unsigned char b5 : 1;
        unsigned char b4 : 1;
        unsigned char b3 : 1;
        unsigned char b2 : 1;
        unsigned char b1 : 1;
        unsigned char b0 : 1;
    };

public:
    int length;
    ostringstream os;

    template<class T>
    // 构造函数竟然可以用模板？！
    explicit cast2bits(const T &input) {
        const T *pTInput = &input;
        auto *pBitsinput = (bits *) pTInput;
        int n = sizeof(T) / sizeof(bits);
        length = 9 * n - 1;
        for (int i = n - 1; i >= 0; --i) {
            os << (int) ((pBitsinput + i)->b0) << (int) ((pBitsinput + i)->b1) << (int) ((pBitsinput + i)->b2) << (int) ((pBitsinput + i)->b3) << (int) ((pBitsinput + i)->b4) << (int) ((pBitsinput + i)->b5) << (int) ((pBitsinput + i)->b6) << (int) ((pBitsinput + i)->b7) << ' ';
        }
    }

    friend ostream &operator<<(ostream &os, const cast2bits &c) {
        os << "M" << string((unsigned long long int) (c.length - 2), ' ') << "L" << endl;
        os << c.os.str() << endl;
        return os;
    }
};


int main() {
    cout << cast2bits(123) << endl;
    cout << cast2bits((long long) 123) << endl;
    cout << cast2bits(123.0f) << endl;
    cout << cast2bits(123.0) << endl;
    cout << cast2bits('3') << endl;
    cout << cast2bits("123") << endl;
    cout << cast2bits(string("123")) << endl;
    return 0;
}
