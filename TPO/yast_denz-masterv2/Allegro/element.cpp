#include "element.h"

Element::Element(const char *path, int win, int hin, float xin, float yin, double time)
{
        ALLEGRO_BITMAP *aux = al_load_bitmap(path);

        image = al_create_bitmap(win, hin);
        al_set_target_bitmap(image);
        al_clear_to_color(al_map_rgba(0, 0, 0, 0));
        al_draw_scaled_bitmap(aux, 0, 0, al_get_bitmap_width(aux), al_get_bitmap_height(aux), 0, 0, win, hin, 0);
        al_destroy_bitmap(aux);

        w = win;
        h = hin;
        x = xin;
        y = yin;
        timestamp = time;
        visible = true;
}

Element::~Element()
{
        al_destroy_bitmap(image);
}

void Element::draw() const
{
        al_draw_bitmap(image, x, y, 0);
}

void Element::draw(float xin, float yin) const
{
        al_draw_bitmap(image, xin, yin, 0);
}

void Element::draw(float xin, float yin, int win, int hin) const
{
        al_draw_scaled_bitmap(image, 0, 0, w, h, xin, yin, win, hin, 0);
}

void Element::operator=(Element &cpy)
{
        image = al_clone_bitmap(cpy.image);

        w = cpy.w;
        h = cpy.h;
        x = cpy.x;
        y = cpy.y;
        timestamp = cpy.timestamp;
        visible = cpy.visible;
}