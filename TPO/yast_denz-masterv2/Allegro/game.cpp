#include "game.h"

bool Game::gmOn;

Game::Game()
{
        gmOn = true;
        arrows = nullptr;

        al_set_new_window_title(WINDOW_TITLE);
        al_set_new_window_position(0, 0);
        al_set_new_display_flags(ALLEGRO_WINDOWED | ALLEGRO_OPENGL);

        game = al_create_display(gw, gh);
        queue = al_create_event_queue();
        fontTitle = al_load_ttf_font("media/Ubuntu-Regular.ttf", 80, ALLEGRO_VIDEO_BITMAP);
        fontText = al_load_ttf_font("media/Ubuntu-Regular.ttf", 24, ALLEGRO_VIDEO_BITMAP);

        if (game == nullptr || queue == nullptr)
                exit(-1);

        if (!al_show_mouse_cursor(game) || !al_set_system_mouse_cursor(game, ALLEGRO_SYSTEM_MOUSE_CURSOR_ARROW))
                exit(-1);

        al_reserve_samples(16);

        icon = al_load_bitmap(ICON_IMG);
        al_set_display_icon(game, icon);

        al_register_event_source(queue, al_get_keyboard_event_source());
        al_register_event_source(queue, al_get_display_event_source(game));
        al_register_event_source(queue, Allegro::dancepad);

        Background b(BACKGROUND_IMG);

        Element A1(ARROW1_IMG, gh / 8, gh / 8, gh / 10 + ((gw - gh) / 2), gh);
        Element A2(ARROW2_IMG, gh / 8, gh / 8, 2 * gh / 10 + gh / 8 + ((gw - gh) / 2), gh);
        Element A3(ARROW3_IMG, gh / 8, gh / 8, 3 * gh / 10 + gh / 4 + ((gw - gh) / 2), gh);
        Element A4(ARROW4_IMG, gh / 8, gh / 8, 4 * gh / 10 + 3 * gh / 8 + ((gw - gh) / 2), gh);

        Element mA1(TARGET_ARROW1_IMG, gh / 8, gh / 8, gh / 10 + ((gw - gh) / 2), gh / 20);
        Element mA2(TARGET_ARROW2_IMG, gh / 8, gh / 8, 2 * gh / 10 + gh / 8 + ((gw - gh) / 2), gh / 20);
        Element mA3(TARGET_ARROW3_IMG, gh / 8, gh / 8, 3 * gh / 10 + gh / 4 + ((gw - gh) / 2), gh / 20);
        Element mA4(TARGET_ARROW4_IMG, gh / 8, gh / 8, 4 * gh / 10 + 3 * gh / 8 + ((gw - gh) / 2), gh / 20);

        presets = (Element *)malloc(sizeof(Element) * 4);
        *presets = A1;
        *(presets + 1) = A2;
        *(presets + 2) = A3;
        *(presets + 3) = A4;

        gui = (Element *)malloc(sizeof(Element) * 5);
        *gui = b;
        *(gui + 1) = mA1;
        *(gui + 2) = mA2;
        *(gui + 3) = mA3;
        *(gui + 4) = mA4;
}

Game::~Game()
{
        free(gui);
        free(presets);
        free(arrows);

        al_destroy_bitmap(icon);
        al_destroy_font(fontTitle);
        al_destroy_font(fontText);

        al_destroy_event_queue(queue);
        al_destroy_display(game);
}

void Game::drawGUI()
{
        for (int i = 0; i < 5; i++)
        {
                (gui + i)->draw();
        }
}

