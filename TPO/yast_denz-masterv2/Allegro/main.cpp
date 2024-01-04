#include "mainlib.h"

int main(int argc, char **argv)
{
        if (argc != 7)
                exit(-1);

        gw = atoi(*(argv + 1));
        gh = atoi(*(argv + 2));
        fr = atoi(*(argv + 3));
        dif = atoi(*(argv + 4));
        lvl = *(argv + 5);

        pthread_t svThread;

        Allegro al;
        Game g;
        Server s(atoi(*(argv + 6)));

        signal(SIGUSR1, sighandler);
        pthread_create(&svThread, nullptr, serverThread, (void *) &s);

        do
        {
                g.waitReady() ? g.endScreen(g.gameLoop()) : g.nop();
        } while(Game::gmOn);

        raise(SIGUSR1);
        pthread_join(svThread, nullptr);

        return 0;
}