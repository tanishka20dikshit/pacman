#include "Pacman.h"
Pacman::Pacman(){}

Pacman::Pacman(sf::RenderWindow& window, int gs) : gridSize(gs) {
    cellSize = window.getSize().x / gridSize;
    if (!pacmanTexture.loadFromFile("images/pacman.png") || !pacmanfTexture.loadFromFile("images/pacman-full.png")) {
        std::cerr << "Error: Failed to load one or more pacman texture files." << std::endl;
    } else {
        pacman.setTexture(pacmanTexture);
        pacman.setOrigin(pacmanTexture.getSize().x / 2, pacmanTexture.getSize().y / 2);
        pacman.setPosition(window.getSize().x / 2, window.getSize().y / 2);
        pacman.setScale(cellSize / pacman.getLocalBounds().width, cellSize / pacman.getLocalBounds().height);
    }
}

void Pacman::draw(sf::RenderWindow& window) {
    if(clk.getElapsedTime().asSeconds() > 0.2f) {
        changed = !changed;
        pacman.setTexture(changed ? pacmanfTexture : pacmanTexture);
        clk.restart();
    } 
    window.draw(pacman);
}

bool Pacman::move(int direction,Maze maze,float time) {
    sf::Vector2f movement(0.0f, 0.0f);
    float fSpeed = time * speed *(boost ? 2.0f : 1.0f);
    if (direction == 0) {
        movement.x = -fSpeed;
        pacman.setRotation(180.0f);
    }else if (direction == 1) {
        movement.x = fSpeed;
        pacman.setRotation(0.0f);
    }else if (direction == 2) {
        movement.y = -fSpeed;
        pacman.setRotation(-90.0f);
    }
    else if (direction == 3) {
        movement.y = fSpeed;
        pacman.setRotation(90.0f);
    }
    sf::Vector2f newPos = pacman.getPosition() + movement;
    int X = newPos.x / (cellSize);
    int Y = newPos.y / (cellSize);
    sf::Vector2f pos(newPos.x,newPos.y);
    if(!maze.isWall(X,Y)){
        if(direction == 0 || direction == 1){
            pos = sf::Vector2f(newPos.x,Y*cellSize+(cellSize/2));
        }else if(direction == 2 || direction == 3){
            pos = sf::Vector2f(X*cellSize+(cellSize/2),newPos.y);
        }else{
            pos = sf::Vector2f(X*cellSize+(cellSize/2),Y*cellSize+(cellSize/2));
        }
        pacman.setPosition(pos);
    }else{
        return false;
    }
    return true;
}

void Pacman::setPosition(const sf::Vector2f& newPos) {
    pacman.setPosition(newPos);
}

sf::Vector2f Pacman::getPosition() const {
    return pacman.getPosition();
}

float Pacman::getSpeed(){
    return speed;
}

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

sf::Texture Pacman::getPacmanTexture() const {
    return pacmanTexture;
}

sf::Texture Pacman::getPacmanfTexture() const {
    return pacmanfTexture;
}

sf::Sprite Pacman::getPacman() const {
    return pacman;
}

sf::Clock Pacman::getClock() const {
    return clock;
}

sf::Clock Pacman::getClk() const {
    return clk;
}

int Pacman::getCellSize() const {
    return cellSize;
}

int Pacman::getGridSize() const {
    return gridSize;
}

bool Pacman::getBoost() const {
    return boost;
}

bool Pacman::getChanged() const {
    return changed;
}