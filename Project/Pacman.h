#ifndef PACMAN_H
#define PACMAN_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include "Entities.h"
#include "Maze.h"

class Pacman : public Entities {
    private:
        sf::Texture pacmanTexture;
        sf::Texture pacmanfTexture;
        sf::Sprite pacman;
        sf::Clock clock;
        sf::Clock clk;
        int cellSize;
        int gridSize;
        float speed = 250.0f;
        bool boost = false;
        bool changed = false;

    public:
        Pacman();
        Pacman(sf::RenderWindow& window, int gs);
        void draw(sf::RenderWindow& window) override;
        bool move(int direction, Maze maze, float time) override;
        void setPosition(const sf::Vector2f& newPos) override;
        sf::Vector2f getPosition() const override;
        float getSpeed() const ;
        void increaseSpeed(bool toggle);
        sf::Texture getPacmanTexture() const;
        sf::Texture getPacmanfTexture() const;
        sf::Sprite getPacman() const;
        sf::Clock getClock() const;
        sf::Clock getClk() const;
        int getCellSize() const;
        int getGridSize() const;
        bool getBoost() const;
        bool getChanged() const;
};

#endif