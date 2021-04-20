
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>


int main(int argc, char const *argv[])
{
    pid_t pid = fork();

    if(pid > 0){
        sleep(50);
    } else {
        exit(0);
    }

    return 0;
}
