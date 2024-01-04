#ifndef SERVER
#define SERVER

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>

#include <signal.h>

#include <arpa/inet.h>
#include <netdb.h>

#include "allegro.h"

struct data
{
        char type;
        long timestamp;
};

class Server
{
private:
        int ssock, csock;
        struct sockaddr_in my_addr, cl_addr;

public:
        Server(int = 0);
        ~Server();

        static bool svOn;

        void serverLoop();
};

#endif