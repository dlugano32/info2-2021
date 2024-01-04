#ifndef ARROW
#define ARROW

#include "element.h"

class Arrow : public Element
{
private:
public:
        Arrow(Element &, double = 0);
        Arrow(Arrow &);
};

class ArrowQ
{
private:
        class Node
        {
        public:
                Arrow *d;
                Node *n;

                static Node *lost;

                Node(Arrow *, Node *);
                ~Node();
        };

        Node *start;
        Node *end;
        float sx, sy;
        int sw, sh;

public:
        ArrowQ(float);
        ~ArrowQ();

        unsigned int popped;

        inline bool isEmpty() const { return (start == nullptr) ? true : false; };
        bool update(long int &, Node * = nullptr);
        void draw();

        void push(Arrow *);
        void pop(Arrow * = nullptr);
        int pop(double);
        int pop(int);
};

#endif
