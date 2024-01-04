#ifndef ALLEGRO
#define ALLEGRO

#include <allegro5/allegro5.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <stdio.h>

#define ALLEGRO_EVENT_DANCEPAD_DOWN 67687890

class Allegro
{
private:
public:
        Allegro();
        ~Allegro();

        static ALLEGRO_EVENT_SOURCE *dancepad;
        static ALLEGRO_EVENT *dancepad_event;
};

extern int gw, gh, fr, dif, lvlin;
extern double tn;
extern char *lvl;

#endif
