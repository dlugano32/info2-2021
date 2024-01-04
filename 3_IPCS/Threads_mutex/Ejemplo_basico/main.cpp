#include <cstdio>
#include <pthread.h>

#define N 12
int a=0;

void* function(void *arg);

int main()
{
    pthread_t id[N];

    for(int i=0; i<N; i++)
    {
        pthread_create(id + i, NULL, function, NULL);
    }

    for(int i=0; i<N; i++)
    {
        pthread_join(id[i], NULL);
    }
}

void* function(void*arg)
{
    printf("Hola, soy el thread %d un gusto\n", a++);
    pthread_exit(NULL);
}
