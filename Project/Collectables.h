#ifndef COLLECTABLES_H
#define COLLECTABLES_H

#include "Elements.h"
#include "Pacman.h"

class Collectables : public Elements {
    private:
        int points;

    public:
        Collectables();
        virtual int addPoints(Pacman pacman);
};

#endif