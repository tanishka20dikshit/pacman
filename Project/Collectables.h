#ifndef COLLECTABLES_H
#define COLLECTABLES_H
#include "Elements.h"
#include <SFML/Graphics.hpp>
class Collectables : public Elements{
    protected:
        int points;
    public:
        Collectables();
        virtual void addPoints(int points);
};

#endif