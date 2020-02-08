#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main()
{
    char *a[] = {"ls", "-l", "/home", NULL};
    if (fork() == 0) 
    {
        /* Start Child task */
        sleep(3);
        if (execvp("ls", a) == -1) //exec vector in path(env var)
        {
            perror("execlp");
        }
        return 1;
        /* End Child task */
    }
    else
    {
        /* Start DAADDDYYY task */
        execlp("ls", "ls", "-l", "/home", NULL); // exec list
        return 0;
        /* End DAADDDYYY task */
    }
}