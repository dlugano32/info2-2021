#ifndef GAME_H
#define GAME_H

#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>

#include "allegro.h"
#include "background.h"
#include "arrow.h"

#define WINDOW_TITLE "Just Dance! Game"
#define ICON_IMG "media/icon.png"

#define BACKGROUND_IMG "media/background.png"

#define ARROW1_IMG "media/A1.png"
#define ARROW2_IMG "media/A2.png"
#define ARROW3_IMG "media/A3.png"
#define ARROW4_IMG "media/A4.png"

#define TARGET_ARROW1_IMG "media/mA1.png"
#define TARGET_ARROW2_IMG "media/mA2.png"
#define TARGET_ARROW3_IMG "media/mA3.png"
#define TARGET_ARROW4_IMG "media/mA4.png"

#define DEFAULT_LVL "media/lvl_test.lvl"

class Game
{
private:
        ALLEGRO_DISPLAY *game;

        ALLEGRO_BITMAP *icon;

        ALLEGRO_EVENT_QUEUE *queue;

        ALLEGRO_AUDIO_STREAM *music;

        ALLEGRO_FONT *fontTitle, *fontText;

        ArrowQ *arrows;

        Element *gui;
        Element *presets;

        unsigned int cant;
        long int maxscore;
        double tmax;

public:
        Game();
        ~Game();

        static bool gmOn;

        inline ALLEGRO_DISPLAY *getGameDisp() { return game; };

        void drawGUI();
        bool waitReady();
        float gameLoop();
        void endScreen(float);
        inline void nop(){};
};

#endif
