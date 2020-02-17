#include <stdio.h>
#include <pthread.h>

void *fc()
{
    printf("TID_C = %ld\n", pthread_self());
}

void *fa()
{
    pthread_t thc;
    pthread_create(&thc, NULL, fc, NULL);
    pthread_join(thc, NULL);
    printf("TID_A = %ld\n", pthread_self());
}

void *fb()
{
    printf("TID_B = %ld\n", pthread_self());
}

int main()
{
    pthread_t tha, thb;
    pthread_create(&tha, NULL, fa, NULL);
    pthread_create(&thb, NULL, fb, NULL);
    pthread_join(tha, NULL);
    pthread_join(thb, NULL);
    printf("TID_P = %ld\n", pthread_self());
    return 1;
}