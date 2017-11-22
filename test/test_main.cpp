#include <iostream>
#include <iterator>

using namespace std;

int main() {
    ostream_iterator<int> oit(cout, "\n");
    istream_iterator<int> iit(cin);
    istream_iterator<int> end;
    while(iit != end){
        oit = *iit;
        ++iit;
    }
}