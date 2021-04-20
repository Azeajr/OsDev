#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>


int main(int argc, char const *argv[])
{
    pid_t pid = fork();

    if(pid > 0){
        exit(0);
    } else {
        sleep(120);
    }

    return 0;
}