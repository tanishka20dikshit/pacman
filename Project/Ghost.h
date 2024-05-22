#ifndef GHOST_H
#define GHOST_H

#include <SFML/Graphics.hpp>
#include "Entities.h"
#include "Maze.h"
#include "Pacman.h"
#include <iostream>

class Ghost : public Entities {
    private:
        int change = 0;
        int cellSize;
        int gridSize;
        float speed = 250.0f;
        sf::Texture ghostTexture;
        sf::Sprite ghost;

    public:
        Ghost();
        Ghost(sf::RenderWindow& window, int gs, int x, int y, std::string color);
        void draw(sf::RenderWindow& window) override;
        bool move(int direction, Maze maze, float time) override;
        void setPosition(const sf::Vector2f& newPos) override;
        sf::Vector2f getPosition() const override;
        sf::Vector2f getMovement(int change, float fSpeed);
        float getSpeed();
        bool checkDeath(Pacman p);
        int getChange() const;
        int getCellSize() const;
        int getGridSize() const;
        sf::Texture getGhostTexture() const;
        sf::Sprite getGhost() const;
};

#endif