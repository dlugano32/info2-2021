#include <stdio.h>
#include <pthread.h>

#define N 12

pthread_mutex_t mutexA= PTHREAD_MUTEX_INITIALIZER;
int a=0;

void* par(void *arg);
void* impar(void *arg);

void* ( *function[2] )(void *arg) ={par, impar};

int main()
{
    pthread_t id[N];

    for(int i=0; i<N; i++)
    {
        pthread_create(id +i, NULL, function[i%2], NULL);
    }

    for(int i=0; i<N; i++)
    {
        pthread_join(id[i], NULL);
    }

    pthread_mutex_destroy(&mutexA);
    pthread_exit(NULL);
}

void* par(void *arg)
{
    pthread_mutex_lock(&mutexA);
    printf("Hola soy un thread par %d\n", a++);
    pthread_mutex_unlock(&mutexA);

    pthread_exit(NULL);
}

void* impar(void *arg)
{
    pthread_mutex_lock(&mutexA);
    printf("Hola soy un thread impar %d\n", a++);
    pthread_mutex_unlock(&mutexA);

    pthread_exit(NULL);
}
