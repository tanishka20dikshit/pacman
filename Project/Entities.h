<<<<<<< HEAD

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

=======
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

>>>>>>> abcc5d7128c62abc84e12feeadabe743d0576259
#endif