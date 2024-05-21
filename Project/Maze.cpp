#include "Maze.h"

#include <SFML/Graphics.hpp>
#include <fstream>
#include <iostream>

#include "Elements.h"

Maze::Maze(){};
Maze::Maze(int gs, int width) : gridSize(gs), cellSize(width / gridSize) {
  this->right_corner.loadFromFile("images/right-corner.png");
  this->left_corner.loadFromFile("images/left-corner.png");
  this->b_left_corner.loadFromFile("images/bottom-left-corner.png");
  this->b_right_corner.loadFromFile("images/bottom-right-corner.png");
  this->top_line.loadFromFile("images/top-line.png");
  this->left_line.loadFromFile("images/left-line.png");
  this->top_line.setSmooth(true);
  this->left_line.setSmooth(true);
  this->maze = new int*[gridSize];
  for (int i = 0; i < gridSize; ++i) {
    this->maze[i] = new int[gridSize];
  }
  Maze::setupMaze();
}
int Maze::getGridSize() { return this->gridSize; };
int Maze::getCellSize() { return this->cellSize; };
int** Maze::getMaze() { return this->maze; };
sf::Texture Maze::getRightCornerTexture() { return this->right_corner; };
sf::Texture Maze::getLeftCornerTexture() { return this->left_corner; };
sf::Texture Maze::getBottomRightCornerTexture() {return this->b_right_corner;};
sf::Texture Maze::getBottomLeftCornerTexture() { return this->b_left_corner; };
sf::Texture Maze::getTopLineCornerTexture() { return this->top_line; };
sf::Texture Maze::getLeftLineCornerTexture() { return this->left_line; };
void Maze::draw(sf::RenderWindow& window) {
  sf::RectangleShape shape(sf::Vector2f(cellSize, cellSize));
  for (int i = 0; i < gridSize; i++) {
    for (int j = 0; j < gridSize; j++) {
      shape.setPosition(j * cellSize, i * cellSize);
      if (maze[i][j] == 1) {
        bool up = (i > 0 && maze[i - 1][j] == 1);
        bool down = (i < gridSize - 1 && maze[i + 1][j] == 1);
        bool left = (j > 0 && maze[i][j - 1] == 1);
        bool right = (j < gridSize - 1 && maze[i][j + 1] == 1);
        bool upLeft = (i > 0 && j > 0 && maze[i - 1][j - 1] == 1);
        bool upRight = (i > 0 && j < gridSize - 1 && maze[i - 1][j + 1] == 1);
        bool downLeft = (i < gridSize - 1 && j > 0 && maze[i + 1][j - 1] == 1);
        bool downRight =
            (i < gridSize - 1 && j < gridSize - 1 && maze[i + 1][j + 1] == 1);
        if (right && down && !downRight) {
          shape.setTexture(&left_corner);
        } else if (left && down && !downLeft) {
          shape.setTexture(&right_corner);
        } else if (up && left && !upLeft) {
          shape.setTexture(&b_right_corner);
        } else if (up && right && !upRight) {
          shape.setTexture(&b_left_corner);
        } else if (up && down) {
          shape.setTexture(&left_line);
        } else if (left && right) {
          shape.setTexture(&top_line);
        } else {
          shape.setTexture(nullptr);
          if (!right && left) {
            shape.setPosition((j * cellSize) - cellSize / 2, i * cellSize);
            shape.setTexture(&top_line);
          } else if (up && !down) {
            shape.setPosition((j * cellSize), (i * cellSize) - cellSize / 2);
            shape.setTexture(&left_line);
          } else if (!left && right) {
            shape.setPosition((j * cellSize) + cellSize / 2, i * cellSize);
            shape.setTexture(&top_line);
          }
        }

        if (up && left && upLeft && !right && !down) {
          shape.setTexture(&b_right_corner);
          shape.setPosition(j * cellSize, i * cellSize);
        }
        if (up && right && upRight && !left && !down) {
          shape.setTexture(&b_left_corner);
          shape.setPosition(j * cellSize, i * cellSize);
        }
        if (down && right && downRight && !left && !up) {
          shape.setTexture(&left_corner);
          shape.setPosition(j * cellSize, i * cellSize);
        }
        if (down && left && downLeft && !right && !up) {
          shape.setTexture(&right_corner);
          shape.setPosition(j * cellSize, i * cellSize);
        }
        if (up && down && left && right) {
          shape.setTexture(nullptr);
        }
        if (shape.getTexture() != nullptr) {
          window.draw(shape);
        }
      }
    }
  }
}
void Maze::reset() { setupMaze(); }
bool Maze::isWall(int x, int y) { return !(maze[y][x] != 1); }

void Maze::setupMaze() {
  std::ifstream file{"maze.txt"};
  int layout[gridSize][gridSize];
  for (int i{}; i != gridSize; ++i) {
    for (int j{}; j != gridSize; ++j) {
      file >> layout[i][j];
      maze[i][j] = layout[i][j];
    }
  }
}
