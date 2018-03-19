#include <iostream>
#include <iterator>
#include <algorithm>
#include <vector>
#include <ctime>
#include <conio.h>
using namespace std;

void e1() {
    vector<int> a = {1, 2, 3, 4, 5};
    copy(a.begin(), a.end(), ostream_iterator<int>(cout, "#"));
    vector<int> b;
    copy(istream_iterator<int>(cin), istream_iterator<int>(), back_inserter(b));
    copy(b.begin(), b.end(), ostream_iterator<int>(cout, "#"));
}

void e2() {
    fill_n(ostream_iterator<int>(cout, ""), 10, 1);
}

void e3() {
    vector<int> a;
    generate_n(back_inserter(a), 10, [&a]() { return a.size(); });
    copy(a.begin(), a.end(), ostream_iterator<int>(cout, ""));
}

void e4() {
    vector<int> a = {1, 2, 3, 4, 5};
    reverse_copy(a.begin(), a.end(), a.begin());
    copy(a.begin(), a.end(), ostream_iterator<int>(cout, ""));
}

void delay(){
    auto start = time(nullptr);
    auto end = start;
    while(start == end){
        end = time(nullptr);
    }
}

void e5(){
    int a[] = {1,2,3,4,5,6,7,8,9};
    while(!kbhit()){
        copy(a, a+9, ostream_iterator<int>(cout, ""));
        rotate(a, a+1, a+9);
        delay();
        cout << endl;
    }
}

int main() {
//    e1();
//    e2();
//    e3();
//    e4();
    e5();
}