<<<<<<< HEAD
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

=======
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

>>>>>>> abcc5d7128c62abc84e12feeadabe743d0576259
#endif