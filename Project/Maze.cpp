#include "Maze.h"
Maze::Maze(){}

Maze::Maze(int gs, int width) : gridSize(gs), cellSize(width / gridSize) {
    if (!right_corner.loadFromFile("images/right-corner.png") ||
        !left_corner.loadFromFile("images/left-corner.png") ||
        !b_left_corner.loadFromFile("images/bottom-left-corner.png") ||
        !b_right_corner.loadFromFile("images/bottom-right-corner.png") ||
        !top_line.loadFromFile("images/top-line.png") ||
        !left_line.loadFromFile("images/left-line.png")) {
        std::cerr << "Error: Failed to load one or more maze texture files." << std::endl;
    } else {
        top_line.setSmooth(true);
        left_line.setSmooth(true);
        maze = new int*[gridSize];
        for (int i = 0; i < gridSize; ++i) {
            maze[i] = new int[gridSize];
        }
        setupMaze();
    }
}

void Maze::draw(sf::RenderWindow& window) {
    sf::RectangleShape shape(sf::Vector2f(cellSize, cellSize));
    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < gridSize; j++) {
            shape.setPosition(j * cellSize, i * cellSize);
            if (maze[i][j] == 1) {
                bool up = (i > 0 && maze[i-1][j] == 1);
                bool down = (i < gridSize - 1 && maze[i+1][j] == 1);
                bool left = (j > 0 && maze[i][j-1] == 1);
                bool right = (j < gridSize - 1 && maze[i][j+1] == 1);
                bool upLeft = (i > 0 && j > 0 && maze[i-1][j-1] == 1);
                bool upRight = (i > 0 && j < gridSize - 1 && maze[i-1][j+1] == 1);
                bool downLeft = (i < gridSize - 1 && j > 0 && maze[i+1][j-1] == 1);
                bool downRight = (i < gridSize - 1 && j < gridSize - 1 && maze[i+1][j+1] == 1);
                if(right && down && !downRight){
                    shape.setTexture(&left_corner);
                }else if(left && down && !downLeft){
                    shape.setTexture(&right_corner);
                }else if(up && left && !upLeft){
                    shape.setTexture(&b_right_corner);
                }else if(up && right && !upRight){
                    shape.setTexture(&b_left_corner);
                }else if(up && down){
                    shape.setTexture(&left_line);
                }else if(left && right){
                    shape.setTexture(&top_line);
                }
                else{
                    shape.setTexture(nullptr);
                    if(!right && left){
                        shape.setPosition((j * cellSize)-cellSize/2, i * cellSize);
                        shape.setTexture(&top_line);
                    }else if(up && !down){
                        shape.setPosition((j * cellSize), (i * cellSize)-cellSize/2);
                        shape.setTexture(&left_line);
                    }else if(!left && right){
                        shape.setPosition((j * cellSize)+cellSize/2, i * cellSize);
                        shape.setTexture(&top_line);
                    }
                }
                if(up && left && upLeft && !right && !down){
                    shape.setTexture(&b_right_corner);
                    shape.setPosition(j * cellSize, i * cellSize);
                }
                if(up && right && upRight && !left && !down){
                    shape.setTexture(&b_left_corner);
                    shape.setPosition(j * cellSize, i * cellSize);
                }
                if(down && right && downRight && !left && !up){
                    shape.setTexture(&left_corner);
                    shape.setPosition(j * cellSize, i * cellSize);
                }
                if(down && left && downLeft && !right && !up){
                    shape.setTexture(&right_corner);
                    shape.setPosition(j * cellSize, i * cellSize);
                }
                if(up && down && left && right){
                    shape.setTexture(nullptr);
                }
                if (shape.getTexture() != nullptr){
                    window.draw(shape);
                }
            }
        }
    }
}

void Maze::reset(){
    setupMaze();
}

bool Maze::isWall(int x,int y){
    return !(maze[y][x] != 1);
}

void Maze::setupMaze(){
    std::ifstream file { "maze.txt" };
    int layout[gridSize][gridSize];
    for (int i{}; i != gridSize; ++i) {
        for (int j{}; j != gridSize; ++j) {
            file >> layout[i][j];
            maze[i][j] = layout[i][j];
        }
    }
}

int **Maze::getMaze(){
    return maze;
}

int Maze::getGridSize() const {
    return gridSize;
}

int Maze::getCellSize() const {
    return cellSize;
}

sf::Texture Maze::getRightCorner() const {
    return right_corner;
}

sf::Texture Maze::getLeftCorner() const {
    return left_corner;
}

sf::Texture Maze::getBottomRightCorner() const {
    return b_right_corner;
}

sf::Texture Maze::getBottomLeftCorner() const {
    return b_left_corner;
}

sf::Texture Maze::getTopLine() const {
    return top_line;
}

sf::Texture Maze::getLeftLine() const {
    return left_line;
}