#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>

int value = 5;

int main(){
    pid_t pid;

    pid = fork();

    if(pid == 0){
        value += 15;
        return 0;
    }
    else if(pid > 0){
        wait(NULL);
        /**
         * @brief This printf will print PARENT: value = 5 because global
         * variables are not shared between parent and child processes.
         */
        printf("PARENT: value = %d\n", value);
        return 0;
    }
}
