#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/time.h>
#include <wait.h>

int main(int argc, char *argv[])
{
    struct timeval start_time, end_time;
    pid_t pid = fork();

    gettimeofday(&start_time, NULL);

    if(pid == 0){
        execvp(argv[1], &argv[1]);
    }else if(pid > 0){
        wait(NULL);
        gettimeofday(&end_time, NULL);

        printf("Elapsed sec: %d\n", end_time.tv_sec - start_time.tv_sec);
        printf("Elapsed usec: %d\n", end_time.tv_usec - start_time.tv_usec);
    }

    

    return 0;
}
