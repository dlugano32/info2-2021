#include "server.h"

bool Server::svOn;

Server::Server(int port)
{
        int opt = 1;
        svOn = true;

        ssock = socket(AF_INET, SOCK_STREAM | SOCK_NONBLOCK, 0);
        setsockopt(ssock, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(int));

        my_addr.sin_family = AF_INET;
        my_addr.sin_port = htons(port);
        my_addr.sin_addr.s_addr = htonl(INADDR_ANY);
        memset((void *)&(my_addr.sin_zero), '\0', 8);

        if (bind(ssock, (struct sockaddr *)&my_addr, sizeof(my_addr)) < 0)
        {
                printf("%s\n", strerror(errno));
                exit(-1);
        }
}

Server::~Server()
{
        close(ssock);
}

void Server::serverLoop()
{
        char input[17]; // # 1 timestamp(10 chars) @\0
        char verif;
        char type;
        char timestamp[10];

        int aux;
        unsigned int len;

        listen(ssock, 1);
        len = sizeof(cl_addr);

        do
        {
                memset(input, 0, sizeof(input));
                usleep(1000);
        } while ((csock = accept4(ssock, (struct sockaddr *)&cl_addr, &len, SOCK_NONBLOCK)) == -1 && svOn && errno == EWOULDBLOCK);
        if (csock < 0)
        {
                printf("%s\n", strerror(errno));
                exit(-1);
        }

        do
        {
                memset(input, 0, sizeof(input));
                usleep(1000);
        } while ((aux = read(csock, input, sizeof(input))) == -1 && svOn && errno == EWOULDBLOCK);
        if (aux < 0 && errno != EWOULDBLOCK)
        {
                printf("%s\n", strerror(errno));
                exit(-1);
        }
        if (strcmp(input, "READY") != 0)
        {
                svOn = false;
        }
        printf("READY\n");

        usleep(10000);

        memset(input, 0, sizeof(input));
        *input = '#';
        *(input + 1) = (char)(dif + 48);
        *(input + 2) = (char)(lvlin + 48);
        *(input + 3) = '@';
        *(input + 4) = '\0';
        write(csock, input, 5);
        printf("%s\n", input);

        usleep(10000);

        while (svOn)
        {
                memset(input, 0, sizeof(input));
                aux = read(csock, input, sizeof(input));
                if (aux == -1)
                {
                        if (errno != EWOULDBLOCK)
                        {
                                printf("%s\n", strerror(errno));
                                exit(-1);
                        }
                        else
                                usleep(1000);
                }
                else
                {
                        printf("%s\n", input);

                        sscanf(input, "%c", &verif);
                        if (verif == '#')
                        {
                                sscanf(input + 2, "%c", &type);
                                sscanf(input + 4, "%s", timestamp);
                                sscanf(input + 5 + strlen(timestamp), "%c", &verif);
                                if (verif == '@')
                                {
                                        Allegro::dancepad_event->touch.x = atof(timestamp) / 1000;
                                        switch (type - 48)
                                        {
                                        case 1:
                                                Allegro::dancepad_event->touch.id = ALLEGRO_KEY_RIGHT;
                                                break;
                                        case 2:
                                                Allegro::dancepad_event->touch.id = ALLEGRO_KEY_DOWN;
                                                break;
                                        case 3:
                                                Allegro::dancepad_event->touch.id = ALLEGRO_KEY_LEFT;
                                                break;
                                        case 4:
                                                Allegro::dancepad_event->touch.id = ALLEGRO_KEY_UP;
                                                break;
                                        }

                                        al_emit_user_event(Allegro::dancepad, Allegro::dancepad_event, nullptr);
                                }
                        }
                        else if (verif == '@')
                        {
                                sscanf(input + 2, "%s", timestamp);
                                sscanf(input + 3 + strlen(timestamp), "%c", &verif);
                                if ((!strcmp(timestamp, "START")) && verif == '#')
                                {
                                        printf("Start\n");
                                        Allegro::dancepad_event->touch.id = ALLEGRO_KEY_ENTER;
                                        al_emit_user_event(Allegro::dancepad, Allegro::dancepad_event, nullptr);
                                }
                        }
                }
        }

        write(csock, "@C#", 4);
        close(csock);
}