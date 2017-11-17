#include <iostream>
#include <string>

using namespace std;

int main() {
    string s1 = "123";
    string s2 = move(s1);
    s1[1] = 'a';
    cout << s1;
}