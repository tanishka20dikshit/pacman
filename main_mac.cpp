#include <SFML/Graphics.hpp>
#include <iostream>
#include "maze.cpp"

void drawMaze(sf::RenderWindow &window, const int maze[gridSize][gridSize], int cellSize) {
    sf::RectangleShape wall(sf::Vector2f(cellSize, cellSize));
    wall.setFillColor(sf::Color::Blue);
    for (int y = 0; y < gridSize; ++y) {
        for (int x = 0; x < gridSize; ++x) {
            if (maze[y][x] == 1) {
                wall.setPosition(x * cellSize, y * cellSize);
                window.draw(wall);
            }
        }
    }
}

void drawPellets(sf::RenderWindow &window, const int maze[gridSize][gridSize], int cellSize) {
    sf::CircleShape dot(cellSize / 8);
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

void drawSpeedthingy(sf::RenderWindow &window, const int maze[gridSize][gridSize], int cellSize) {
    sf::CircleShape dot(cellSize / 4);
    dot.setFillColor(sf::Color::White);
    float offset = (cellSize - dot.getRadius() * 2) / 2;
    for (int y = 0; y < gridSize; ++y) {
        for (int x = 0; x < gridSize; ++x) {
            if (maze[y][x] == 2) {
                dot.setPosition(x * cellSize + offset, y * cellSize + offset);
                window.draw(dot);
            }
        }
    }
}

void drawGrid(sf::RenderWindow &window,int cellSize){
    for (int i = 0; i <= gridSize; ++i){
        sf::Vertex line[] = {
            sf::Vertex(sf::Vector2f(0, i * cellSize)),
            sf::Vertex(sf::Vector2f(window.getSize().x, i * cellSize))
        };
        window.draw(line, 2, sf::Lines);
    }

    for (int i = 0; i <= gridSize; ++i){
        sf::Vertex line[] = {
            sf::Vertex(sf::Vector2f(i * cellSize, 0)),
            sf::Vertex(sf::Vector2f(i * cellSize, window.getSize().y))
        };
        window.draw(line, 2, sf::Lines);
    }
}

int main() {
    sf::RenderWindow window(sf::VideoMode(600, 600), "Pacman");

    const float cellSize = window.getSize().x / gridSize;

    sf::Texture pacmanTexture;
    if (!pacmanTexture.loadFromFile("pacman.png")) {
        return 1;
    }

    sf::Sprite pacman(pacmanTexture);
    pacman.setOrigin(pacmanTexture.getSize().x / 2, pacmanTexture.getSize().y / 2);
    pacman.setPosition(window.getSize().x / 2, window.getSize().y / 2);
    pacman.setScale(cellSize / pacman.getLocalBounds().width, cellSize / pacman.getLocalBounds().height);

    bool movingleft = false;
    bool movingtop = false;
    bool movingright = false;
    bool movingbottom = false;
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed){
                window.close();
            }
        }
        sf::Vector2f movement(0.0f, 0.0f);
        
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            movingleft = true;
            movingtop = false;
            movingright = false;
            movingbottom = false;
        }else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            movingleft = false;
            movingtop = false;
            movingright = true;
            movingbottom = false;
        }else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
            movingleft = false;
            movingtop = true;
            movingright = false;
            movingbottom = false;
        }else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
            movingleft = false;
            movingtop = false;
            movingright = false;
            movingbottom = true;
        }

        if (movingleft) {
            movement.x = -0.1f;
            pacman.setRotation(180.0f);
        }else if (movingright) {
            movement.x = 0.1f;
            pacman.setRotation(0.0f);
        }else if (movingtop) {
            movement.y = -0.1f;
            pacman.setRotation(-90.0f);
        }
        else if (movingbottom) {
            movement.y = 0.1f;
            pacman.setRotation(90.0f);
        }

        sf::Vector2f newPos = pacman.getPosition() + movement;
        int newX = newPos.x / (cellSize);
        int newY = newPos.y / (cellSize);
        if(maze[newY][newX] != 1){
            sf::Vector2f pos(newPos.x,newPos.y);
            if(movingright || movingleft){
                pos = sf::Vector2f(newPos.x,newY*cellSize+(cellSize/2));
            }else if(movingtop || movingbottom){
                pos = sf::Vector2f(newX*cellSize+(cellSize/2),newPos.y);
            }else{
                pos = sf::Vector2f(newX*cellSize+(cellSize/2),newY*cellSize+(cellSize/2));
            }
            onCollect(newY,newX);
            pacman.setPosition(pos);
        }
        window.clear();
        drawPellets(window,maze,cellSize);
        drawSpeedthingy(window,maze,cellSize);
        window.draw(pacman);
        drawMaze(window, maze, cellSize);
        drawGrid(window,cellSize);
        window.display();
    }
    return 0;
}
