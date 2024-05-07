#include <SFML/Graphics.hpp>
#include <iostream>
#include "Elements.cpp"
#include "Maze.cpp"
#include "Entities.cpp"
#include "Pacman.cpp"
#include "Ghost.cpp"

class Game {
    private:
        int points = 0;
        int lives = 1;
        bool isAlive;
        int width;
        int height;
        sf::RenderWindow window;
        Maze maze;
        Pacman player;
        Ghost* ghosts[3];
        int direction; // 0 left,1 right,2 up,3 down,4 none
    public:
        Game(int h, int w) :
            height(h),
            width(w),
            window(sf::VideoMode(800, 800), "Pacman"),
            maze(20, width),
            player(window, 20)
        {
            player.setPosition(sf::Vector2f(60, 60));
            ghosts[0] = new Ghost(window, 20, 60, 60);
            ghosts[1] = new Ghost(window, 20, 720, 720);
            ghosts[2] = new Ghost(window, 20, 140, 140);
        }
        void run() {
            while (window.isOpen()) {
                sf::Event event;
                while (window.pollEvent(event)) {
                    if (event.type == sf::Event::Closed) {
                        window.close();
                    }
                }
                handlingKeys();
                if (!player.move(direction, maze)) {
                    direction = 4;
                }
                for (int i = 0; i < 3; ++i) {
                    ghosts[i]->move(0, maze);
                }
                window.clear();
                maze.draw(window);
                for (int i = 0; i < 3; ++i) {
                    ghosts[i]->draw(window);
                }
                player.draw(window);
                window.display();
            }
        }

        void handlingKeys() {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
                direction = 0;
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
                direction = 1;
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
                direction = 2;
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
                direction = 3;
            }
        }

        void render() {}
};