bool Game::waitReady()
{
        FILE *f;
        int type;
        long int tread;
        char songname[100];
        Arrow *buff;

        bool loop = true;
        bool ret = true;

        if (arrows != nullptr)
        {
                free(arrows);
        }

        arrows = (ArrowQ *)malloc(sizeof(ArrowQ) * 4);
        ArrowQ r(presets[0].getX()), d(presets[1].getX()), l(presets[2].getX()), u(presets[3].getX());
        *arrows = r;
        *(arrows + 1) = d;
        *(arrows + 2) = l;
        *(arrows + 3) = u;

        ALLEGRO_EVENT inEvent;
        ALLEGRO_TIMER *countdown = al_create_timer(1);
        al_register_event_source(queue, al_get_timer_event_source(countdown));

        al_set_target_backbuffer(game);
        al_clear_to_color(al_map_rgb(255, 255, 255));
        gui->draw();
        al_draw_textf(fontTitle, al_map_rgb(30, 30, 30), (gw - al_get_text_width(fontTitle, "Press ENTER to start")) / 2, (gh - al_get_font_ascent(fontTitle) - al_get_font_descent(fontTitle)) / 2, ALLEGRO_ALIGN_INTEGER, "Press ENTER to start");
        al_flip_display();

        f = fopen((strcmp(lvl, "default") ? lvl : DEFAULT_LVL), "r");
        fscanf(f, "%d%ld%s", &lvlin, &tread, songname);
        tmax = (double)tread / 1000;
        while (!feof(f))
        {
                fscanf(f, "%d%ld", &type, &tread);
                buff = new Arrow((*(presets + type - 1)), (double)tread / 1000);
                arrows[type - 1].push(buff);
                delete (buff);
                cant++;
        }
        fclose(f);
        maxscore = cant * 100;

        music = al_load_audio_stream(songname, 2, 2048);

        do
        {
                al_wait_for_event(queue, &inEvent);
                do
                {
                        switch (inEvent.type)
                        {
                        case ALLEGRO_EVENT_TIMER:
                                if (inEvent.timer.count == 3)
                                {
                                        al_flush_event_queue(queue);
                                        al_stop_timer(countdown);
                                        loop = false;
                                }
                                else
                                {
                                        al_clear_to_color(al_map_rgb(255, 255, 255));
                                        gui->draw();
                                        al_draw_textf(fontTitle, al_map_rgb(30, 30, 30), (gw - al_get_text_width(fontTitle, "2")) / 2, (gh - al_get_font_ascent(fontTitle) - al_get_font_descent(fontTitle)) / 2, ALLEGRO_ALIGN_INTEGER, "%d", 3 - (int)inEvent.timer.count);
                                        al_flip_display();
                                }
                                break;
                        case ALLEGRO_EVENT_KEY_DOWN:
                        case ALLEGRO_EVENT_DANCEPAD_DOWN:
                                switch (inEvent.keyboard.keycode)
                                {
                                case ALLEGRO_KEY_ENTER:
                                        al_start_timer(countdown);
                                        al_clear_to_color(al_map_rgb(255, 255, 255));
                                        gui->draw();
                                        al_draw_textf(fontTitle, al_map_rgb(30, 30, 30), (gw - al_get_text_width(fontTitle, "2")) / 2, (gh - al_get_font_ascent(fontTitle) - al_get_font_descent(fontTitle)) / 2, ALLEGRO_ALIGN_INTEGER, "%d", 3);
                                        al_flip_display();
                                        break;
                                case ALLEGRO_KEY_ESCAPE:
                                        al_flush_event_queue(queue);
                                        loop = false;
                                        gmOn = ret = false;
                                        break;
                                }
                                break;
                        case ALLEGRO_EVENT_DISPLAY_CLOSE:
                                al_flush_event_queue(queue);
                                loop = false;
                                gmOn = ret = false;
                                break;
                        }
                } while (al_get_next_event(queue, &inEvent));
        } while (loop);

        al_destroy_timer(countdown);

        return ret;
}

