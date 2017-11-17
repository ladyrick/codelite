#include <cstdio>

using namespace std;

template<class T>
class MyArray {
private:
    int m_nTotalSize;
    int m_nValidSize;
    T *m_pData;

public:
    MyArray(int nSize = 3) {
        m_pData = new T[nSize];
        m_nTotalSize = nSize;
        m_nValidSize = 0;
    }

    void Add(T value) {
        if (m_nValidSize < m_nTotalSize) {
            m_pData[m_nValidSize] = value;
            m_nValidSize++;
        } else {
            T *tempData = new T[m_nTotalSize];
            for (int i = 0; i < m_nTotalSize; i++) {
                tempData[i] = m_pData[i];
            }
            delete[] m_pData;
            m_nTotalSize *= 2;
            m_pData = new T[m_nTotalSize];
            for (int i = 0; i < m_nValidSize; i++) {
                m_pData[i] = tempData[i];
            }
            delete[] tempData;
            m_pData[m_nValidSize] = value;
            m_nValidSize++;
        }
    }

    int GetSize() {
        return m_nValidSize;
    }

    T Get(int pos) {
        return m_pData[pos];
    }

    virtual ~MyArray() {
        if (m_pData != nullptr) {
            delete m_pData;
            m_pData = nullptr;
        }
    }
};

int main() {
    MyArray<int> obj;

    for (int i = 0; i < 10; i++) {
        obj.Add(i + 1);
    }
    for (int i = 0; i < obj.GetSize(); i++) {
        printf("%d\n", obj.Get(i));
    }
    return 0;
}
