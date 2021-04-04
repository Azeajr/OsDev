#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>

int main(){
    fork();
    fork();
    fork();

    pid_t id = getpid();
    printf("process: %d\n", id);

    return 0;
}
/**
 * @brief This process will end up spawning a total of 8 processes including
 * the parent process.
 */
/*
M           c1    c2    c3
c1 2 fork   c4    c5
c2 1 fork   c6
c3 0 fork
c4 1 fork   c7
c5 0 fork
c6 0 fork
c7 0 fork
*/