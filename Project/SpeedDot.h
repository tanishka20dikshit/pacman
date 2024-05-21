#ifndef SPEEDDOT_H
#define SPEEDDOT_H

#include <SFML/Graphics.hpp>
#include <cstdlib>
#include "Collectables.h"  // Assuming Collectables is defined elsewhere
#include "Pacman.h"        // Assuming Pacman is defined elsewhere

class SpeedDot : public Collectables {
private:
    int gridSize;
    int cellSize;
    int points = 50;
    int n = 3;  // Number of speed dots to be placed
    int **maze;
    float scaleFactor = 1.0f;
    bool isScalingDown = false;
    sf::Clock animationClock;

public:
    SpeedDot();
    SpeedDot(int gs, int width, int **mz);

    virtual void draw(sf::RenderWindow& window) override;
    int addPoints(Pacman &pacman);
    void placeRandomly();
    
    // Getter functions
    int getGridSize() const;
    int getCellSize() const;
    int getPoints() const;
    int getNumberOfDots() const;
    float getScaleFactor() const;
    bool getIsScalingDown() const;
};

#endif // SPEEDDOT_H
