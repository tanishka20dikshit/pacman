<<<<<<< HEAD

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
        int** maze;
        sf::SoundBuffer buffer;
        sf::Sound sound;
    public:
        Pellets();
        Pellets(int gs, int width, int** mz);
        virtual void draw(sf::RenderWindow& window) override;
        int addPoints(Pacman pacman);
        
        // Getter functions
        int getGridSize() const;
        int getCellSize() const;
        int getPoints() const;
        int** getMaze() const;
        sf::SoundBuffer& getBuffer();
        sf::Sound& getSound();
};

#endif // PELLETS_H
=======
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
};

#endif
>>>>>>> abcc5d7128c62abc84e12feeadabe743d0576259
