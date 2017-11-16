#include <cstdio>
#include <iostream>
#include "MyArray.hpp"
#include "MyLink.hpp"
using namespace std;

template <class Init>
void display(Init start, Init end) {
    for(Init mid = start; mid != end; mid++) {
        cout << (*mid) << endl;
    }
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
    display(ary.Begin(), ary.End());

    cout << "MyLink" << endl;
    MyLink<int> lnk;
    for(int i = 0; i < 10; i++) {
        lnk.Add(i + 1);
    }
    display(lnk.Begin(), lnk.End());
}

int main() {
    //    oldMethod();
    newMethod();
    return 0;
}
