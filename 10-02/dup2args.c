#include <unistd.h>
#include <stdio.h>
int main(int argc, char *argv[])
{
    int p[2];
    if (pipe(p))
    {
        perror("Erreur de création de tube");
        return 0;
    }
    if (fork())
    {
        close(p[0]);
        dup2(p[1], 1); // stdout = 1
        close(p[1]);
        execlp(argv[1], argv[1], NULL);
    }
    else
    {
        close(p[1]);
        dup2(p[0], 0); // stdin =0
        close(p[0]);
        execlp(argv[2], argv[2], NULL);
    }
}