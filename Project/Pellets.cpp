#include "Pellets.h"
Pellets::Pellets(){}
        
Pellets::Pellets(int gs,int width,int ** mz) : gridSize(gs), cellSize(width/gridSize), maze(mz) {
    buffer.loadFromFile("sounds/sound_eating.mp3");
    sound.setBuffer(buffer);
}
void Pellets::draw(sf::RenderWindow& window) {
    sf::CircleShape dot(cellSize / 12);
    dot.setFillColor(sf::Color::White);
    float offset = (cellSize - dot.getRadius() * 2) / 2;
    for (int y = 0; y < gridSize; ++y) {
        for (int x = 0; x < gridSize; ++x) {
            if (maze[y][x] == 0) {
                dot.setPosition(x * cellSize + offset, y * cellSize + offset);
                window.draw(dot);
            }
        }
    }
}

int Pellets::addPoints(Pacman pacman){
    sf::Vector2f pos = pacman.getPosition();
    int X = pos.x / (cellSize);
    int Y = pos.y / (cellSize);
    if(maze[Y][X] == 0){
        maze[Y][X] = 8;
        if(sound.getStatus() != sf::Sound::Status::Playing){
            sound.play();
        }
        return points;
    }
    return 0;
};

int Pellets::getGridSize() const {
    return gridSize;
}

int Pellets::getCellSize() const {
    return cellSize;
}

int Pellets::getPoints() const {
    return points;
}

int** Pellets::getMaze() const {
    return maze;
}

sf::SoundBuffer Pellets::getBuffer() const {
    return buffer;
}

sf::Sound Pellets::getSound() const {
    return sound;
}