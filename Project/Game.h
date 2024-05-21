<<<<<<< HEAD
#ifndef GAME_H
#define GAME_H
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Cherry.h"
#include "Collectables.h"
#include "Elements.h"
#include "Entities.h"
#include "Ghost.h"
#include "Maze.h"
#include "Pacman.h"
#include "Pellets.h"
#include "SpeedDot.h"

class Game {
    private:
        sf::RenderWindow window;
        sf::Font font;
        sf::Text score, livesText, title, playText, highScoreText;
        sf::SoundBuffer buffer, buffer_ready, buffer_die; 
        sf::Sound siren, sound_ready, sound_die;
        sf::Clock clock, clock_die;
        int width,height;
        int highScore = 0;
        int points = 0;
        int lives = 3;
        int direction = 0; // 0 left,1 right,2 up,3 down,4 none
        bool isAlive = false;
        bool canGameStart = false;
        bool isDying = false;
        Maze maze;
        Pacman player;
        Ghost* ghosts[4];
        Pellets pellets;
        SpeedDot speedDot;
        Cherry cherry;
    public:
        Game(int h, int w);
        sf::Font getFont();
        sf::Text getScore();
        sf::Text getLivesText();
        sf::Text getTitle();
        sf::Text getPlayText();
        sf::Text getHighScoreText();
        int getWidth();
        int getHeight();
        int getHighScore();
        int getPoints ();
        int getLives ();
        int getDirection (); 
        bool getIsAlive ();
        bool getCanGameStart();
        bool getIsDying();
        void run();
        void handleKeys();
        void handleClicks();
        void render();

        void resetGame();

        ~Game();
};
=======
#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <chrono>
#include <fstream>
#include <string>
#include "Maze.h"
#include "Pacman.h"
#include "Ghost.h"
#include "Pellets.h"
#include "SpeedDot.h"
#include "Cherry.h"

class Game {
    private:
        sf::RenderWindow window;
        sf::Font font;
        sf::Text score, livesText, title, playText, highScoreText;
        sf::SoundBuffer buffer, buffer_ready, buffer_die; 
        sf::Sound siren, sound_ready, sound_die;
        sf::Clock clock, clock_die;
        int width, height;
        int highScore = 0;
        int points = 0;
        int lives = 3;
        int direction = 0; // 0 left, 1 right, 2 up, 3 down, 4 none
        bool isAlive = false;
        bool canGameStart = false;
        bool isDying = false;
        Maze maze;
        Pacman player;
        Ghost* ghosts[4];
        Pellets pellets;
        SpeedDot speedDot;
        Cherry cherry;

    public:
        Game(int h, int w);
        void run();
        void handleKeys();
        void handleClicks();
        void render();
        void resetGame();
        ~Game();
};

>>>>>>> abcc5d7128c62abc84e12feeadabe743d0576259
#endif