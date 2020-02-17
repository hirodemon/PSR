#include <stdio.h>
#include <pthread.h>
/*  !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    gcc thread1.c -o thread1 -lpthread
    !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!  */

void *afficher(void *param)
{
    int *t = (int *)param;
    printf("Valeur = %d\n", *t);
}

int main()
{
    pthread_t th1;
    int arg = 5;
    int r = 0;
    r = pthread_create(&th1, NULL, afficher, &arg);
    if (r == -1)
    {
        perror("error de creation de thread");
        pthread_exit(NULL);
    }
    pthread_join(th1, NULL);
    return 1;
}