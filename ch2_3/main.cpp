#include <iostream>
using namespace std;

class CIntArray {
    int a[10];

public:
    CIntArray() {
        for(int i = 0; i < 10; i++) {
            a[i] = i + 1;
        }
    }
    int getSum(int times) {
        int sum = 0;
        for(int i = 0; i < 10; i++) {
            sum += a[i];
        }
        return sum * times;
    }
};

class CFloatArray {
    float f[10];

public:
    CFloatArray() {
        for(int i = 0; i < 10; i++) {
            f[i] = i + 1;
        }
    }
    float getSum(float times) {
        float sum = 0;
        for(int i = 0; i < 10; i++) {
            sum += f[i];
        }
        return sum * times;
    }
};

//定义基本模板类
template <typename T>
class NumTraits {};

//模板特化
template <>
class NumTraits<CIntArray> {
public:
    typedef int resulttype;
    typedef int inputpara;
};

template <>
class NumTraits<CFloatArray> {
public:
    typedef float resulttype;
    typedef float inputpara;
};

//统一模板调用类编制
template <typename T>
class CApply {
public:
    typedef typename NumTraits<T>::resulttype result;
    typedef typename NumTraits<T>::inputpara input;
    result getSum(T &obj, input in) {
        return obj.getSum(in);
    }
};

int main(int argc, char *argv[]) {
    cout << "Hello World!" << endl;
    CIntArray a;
    CFloatArray f;
    CApply<CIntArray> ca1;
    CApply<CFloatArray> ca2;
    cout << "INT: " << ca1.getSum(a, 3) << endl;
    cout << "FLOAT: " << ca2.getSum(f, 3.3f) << endl;
}