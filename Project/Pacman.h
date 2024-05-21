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
