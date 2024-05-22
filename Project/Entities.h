#ifndef ENTITIES_H
#define ENTITIES_H

#include "Elements.h"
#include "Maze.h"

class Entities : public Elements {
    private:
        int speed;
    public:
        Entities();
        virtual bool move(int direction, Maze maze, float time);
        virtual float getSpeed();
};

#endif