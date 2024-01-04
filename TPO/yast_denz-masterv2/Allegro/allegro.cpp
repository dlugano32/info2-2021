#include "allegro.h"

ALLEGRO_EVENT_SOURCE *Allegro::dancepad;
ALLEGRO_EVENT *Allegro::dancepad_event;

Allegro::Allegro()
{
        al_init();

        if (!(al_install_mouse()) || !(al_install_keyboard()) || !(al_install_audio()))
                exit(-1);

        if (!(al_init_image_addon()) || !(al_init_font_addon()) || !(al_init_ttf_addon()) || !(al_init_acodec_addon()))
                exit(-1);

        dancepad = new ALLEGRO_EVENT_SOURCE;
        dancepad_event = new ALLEGRO_EVENT;

        al_init_user_event_source(dancepad);
        dancepad_event->type = ALLEGRO_EVENT_DANCEPAD_DOWN;
}

Allegro::~Allegro()
{
        delete dancepad;
        delete dancepad_event;

        al_uninstall_mouse();
        al_uninstall_keyboard();
        al_uninstall_audio();
        al_shutdown_ttf_addon();
        al_shutdown_font_addon();
        al_shutdown_image_addon();
}

int gw, gh, fr, dif, lvlin;
double tn;
char *lvl;