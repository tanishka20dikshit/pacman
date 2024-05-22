#ifndef SPEEDDOT_H
#define SPEEDDOT_H

#include <SFML/Graphics.hpp>
#include <cstdlib>
#include "Collectables.h"
#include "Pacman.h"

class SpeedDot : public Collectables {
    private:
        int gridSize;
        int cellSize;
        int points = 50;
        int n = 3;
        int **maze;
        float scaleFactor = 1.0f;
        bool isScalingDown = false;
        sf::Clock animationClock;
    public:
        SpeedDot();
        SpeedDot(int gs, int width, int **mz);
        void placeRandomly();
        void draw(sf::RenderWindow& window) override;
        int addPoints(Pacman &pacman);
        int getGridSize() const;
        int getCellSize() const;
        int getPoints() const;
        int getN() const;
        int** getMaze() const;
        float getScaleFactor() const;
        bool getIsScalingDown() const;
        sf::Clock getAnimationClock() const;
};

#endif