#include <stdio.h>
#include <pthread.h>

#define N 15
int a = 0;

void * hola(void *arg);
pthread_mutex_t mutexA = PTHREAD_MUTEX_INITIALIZER;

int main(int argc, char *argv[])
{
    pthread_t id[N];

    for(int i = 0; i < N; i++)
    {
        pthread_create(id + i, NULL, hola, NULL);
    }

    for(int i = 0; i < N; i++)
    {
        pthread_join( id[i], NULL);
    }

    pthread_mutex_destroy(&mutexA);
    pthread_exit(NULL);

}

void * hola(void * arg)
{
    pthread_mutex_lock (&mutexA);
        printf("Hola soy el thread nro: %d\n", a++);
    pthread_mutex_unlock (&mutexA);

    pthread_exit(NULL);
}
