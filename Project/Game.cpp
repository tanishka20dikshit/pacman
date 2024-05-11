#include <SFML/Graphics.hpp>
#include <iostream>
#include "Elements.cpp"
#include "Maze.cpp"
#include "Entities.cpp"
#include "Pacman.cpp"
#include "Ghost.cpp"
#include "Collectables.cpp"
#include "Pellets.cpp"
#include "SpeedDot.cpp"
#include "Cherry.cpp"
class Game {
    private:
        int points = 0;
        int lives = 1;
        bool isAlive = false;
        int width;
        int height;
        sf::RenderWindow window;
        Maze maze;
        Pacman player;
        Ghost* ghosts[4];
        Pellets pellets;
        SpeedDot speedDot;
        Cherry cherry;
        int direction; // 0 left,1 right,2 up,3 down,4 none
        sf::Font font;
        sf::Text score;
        sf::Text title;
        sf::Text playText;
    public:
        Game(int h, int w) :
            height(h),
            width(w),
            window(sf::VideoMode(w,h), "Pacman"),
            maze(20, width),
            player(window, 20),
            pellets(20,width,maze.maze),
            speedDot(20,width,maze.maze),
            cherry(20,width,maze.maze)
        {
            player.setPosition(sf::Vector2f(60, 60));
            ghosts[0] = new Ghost(window, 20, 180, 60,"red");
            ghosts[1] = new Ghost(window, 20, 720, 720,"blue");
            ghosts[2] = new Ghost(window, 20, 140, 140,"green");
            ghosts[3] = new Ghost(window, 20, 480, 400,"yellow");
            font.loadFromFile("CrackMan.TTF");
            score.setFont(font);
            score.setCharacterSize(20);
            score.setFillColor(sf::Color::Yellow);
            score.setStyle(sf::Text::Bold);
            score.setPosition(30,330);

            /// Start Screen
            title = sf::Text ("PACMAN", font, 100);
            title.setFillColor(sf::Color::Yellow);
            sf::FloatRect titleBounds = title.getLocalBounds();
            title.setOrigin(titleBounds.left + titleBounds.width / 2.0f, titleBounds.top + titleBounds.height / 2.0f);
            title.setPosition(window.getSize().x / 2.0f, 200);

            playText = sf::Text ("PLAY GAME", font, 30);
            playText.setFillColor(sf::Color::White);
            sf::FloatRect textBounds = playText.getLocalBounds();
            playText.setOrigin(textBounds.left + textBounds.width / 2.0f, textBounds.top + textBounds.height / 2.0f);
            playText.setPosition(window.getSize().x / 2.0f, 500);
        }
        void run() {
            while (window.isOpen()) {
                sf::Event event;
                while (window.pollEvent(event)) {
                    if (event.type == sf::Event::Closed) {
                        window.close();
                    }
                }
                if (event.type == sf::Event::MouseButtonPressed && !isAlive) {
                    if (event.mouseButton.button == sf::Mouse::Left) {
                        if (playText.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
                            isAlive = true; 
                        }
                    }
                }
                handlingKeys();
                if(isAlive){
                    if (!player.move(direction, maze)) {
                        direction = 4;
                    }
                    for (int i = 0; i < 4; ++i) {
                        ghosts[i]->move(0, maze);
                        if (ghosts[i]->checkDeath(player)){
                            isAlive = false; 
                        };
                    }
                }
                points += pellets.addPoints(player);
                points += speedDot.addPoints(player);
                points += cherry.addPoints(player);
                score.setString("P* " + std::to_string(points));
                render();
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

        void render() {
            if(!isAlive){
                window.clear(sf::Color::Black); 
                window.draw(title);
                window.draw(playText);
            }else{
                window.clear();
                maze.draw(window);
                for (int i = 0; i < 4; ++i) {
                    ghosts[i]->draw(window);
                }
                pellets.draw(window);
                speedDot.draw(window);
                cherry.draw(window);
                player.draw(window);
                window.draw(score);
            }
            window.display();
        }
};