

#include <stdio.h>
#include <unistd.h>
#include <iostream>

int main() {
    printf("printf   \n");
    sleep(1);
    pid_t pid = fork();
    std::cout << "why there are 2 \"printf\"?\n";
    return 0;
}
