#include <SFML/Graphics.hpp>
#include <random>
#include <iostream>
#include "Cherry.h"
#include "Collectables.h"

Cherry::Cherry() {}
Cherry::Cherry(int gs, int width, int** mz)
    : gridSize(gs), cellSize(width / gridSize), maze(mz) {
      this->cherryTexture.loadFromFile("images/cherry.png");
  Cherry::placeRandomly();
}
int Cherry::getGridSize() { return gridSize; }
int Cherry::getCellSize() { return cellSize; };
int Cherry::getPoints() { return points; }
int Cherry::getNumber() { return n; }
int** Cherry::getMaze() { return maze; }
sf::Texture Cherry::getTexture() { return cherryTexture; }

 void Cherry::draw(sf::RenderWindow& window) {
  sf::RectangleShape cherry(sf::Vector2f(cellSize, cellSize));
    cherry.setFillColor(sf::Color::White);
  cherry.setTexture(&cherryTexture);
  for (int y = 0; y < gridSize; ++y) {
    for (int x = 0; x < gridSize; ++x) {
      if (maze[y][x] == 3) {
        cherry.setPosition(x * cellSize, y * cellSize);
        window.draw(cherry);
      }
    }
  }
}

int Cherry::addPoints(Pacman pacman) {
  sf::Vector2f pos = pacman.getPosition();
  int X = pos.x / (cellSize);
  int Y = pos.y / (cellSize);
  if (maze[Y][X] == 3) {
    maze[Y][X] = 8;
    placeRandomly();
    return points;
  }
  return 0;
};

void Cherry::placeRandomly() {
  int count = 0;
  while (count < n) {
    int x = rand() % gridSize;
    int y = rand() % gridSize;
    if (maze[x][y] == 0 || maze[x][y] == 8) {
      maze[x][y] = 3;
      count++;
    }
  }
};
