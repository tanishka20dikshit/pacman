#include "Cherry.h"

// Default constructor for the Cherry class
Cherry::Cherry() {}

// Parameterized constructor for the Cherry class
// Initializes gridSize, cellSize, and maze
// Attempts to load the cherry texture and places the cherry randomly in the maze
Cherry::Cherry(int gs, int width, int** mz) 
    : gridSize(gs), cellSize(width / gridSize), maze(mz) {
    // Load the texture for the cherry
    if (!cherryTexture.loadFromFile("images/cherry.png")) {
        std::cerr << "Error: Failed to load cherry texture file." << std::endl;
    } else {
        // Place the cherry randomly in the maze
        placeRandomly();
    }
}

// Draws the cherry on the given window
void Cherry::draw(sf::RenderWindow& window) {
    sf::RectangleShape cherry(sf::Vector2f(cellSize, cellSize));
    cherry.setFillColor(sf::Color::White);
    cherry.setTexture(&cherryTexture);

    // Iterate over each cell in the grid
    for (int y = 0; y < gridSize; ++y) {
        for (int x = 0; x < gridSize; ++x) {
            // If the cell contains a cherry (indicated by the value 3)
            if (maze[y][x] == 3) {
                // Set the position of the cherry and draw it
                cherry.setPosition(x * cellSize, y * cellSize);
                window.draw(cherry);
            }
        }
    }
}

// Adds points if Pacman eats a cherry and places a new cherry randomly
int Cherry::addPoints(Pacman pacman) {
    // Get Pacman's position
    sf::Vector2f pos = pacman.getPosition();
    int X = pos.x / cellSize;
    int Y = pos.y / cellSize;

    // Check if Pacman is on a cherry cell
    if (maze[Y][X] == 3) {
        // Mark the cell as empty (or eaten) and place a new cherry
        maze[Y][X] = 8;
        placeRandomly();
        // Return the points for eating a cherry
        return points;
    }
    // Return 0 points if no cherry was eaten
    return 0;
}

// Places cherries randomly in the maze
void Cherry::placeRandomly() {
    int count = 0;
    while (count < n) {
        // Generate random coordinates
        int x = rand() % gridSize;
        int y = rand() % gridSize;
        // Place a cherry if the cell is empty (value 0) or previously eaten (value 8)
        if (maze[x][y] == 0 || maze[x][y] == 8) {
            maze[x][y] = 3;
            count++;
        }
    }
}

// Getters for various private member variables
int Cherry::getGridSize() const {
    return gridSize;
}

int Cherry::getCellSize() const {
    return cellSize;
}

int Cherry::getPoints() const {
    return points;
}

int Cherry::getN() const {
    return n;
}

int** Cherry::getMaze() const {
    return maze;
}

sf::Texture Cherry::getCherryTexture() const {
    return cherryTexture;
}
