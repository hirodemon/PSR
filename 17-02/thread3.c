#include <stdio.h>
#include <pthread.h>

// Global variable
int arg = 0, max = 1000000;
pthread_mutex_t verrou;

void *incrementer()
{
    for (int i = 0; i < max; i++)
    {
        pthread_mutex_lock(&verrou);
        arg++;
        //printf("INC: %d\n", arg);
        pthread_mutex_unlock(&verrou);
    }
    pthread_exit(NULL);
}

void *decrementer()
{
    for (int i = 0; i < max; i++)
    {
        pthread_mutex_lock(&verrou);
        arg--;
        //printf("DEC: %d\n", arg);
        pthread_mutex_unlock(&verrou);
    }
    pthread_exit(NULL);
}

int main()
{
    pthread_mutex_init(&verrou, NULL);
    pthread_t thi, thd;
    pthread_create(&thi, NULL, incrementer, &arg);
    pthread_create(&thd, NULL, decrementer, &arg);
    pthread_join(thi, NULL);
    pthread_join(thd, NULL);
    printf("Valeur finale = %d\n", arg);
    return 0;
}