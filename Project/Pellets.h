#ifndef PELLETS_H
#define PELLETS_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Collectables.h"
#include "Pacman.h"

class Pellets : public Collectables {
    private:
        int gridSize;
        int cellSize;
        int points = 10;
        int **maze;
        sf::SoundBuffer buffer;
        sf::Sound sound;

    public:
        Pellets();
        Pellets(int gs, int width, int **mz);
        void draw(sf::RenderWindow& window) override;
        int addPoints(Pacman pacman);
        int getGridSize() const;
        int getCellSize() const;
        int getPoints() const;
        int** getMaze() const;
        sf::SoundBuffer getBuffer() const;
        sf::Sound getSound() const;
};

#endif