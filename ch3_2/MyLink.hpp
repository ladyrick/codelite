#ifndef MYLINK_HPP
#define MYLINK_HPP
#include <iostream>

template <class T>
struct Unit {
    T value;
    Unit *next;
};

template <class T>
class MyLink {
public:
    class LinkIterator {
        Unit<T> *init;

    public:
        LinkIterator(Unit<T> *init) {
            this->init = init;
        }
        bool operator!=(LinkIterator &it) {
            return this->init != it.init;
        }
        void operator++(int) {
            init = init->next;
        }
        Unit<T> operator*() {
            return *init;
        }
    };

private:
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

    LinkIterator Begin() {
        return LinkIterator(head);
    }

    LinkIterator End() {
        return LinkIterator(tail);
    }
};

template <class T>
std::ostream &operator<<(std::ostream &os, const Unit<T> &s) {
    os << s.value;
    return os;
}

#endif // MYLINK_HPP
