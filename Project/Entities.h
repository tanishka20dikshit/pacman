
#ifndef ENTITIES_H
#define ENTITIES_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Elements.h"
#include "Maze.h"

class Entities : public Elements{
    protected:
        int speed;
    public:
        Entities();
        virtual bool move(int direction,Maze maze,float time);
        virtual float getSpeed();
};

#endif