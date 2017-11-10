#include <cstdio>
#include <iostream>
using namespace std;

template <class T>
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
        if(m_nValidSize < m_nTotalSize) {
            m_pData[m_nValidSize] = value;
            m_nValidSize++;
        } else {
            T *tempData = new T[m_nTotalSize];
            for(int i = 0; i < m_nTotalSize; i++) {
                tempData[i] = m_pData[i];
            }
            delete[] m_pData;
            m_nTotalSize *= 2;
            m_pData = new T[m_nTotalSize];
            for(int i = 0; i < m_nValidSize; i++) {
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
        if(m_pData != nullptr) {
            delete m_pData;
            m_pData = nullptr;
        }
    }

    T *Begin() {
        return m_pData;
    }

    T *End() {
        return m_pData + m_nValidSize;
    }
};

template <class T>
struct Unit {
    T value;
    Unit *next;
};

template <class T>
class MyLink {
public:
    Unit<T> *head, *tail, *prev;

public:
    MyLink() {
        head = tail = prev = nullptr;
    }

    void Add(T value) {
        Unit<T> *u = new Unit<T>();
        u->value = value;
        u->next = nullptr;
        if(head == nullptr) {
            head = u;
            prev = u;
        } else {
            prev->next = u;
            prev = u;
        }
        tail = u->next;
    }

    virtual ~MyLink() {
        if(head != nullptr) {
            Unit<T> *prev = head;
            Unit<T> *next = nullptr;
            while(prev != tail) {
                next = prev->next;
                delete prev;
                prev = next;
            }
        }
    }

    Unit<T> *Begin() {
        return head;
    }

    Unit<T> *End() {
        return tail;
    }
};

template <class Init>
void display(Init start, Init end) {
    for(Init mid = start; mid != end; mid++) {
        cout << *mid << endl;
    }
}

template <class Init>
class ArrayIterator {
    Init *init;

public:
    ArrayIterator(Init *init) {
        this->init = init;
    }
    bool operator!=(ArrayIterator &it) {
        return this->init != it.init;
    }
    void operator++(int) { // 有时候本不需要参数，但是为了结构，必须有一个参数。就可以只写一个int。
        init++;
    }
    Init operator*() {
        return *init;
    }
};

template <class Init>
class LinkIterator {
    Init *init;

public:
    LinkIterator(Init *init) {
        this->init = init;
    }
    bool operator!=(LinkIterator &it) {
        return this->init != it.init;
    }
    void operator++(int) {
        init = init->next;
    }
    Init operator*() {
        return *init;
    }
};

template <class T>
ostream &operator<<(ostream &os, const Unit<T> &s) {
    os << s.value;
    return os;
}

void oldMethod() {
    MyArray<int> arrayobj;

    for(int i = 0; i < 10; i++) {
        arrayobj.Add(i + 1);
    }
    for(int i = 0; i < arrayobj.GetSize(); i++) {
        cout << arrayobj.Get(i) << endl;
    }

    MyLink<int> linkobj;

    for(int i = 0; i < 10; i++) {
        linkobj.Add(i + 1);
    }
}

void newMethod() {
    cout << "MyArray" << endl;
    MyArray<int> ary;
    for(int i = 0; i < 10; i++) {
        ary.Add(i + 1);
    }
    ArrayIterator<int> start1(ary.Begin());
    ArrayIterator<int> end1(ary.End());
    display(start1, end1);

    cout << "MyLink" << endl;
    MyLink<int> lnk;
    for(int i = 0; i < 10; i++) {
        lnk.Add(i + 1);
    }
    LinkIterator<Unit<int> > start2(lnk.Begin());
    LinkIterator<Unit<int> > end2(lnk.End());
    display(start2, end2);
}

int main() {
    //    oldMethod();
    newMethod();
    return 0;
}
