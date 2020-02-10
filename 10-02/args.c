#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
int main(int argc, char *argv[])
{
    if (fork())
    {
        wait(NULL);
        return 0;
    }
    else
    {
        execvp(argv[1], &argv[1]);
    }
}