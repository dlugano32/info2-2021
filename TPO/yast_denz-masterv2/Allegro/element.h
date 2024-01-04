#ifndef ELEMENT
#define ELEMENT

#include "allegro.h"

class Element
{
private:
        ALLEGRO_BITMAP *image;
        int w, h;
        float x, y;
        double timestamp;
        bool visible;

public:
        inline Element(){};
        Element(const char *, int, int, float = 0, float = 0, double = 0);
        ~Element();

        inline ALLEGRO_BITMAP *getBitmap() const { return image; };
        inline int getW() const { return w; };
        inline int getH() const { return h; };
        inline float getX() const { return x; };
        inline float getY() const { return y; };
        inline double getT() const { return timestamp; };
        inline bool getV() const { return visible; };

        inline void setBitmap(ALLEGRO_BITMAP *in) { image = in; };
        inline void setW(int in) { w = in; };
        inline void setH(int in) { h = in; };
        inline void setX(float in) { x = in; };
        inline void setY(float in) { y = in; };
        inline void setT(double in) { timestamp = in; };
        inline void setV(bool in) { visible = in; };

        void draw() const;
        void draw(float, float) const;
        void draw(float, float, int, int) const;

        void operator=(Element &);
};

#endif
