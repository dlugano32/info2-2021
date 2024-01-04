#include "arrow.h"

ArrowQ::Node *ArrowQ::Node::lost;

Arrow::Arrow(Element &cpy, double time)
{
        setBitmap(al_clone_bitmap(cpy.getBitmap()));
        setW(cpy.getW());
        setH(cpy.getH());
        setX(cpy.getX());
        setY(cpy.getY());

        setT(time);
        setV(true);
}

Arrow::Arrow(Arrow &cpy) : Arrow((Element &)cpy, cpy.getT())
{
}

ArrowQ::Node::Node(Arrow *in, Node *next)
{
        d = new Arrow(*in);
        n = next;
}

ArrowQ::Node::~Node()
{
        delete (d);
        lost = n;
}

ArrowQ::ArrowQ(float xin)
{
        start = nullptr;
        end = nullptr;
        sx = xin;
        sy = gh / 20;
        sh = sw = gh / 8;
        popped = 0;
}

ArrowQ::~ArrowQ()
{
        Node *aux;

        while (start != nullptr)
        {
                aux = start->n;
                free(start);
                start = aux;
        }
}

bool ArrowQ::update(long int &score, Node *point)
{
        bool ret = true;

        if (point == nullptr)
                point = start;

        if (point != nullptr)
        {
                if (point->d->getT() - tn < -(dif * 0.3))
                {
                        score += pop((int)0);
                        if (Node::lost != nullptr)
                                ret = update(score, Node::lost);
                }
                else
                {
                        while (point != nullptr)
                        {
                                if ((point->d->getT() - tn) >= (dif * 1.5))
                                {
                                        if (point == start)
                                                ret = false;
                                        point = nullptr;
                                }
                                else if ((point->d->getT() - tn) >= (double)0)
                                {
                                        point->d->setY((float)(gh * (point->d->getT() - tn) / (dif * 1.5) + sy));
                                        point = point->n;
                                }
                                else
                                {
                                        point->d->setX((float)(gh / 16 * (point->d->getT() - tn) / -(dif * 0.3) + sx));
                                        point->d->setY((float)(gh / 16 * (point->d->getT() - tn) / -(dif * 0.3) + sy));
                                        point->d->setW((int)(sw * (1 + (point->d->getT() - tn) / (dif * 0.3))));
                                        point->d->setH((int)(sh * (1 + (point->d->getT() - tn) / (dif * 0.3))));
                                        point = point->n;
                                }
                        }
                }
        }
        else
        {
                ret = false;
        }

        return ret;
}

void ArrowQ::draw()
{
        Node *point = start;

        while (point != nullptr)
        {
                al_draw_scaled_bitmap(point->d->getBitmap(), 0, 0, sw, sh, point->d->getX(), point->d->getY(), point->d->getW(), point->d->getH(), 0);
                point = point->n;
        }
}

void ArrowQ::push(Arrow *in)
{
        if (start == nullptr)
        {
                start = new Node(in, nullptr);
                end = start;
        }
        else
        {
                end->n = new Node(in, nullptr);
                end = end->n;
        }
}

void ArrowQ::pop(Arrow *ret)
{
        if (start == nullptr)
        {
                ret = nullptr;
        }
        else if (ret == nullptr)
        {
                delete (start);
                start = Node::lost;
                popped++;
        }
        else
        {
                *ret = *(start->d);
                delete (start);
                start = Node::lost;
                popped++;
        }
}

int ArrowQ::pop(double tp)
{
        int ret;

        if (start == nullptr || (start->d->getT() - tp) >= (dif * 0.3) || (start->d->getT() - tp) <= -(dif * 0.3))
                ret = -20;
        else
        {
                if ((start->d->getT() - tp) <= (dif * 0.2) && (start->d->getT() - tp) >= -(dif * 0.2))
                        if ((start->d->getT() - tp) <= (dif * 0.1) && (start->d->getT() - tp) >= -(dif * 0.1))
                                if ((start->d->getT() - tp) <= (dif * 0.05) && (start->d->getT() - tp) >= -(dif * 0.05))
                                        /*if ((start->d->getT() - tp) <= 0.0005 && (start->d->getT() - tp) >= -0.0005)
                                                ret = 500;
                                        else*/
                                        ret = 100;
                                else
                                        ret = 50;
                        else
                                ret = 20;
                else
                        ret = 0;

                this->pop();
        }

        return ret;
}

int ArrowQ::pop(int)
{
        this->pop();
        return -20;
}