float Game::gameLoop()
{
        bool loop = true;
        bool held[4] = {false, false, false, false};

        double tlast, tini;
        long int score = 0;

        ALLEGRO_EVENT inEvent;
        ALLEGRO_KEYBOARD_STATE keyboard;

        al_attach_audio_stream_to_mixer(music, al_get_default_mixer());

        al_set_target_backbuffer(game);
        tini = tlast = al_get_time();

        do
        {
                while (al_get_next_event(queue, &inEvent))
                {
                        switch (inEvent.type)
                        {
                        case ALLEGRO_EVENT_KEY_DOWN:
                                if (inEvent.keyboard.display == game)
                                {
                                        al_get_keyboard_state(&keyboard);
                                        if (al_key_down(&keyboard, ALLEGRO_KEY_RIGHT) && !held[0])
                                        {
                                                score += arrows->pop(inEvent.keyboard.timestamp - tini);
                                                held[0] = true;
                                        }
                                        if (al_key_down(&keyboard, ALLEGRO_KEY_DOWN) && !held[1])
                                        {
                                                score += (arrows + 1)->pop(inEvent.keyboard.timestamp - tini);
                                                held[1] = true;
                                        }
                                        if (al_key_down(&keyboard, ALLEGRO_KEY_LEFT) && !held[2])
                                        {
                                                score += (arrows + 2)->pop(inEvent.keyboard.timestamp - tini);
                                                held[2] = true;
                                        }
                                        if (al_key_down(&keyboard, ALLEGRO_KEY_UP) && !held[3])
                                        {
                                                score += (arrows + 3)->pop(inEvent.keyboard.timestamp - tini);
                                                held[3] = true;
                                        }
                                        if (al_key_down(&keyboard, ALLEGRO_KEY_ESCAPE))
                                        {
                                                al_flush_event_queue(queue);
                                                loop = false;
                                                gmOn = (score = 0);
                                                break;
                                        }
                                }
                                break;
                        case ALLEGRO_EVENT_KEY_UP:
                                al_get_keyboard_state(&keyboard);
                                held[0] = al_key_down(&keyboard, ALLEGRO_KEY_RIGHT);
                                held[1] = al_key_down(&keyboard, ALLEGRO_KEY_DOWN);
                                held[2] = al_key_down(&keyboard, ALLEGRO_KEY_LEFT);
                                held[3] = al_key_down(&keyboard, ALLEGRO_KEY_UP);
                                break;
                        case ALLEGRO_EVENT_DANCEPAD_DOWN:
                                switch (inEvent.touch.id)
                                {
                                case ALLEGRO_KEY_RIGHT:
                                        score += arrows->pop(inEvent.touch.x);
                                        printf("%lf\n", inEvent.touch.x);
                                        break;
                                case ALLEGRO_KEY_DOWN:
                                        score += (arrows + 1)->pop(inEvent.touch.x);
                                        printf("%lf\n", inEvent.touch.x);
                                        break;
                                case ALLEGRO_KEY_LEFT:
                                        score += (arrows + 2)->pop(inEvent.touch.x);
                                        printf("%lf\n", inEvent.touch.x);
                                        break;
                                case ALLEGRO_KEY_UP:
                                        score += (arrows + 3)->pop(inEvent.touch.x);
                                        printf("%lf\n", inEvent.touch.x);
                                        break;
                                }
                                break;
                        case ALLEGRO_EVENT_DISPLAY_CLOSE:
                                al_flush_event_queue(queue);
                                loop = false;
                                gmOn = (score = 0);
                                break;
                        }
                }

                tn = al_get_time() - tini;
                if (fr ? (tn - tlast >= 1 / fr) : 1)
                {
                        al_clear_to_color(al_map_rgb(255, 255, 255));
                        drawGUI();

                        (!arrows->isEmpty()) ? (arrows->update(score) ? arrows->draw() : nop()) : nop();
                        (!(arrows + 1)->isEmpty()) ? ((arrows + 1)->update(score) ? (arrows + 1)->draw() : nop()) : nop();
                        (!(arrows + 2)->isEmpty()) ? ((arrows + 2)->update(score) ? (arrows + 2)->draw() : nop()) : nop();
                        (!(arrows + 3)->isEmpty()) ? ((arrows + 3)->update(score) ? (arrows + 3)->draw() : nop()) : nop();

                        if (score < 0)
                                score = 0;

                        if (score + (cant - (arrows->popped + (arrows + 1)->popped + (arrows + 2)->popped + (arrows + 3)->popped)) * 100 < cant * 70)
                        {
                                loop = false;
                                score = 0;
                        }

                        al_draw_textf(fontText, al_map_rgb(30, 30, 30), gh / 20, gh / 20 - al_get_font_ascent(fontText), ALLEGRO_ALIGN_LEFT, "Score: %ld/%ld", score, maxscore);
                        al_draw_textf(fontText, al_map_rgb(30, 30, 30), gh / 20, gh / 10 - al_get_font_ascent(fontText), ALLEGRO_ALIGN_LEFT, "%02d : %02d", (int)(tn / 60), ((int)tn % 60));

                        al_flip_display();
                }
                if (tn >= tmax)
                        loop = false;
                else if (fr)
                        tlast = tn;
        } while (loop);

        al_detach_audio_stream(music);
        al_destroy_audio_stream(music);

        return (float)score / (float)maxscore;
}

void Game::endScreen(float score)
{
        ALLEGRO_EVENT inEvent;
        bool loop = true;

        if (gmOn)
        {
                al_set_target_backbuffer(game);

                al_clear_to_color(al_map_rgb(255, 255, 255));
                gui->draw();
                if (score < 0.7)
                {
                        al_draw_text(fontTitle, al_map_rgb(30, 30, 30), (gw - al_get_text_width(fontTitle, "You Lose!")) / 2, (gh - al_get_font_ascent(fontTitle) - al_get_font_descent(fontTitle)) / 2, ALLEGRO_ALIGN_INTEGER, "You Lose!");
                }
                else
                {
                        al_draw_text(fontTitle, al_map_rgb(30, 30, 30), (gw - al_get_text_width(fontTitle, "You Win!")) / 2, (gh - al_get_font_ascent(fontTitle) - al_get_font_descent(fontTitle)) / 2, ALLEGRO_ALIGN_INTEGER, "You Win!");
                        al_draw_textf(fontText, al_map_rgb(30, 30, 30), (gw - al_get_text_width(fontText, "Score: 99!%")) / 2, 11 * gh / 20, ALLEGRO_ALIGN_INTEGER, "Score: %0.2f%%", score * 100);
                }
                al_flip_display();

                do
                {
                        al_wait_for_event(queue, &inEvent);
                        do
                        {
                                switch (inEvent.type)
                                {
                                case ALLEGRO_EVENT_KEY_DOWN:
                                case ALLEGRO_EVENT_DANCEPAD_DOWN:
                                        switch (inEvent.keyboard.keycode)
                                        {
                                        case ALLEGRO_KEY_ENTER:
                                                al_flush_event_queue(queue);
                                                loop = false;
                                                break;
                                        case ALLEGRO_KEY_ESCAPE:
                                                al_flush_event_queue(queue);
                                                loop = false;
                                                gmOn = false;
                                                break;
                                        }
                                        break;
                                case ALLEGRO_EVENT_DISPLAY_CLOSE:
                                        al_flush_event_queue(queue);
                                        loop = false;
                                        gmOn = false;
                                        break;
                                }
                        } while (al_get_next_event(queue, &inEvent));
                } while (loop);
        }
}