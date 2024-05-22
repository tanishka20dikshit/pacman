#ifndef MAZE_H
#define MAZE_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include <fstream>
#include "Elements.h"

class Maze : public Elements {
    private:
        int gridSize;
        int cellSize;
        int **maze;
        sf::Texture right_corner;
        sf::Texture left_corner;
        sf::Texture b_right_corner;
        sf::Texture b_left_corner;
        sf::Texture top_line;
        sf::Texture left_line;

    public:
        Maze();
        Maze(int gs, int width);
        void draw(sf::RenderWindow& window) override;
        void reset();
        bool isWall(int x, int y);
        void setupMaze();
        int **getMaze();
        int getGridSize() const;
        int getCellSize() const;
        sf::Texture getRightCorner() const;
        sf::Texture getLeftCorner() const;
        sf::Texture getBottomRightCorner() const;
        sf::Texture getBottomLeftCorner() const;
        sf::Texture getTopLine() const;
        sf::Texture getLeftLine() const;
};

#endif