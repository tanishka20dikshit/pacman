<<<<<<< HEAD
#ifndef CHERRY_H
#define CHERRY_H

#include "Collectables.h"
#include "Cherry.h"
#include "Pacman.h"
#include <SFML/Graphics.hpp>
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
        Cherry(int gs,int width,int ** mz);
        int getGridSize();
        int getCellSize();
        int getPoints();
        int getNumber();
        int** getMaze();
        sf::Texture getTexture();
        virtual void draw(sf::RenderWindow& window);
        int addPoints(Pacman pacman);
        void placeRandomly();
};

=======
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

>>>>>>> abcc5d7128c62abc84e12feeadabe743d0576259
#endif