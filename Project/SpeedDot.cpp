#include "SpeedDot.h"
<<<<<<< HEAD
#include <SFML/Graphics.hpp>

// Default constructor
SpeedDot::SpeedDot() : gridSize(0), cellSize(0), maze(nullptr) {}

// Parameterized constructor
SpeedDot::SpeedDot(int gs, int width, int **mz)
    : gridSize(gs), cellSize(width / gridSize), maze(mz) {
    placeRandomly();
}

// Method to place speed dots randomly in the maze
=======
SpeedDot::SpeedDot(){}

SpeedDot::SpeedDot(int gs,int width,int ** mz): gridSize(gs), cellSize(width/gridSize), maze(mz) {
    placeRandomly();
}

>>>>>>> abcc5d7128c62abc84e12feeadabe743d0576259
void SpeedDot::placeRandomly() {
    int count = 0;
    while (count < n) {
        int x = rand() % gridSize;
        int y = rand() % gridSize;
        if (maze[x][y] == 0) {
            maze[x][y] = 2;
            count++;
        }
    }
}

<<<<<<< HEAD
// Draw method for the SpeedDot
void SpeedDot::draw(sf::RenderWindow& window) {
    sf::CircleShape dot((cellSize / 3) * scaleFactor);
=======
void SpeedDot::draw(sf::RenderWindow& window) {
    sf::CircleShape dot((cellSize / 3)*scaleFactor);
>>>>>>> abcc5d7128c62abc84e12feeadabe743d0576259
    dot.setFillColor(sf::Color::White);
    float offset = (cellSize - dot.getRadius() * 2) / 2;
    for (int y = 0; y < gridSize; ++y) {
        for (int x = 0; x < gridSize; ++x) {
            if (maze[y][x] == 2) {
                dot.setPosition(x * cellSize + offset, y * cellSize + offset);
                window.draw(dot);
            }
        }
    }
    if (animationClock.getElapsedTime().asMilliseconds() > 10) {
        if (isScalingDown) {
            scaleFactor -= 0.01f;
            if (scaleFactor <= 0.5f) {
                isScalingDown = false;
            }
        } else {
            scaleFactor += 0.01f;
            if (scaleFactor >= 1.0f) {
<<<<<<< HEAD
                isScalingDown = true;
=======
                isScalingDown = true; 
>>>>>>> abcc5d7128c62abc84e12feeadabe743d0576259
            }
        }
        animationClock.restart();
    }
}

<<<<<<< HEAD
// Method to add points when Pacman eats a SpeedDot
int SpeedDot::addPoints(Pacman &pacman) {
    sf::Vector2f pos = pacman.getPosition();
    int X = pos.x / cellSize;
    int Y = pos.y / cellSize;
    pacman.increaseSpeed(false);
    if (maze[Y][X] == 2) {
=======
int SpeedDot::addPoints(Pacman &pacman){
    sf::Vector2f pos = pacman.getPosition();
    int X = pos.x / (cellSize);
    int Y = pos.y / (cellSize);
    pacman.increaseSpeed(false);
    if(maze[Y][X] == 2){
>>>>>>> abcc5d7128c62abc84e12feeadabe743d0576259
        maze[Y][X] = 8;
        pacman.increaseSpeed(true);
        return points;
    }
    return 0;
<<<<<<< HEAD
}

// Getter methods
int SpeedDot::getGridSize() const {
    return gridSize;
}

int SpeedDot::getCellSize() const {
    return cellSize;
}

int SpeedDot::getPoints() const {
    return points;
}

int SpeedDot::getNumberOfDots() const {
    return n;
}

float SpeedDot::getScaleFactor() const {
    return scaleFactor;
}

bool SpeedDot::getIsScalingDown() const {
    return isScalingDown;
}
=======
};
>>>>>>> abcc5d7128c62abc84e12feeadabe743d0576259
