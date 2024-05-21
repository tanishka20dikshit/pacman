#ifndef CHERRY_H
#define CHERRY_H

#include "Collectables.h"
#include "Pacman.h"

class Cherry : public Collectables {
    private:
        int gridSize;
        int cellSize;
        int points = 100;
        int n = 1; // Number of cherries to be placed
        int **maze;
        sf::Texture cherryTexture;

    public:
        Cherry();
        Cherry(int gs, int width, int **mz);
        void draw(sf::RenderWindow& window) override;
        int addPoints(Pacman pacman) override;
        void placeRandomly();
};

#endif