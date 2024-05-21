<<<<<<< HEAD
#ifndef PACMAN_H
#define PACMAN_H
#include "Entities.h"
#include <SFML/Graphics.hpp>
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

        virtual void draw(sf::RenderWindow& window);
        virtual bool move(int direction, Maze maze, float time) override;
        virtual void setPosition(const sf::Vector2f& newPos);
        virtual sf::Vector2f getPosition() const;
        virtual float getSpeed() override;
        void increaseSpeed(bool toggle);

        // Getters for private attributes
        sf::Texture getPacmanTexture() const;
        sf::Texture getPacmanfTexture() const;
        sf::Sprite getPacmanSprite() const;
        int getCellSize() const;
        int getGridSize() const;
        bool isBoosted() const;
        bool isChanged() const;
};

#endif
=======
#ifndef PACMAN_H
#define PACMAN_H

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
        float getSpeed();
        void increaseSpeed(bool toggle);
};

#endif
>>>>>>> abcc5d7128c62abc84e12feeadabe743d0576259
