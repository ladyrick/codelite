#include <unistd.h>
#include <iostream>

using namespace std;

int main() {
    pid_t fpid; //fpid表示fork函数返回的值
    int count = 0;
    fpid = fork();
    if (fpid < 0)
        cout << "error in fork!" << endl;
    else if (fpid == 0) {
        cout << "I am the child process, my process id is " << getpid() << endl;
        count++;
    } else {
        cout << "I am the parent process, my process id is " << getpid() << endl;
        count++;
    }
    cout << "count = " << count << endl;
    return 0;
}
