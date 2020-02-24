#include <stdio.h>
#include <pthread.h>

// Global variables
int tab[50000], i = 0;
pthread_mutex_t mutex;

void *mettre1()
{
    while (i <= 50000)
    {
        pthread_mutex_lock(&mutex);
        tab[i] = 1;
        i++;
        pthread_mutex_unlock(&mutex);
    }
    pthread_exit(NULL);
}

void *mettre2()
{
    while (i <= 50000)
    {
        pthread_mutex_lock(&mutex);
        tab[i] = 2;
        i++;
        pthread_mutex_unlock(&mutex);
    }
    pthread_exit(NULL);
}

int main()
{
    int var = 0;

    // Creating threads
    pthread_mutex_init(&mutex, NULL);
    pthread_t th1, th2;
    pthread_create(&th1, NULL, mettre1, NULL);
    pthread_create(&th2, NULL, mettre2, NULL);
    pthread_join(th1, NULL);
    pthread_join(th2, NULL);

    // Test who is winner
    for (i = 0; i <= 50000; i++)
        if (tab[i] == 1)
        {
            printf("%d\n", var);
            var++;
        }
    if (var == 25000)
        printf("Egalité\n");
    else if (var > 25000)
        printf("Th1 Winner!\n");
    else
        printf("Th2 Winner!\n");

    return 0;
}