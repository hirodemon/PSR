#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
int main()
{
    int n;
    printf("je suis père de PID = %d, mon PPID = %d\n",
           (int)getpid(), (int)getppid());
    //fflush(stdout);
    n = fork();
    fork(); // create son for both
    if (!fork()) // if son 
    {
        printf("Je suis le fils: la valeur de n = %d, mon PID = %d, mon ppid = %d\n",
               n, (int)getpid(), getppid());
        return 0;
    }
    else
    {
        printf("Je suis le père: la valeur de n = %d, mon PID = %d, mon ppid = %d\n",
               n, (int)getpid(), getppid());
        return 1;
    }
}