#include <SFML/Graphics.hpp>
#include <iostream>
const int gridSize = 20;

// Define the maze layout using a 2D array
int maze[gridSize][gridSize] = {
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 1, 1, 0, 0, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1},
    {1, 0, 1, 1, 1, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1},
    {1, 0, 1, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 1, 1, 0, 1, 0, 1},
    {1, 0, 1, 0, 1, 1, 0, 0, 0, 1, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1},
    {1, 0, 1, 0, 1, 0, 1, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1},
    {1, 0, 1, 0, 1, 0, 0, 1, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1},
    {1, 0, 1, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1},
    {1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1},
    {1, 0, 1, 0, 1, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1},
    {1, 0, 1, 0, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1},
    {1, 0, 1, 0, 1, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1},
    {1, 0, 1, 0, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1},
    {1, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1},
    {1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
};

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
    sf::RenderWindow window(sf::VideoMode(800, 800), "Pacman");
    sf::Texture pacmanTexture;
    if (!pacmanTexture.loadFromFile("pacman.png")) {
        return 1;
    }

    sf::Sprite pacman(pacmanTexture);
    pacman.setOrigin(pacmanTexture.getSize().x / 2, pacmanTexture.getSize().y / 2);
    pacman.setPosition(window.getSize().x / 2, window.getSize().y / 2);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed){
                window.close();
            }
        }
        bool movingleft = false;
        bool movingtop = false;
        bool movingright = false;
        bool movingbottom = false;
        sf::Vector2f movement(0.0f, 0.0f);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            movement.x = -0.1f;
            pacman.setRotation(180.0f);
            movingleft = true;
        }else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            movement.x = 0.1f;
            pacman.setRotation(0.0f);
            movingright = true;
        }else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
            movement.y = -0.1f;
            pacman.setRotation(-90.0f);
            movingtop = true;
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
            movement.y = 0.1f;
            pacman.setRotation(90.0f);
            movingbottom = true;
        }

        const float cellSizeX = window.getSize().x / gridSize;
        const float cellSizeY = window.getSize().y / gridSize;

        sf::Vector2f newPos = pacman.getPosition() + movement;
        int newX = newPos.x / (cellSizeX);
        int newY = newPos.y / (cellSizeY);

        if (newX >= 0 && newX < window.getSize().x / gridSize &&
            newY >= 0 && newY < window.getSize().y / gridSize &&
            newPos.x >= 0 && newPos.x < window.getSize().x &&
            newPos.y >= 0 && newPos.y < window.getSize().y) {
            if(maze[newY][newX] == 0){
                sf::Vector2f pos(newPos.x,newPos.y);
                if(movingright){
                    pos = sf::Vector2f(newPos.x,newY*40+20);
                }else if(movingleft){
                    pos = sf::Vector2f(newPos.x,newY*40+20);
                }else if(movingtop){
                    pos = sf::Vector2f(newX*40+20,newPos.y);
                }else{
                    pos = sf::Vector2f(newX*40+20,newPos.y);
                }
                pacman.setPosition(pos);
            }
            std::cout << "Pacman's current grid position: (" << newX << ", " << newY << ")" << std::endl;
        }
        window.clear();
       
        
        pacman.setScale(cellSizeX / pacman.getLocalBounds().width, cellSizeY / pacman.getLocalBounds().height);
        drawMaze(window, maze, 40);
        window.draw(pacman);
        //drawGrid(window,cellSizeX); Used to debug
        window.display();
    }
    return 0;
}
