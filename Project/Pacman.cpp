#include "Pacman.h"
#include <SFML/Graphics.hpp>
#include <iostream>
// Default constructor
Pacman::Pacman() {}

// Parameterized constructor
Pacman::Pacman(sf::RenderWindow& window, int gs) : gridSize(gs) {
    cellSize = window.getSize().x / gridSize;
    if(!pacmanTexture.loadFromFile("images/pacman.png") )
     {std::cout << "ERROR::GAME::TEXTURE::Failed to texture!" << "\n";
  };
    if(!pacmanfTexture.loadFromFile("images/pacman-full.png"))
    {
    std::cout << "ERROR::GAME::TEXTURE::Failed to texture!" << "\n";

    };
    pacman.setTexture(pacmanTexture);
    pacman.setOrigin(pacmanTexture.getSize().x / 2, pacmanTexture.getSize().y / 2);
    pacman.setPosition(window.getSize().x / 2, window.getSize().y / 2);
    pacman.setScale(cellSize / pacman.getLocalBounds().width, cellSize / pacman.getLocalBounds().height);
}

// Draw the Pacman
void Pacman::draw(sf::RenderWindow& window) {
    if (clk.getElapsedTime().asSeconds() > 0.2f) {
        changed = !changed;
        pacman.setTexture(changed ? pacmanfTexture : pacmanTexture);
        clk.restart();
    }
    window.draw(pacman);
}

// Move Pacman
bool Pacman::move(int direction, Maze maze, float time) {
    sf::Vector2f movement(0.0f, 0.0f);
    float fSpeed = time * speed * (boost ? 2.0f : 1.0f);
    if (direction == 0) {
        movement.x = -fSpeed;
        pacman.setRotation(180.0f);
    } else if (direction == 1) {
        movement.x = fSpeed;
        pacman.setRotation(0.0f);
    } else if (direction == 2) {
        movement.y = -fSpeed;
        pacman.setRotation(-90.0f);
    } else if (direction == 3) {
        movement.y = fSpeed;
        pacman.setRotation(90.0f);
    }
    sf::Vector2f newPos = pacman.getPosition() + movement;
    int X = newPos.x / (cellSize);
    int Y = newPos.y / (cellSize);
    sf::Vector2f pos(newPos.x, newPos.y);
    if (!maze.isWall(X, Y)) {
        if (direction == 0 || direction == 1) {
            pos = sf::Vector2f(newPos.x, Y * cellSize + (cellSize / 2));
        } else if (direction == 2 || direction == 3) {
            pos = sf::Vector2f(X * cellSize + (cellSize / 2), newPos.y);
        } else {
            pos = sf::Vector2f(X * cellSize + (cellSize / 2), Y * cellSize + (cellSize / 2));
        }
        pacman.setPosition(pos);
    } else {
        return false;
    }
    return true;
}

// Set Pacman's position
void Pacman::setPosition(const sf::Vector2f& newPos) {
    pacman.setPosition(newPos);
}

// Get Pacman's position
sf::Vector2f Pacman::getPosition() const {
    return pacman.getPosition();
}

// Get Pacman's speed
float Pacman::getSpeed() {
    return speed;
}

// Increase Pacman's speed
void Pacman::increaseSpeed(bool toggle) {
    if (toggle) {
        clock.restart();
        boost = true;
    } else if (boost) {
        float seconds = clock.getElapsedTime().asSeconds();
        if (seconds > 5) {
            boost = false;
        }
    }
}

// Getters for additional attributes
sf::Texture Pacman::getPacmanTexture() const {
    return pacmanTexture;
}

sf::Texture Pacman::getPacmanfTexture() const {
    return pacmanfTexture;
}

sf::Sprite Pacman::getPacmanSprite() const {
    return pacman;
}

int Pacman::getCellSize() const {
    return cellSize;
}

int Pacman::getGridSize() const {
    return gridSize;
}

bool Pacman::isBoosted() const {
    return boost;
}

bool Pacman::isChanged() const {
    return changed;
}
