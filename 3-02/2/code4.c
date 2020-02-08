#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
int main()
{
    int etat, pid_fils, ez;

    if (fork()) // if father
    {
        printf("Je suis le père, je vais attendre mon fils\n");
        pid_fils = wait(&etat); // -> exit()
        printf("Mon fils de pid = %d, m'a envoyé le signal %x\n", pid_fils, etat);
        return 0;
    }
    else // fils
    {
        printf("Je suis le fils je vais attendre 15 secondes\n");
        sleep(15);          // ./code4& -> ps -> kill -9 (pid_fils)
        if (getppid() == 1) // booh maaash mawjood hawnyya
            printf("\nmon père est mort\n");
        exit(0xFA); // wait()
    }
}