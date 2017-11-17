#ifndef MYARRAY_HPP
#define MYARRAY_HPP

template<class T>
class MyArray {
private:
    int m_nTotalSize;
    int m_nValidSize;
    T *m_pData;

public:
    class ArrayIterator {
        T *init;

    public:
        ArrayIterator(T *init) {
            this->init = init;
        }

        bool operator!=(ArrayIterator &it) {
            return this->init != it.init;
        }

        void operator++(int) { // 有时候本不需要参数，但是为了结构，必须有一个参数。就可以只写一个int。
            init++;
        }

        T operator*() {
            return *init;
        }
    };

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

    ArrayIterator Begin() {
        return ArrayIterator(m_pData);
    }

    ArrayIterator End() {
        return ArrayIterator(m_pData + m_nValidSize);
    }
};

#endif // MYARRAY_HPP
