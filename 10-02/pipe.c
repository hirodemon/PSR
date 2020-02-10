#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <sys/wait.h>
int main()
{
    char *message = "Bonjour mon père";
    char messageR[100];
    int p[2];
    if (pipe(p))
    {
        perror("Erreur de création de tube");
        return 0;
    }
    else
    {
        if (fork())
        {
            close(p[1]);
            wait(NULL);
            read(p[0], messageR, 100);
            printf("Mon fils m'a envoyé %s\n", messageR);
            return 1;
        }
        else
        {
            close(p[0]);
            write(p[1], message, strlen(message) + 1);
            exit(2);
        }
    }
}