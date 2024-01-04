#include "mainlib.h"

void sighandler(int)
{
        Server::svOn = false;
}

void *serverThread(void *s)
{
        ((Server *)s)->serverLoop();
        pthread_exit(NULL);
}