#include <SFML/Graphics.hpp>
#include <iostream>

#include "Cherry.h"
#include "Collectables.h"
#include "Maze.h"
#include "Pellets.h"
#include "SpeedDot.h"
void testCollectablesAddPoints(Pacman pacman, Cherry cherry, SpeedDot speedDot,
                               Pellets pellets, Maze maze) {
  // Test add cherry points
  //  Manually place a cherry at a known location
  maze.getMaze()[0][0] = 3;
  pacman.setPosition(sf::Vector2f(0, 0));
  if (cherry.addPoints(pacman) != 100) {
    std::cerr << "testCollectablesAddPoints Cherry failed. " << std::endl;
  } else {
    std::cout << "testCollectablesAddPoints Cherry  passed." << std::endl;
  }

  // Test add speed dot points
  pacman.setPosition(sf::Vector2f(0, 0));
  maze.getMaze()[0][0] = 2;
  if (speedDot.addPoints(pacman) != 50) {
    std::cerr << "testCollectablesAddPoints Speed dot failed. " << std::endl;
  } else {
    std::cout << "testCollectablesAddPoints Speed dot  passed." << std::endl;
  }

  // Test add pellets points
  pacman.setPosition(sf::Vector2f(0, 0));
  maze.getMaze()[0][0] = 0;
  if (pellets.addPoints(pacman) != 10) {
    std::cerr << "testCollectablesAddPoints Pellets failed. " << std::endl;
  } else {
    std::cout << "testCollectablesAddPoints Pellets  passed." << std::endl;
  }
}

int main() {
  // Initilize Window for testing purpose
  sf::RenderWindow window(sf::VideoMode(800, 800), "Cherry Unit Test");

  // Initialize Maze
  Maze maze(20, 20);

  // Initialize Pacman
  Pacman pacman(window, 20);

  // Initialize collectable object
  Cherry cherry(20, 800, maze.getMaze());
  SpeedDot speedDot(20, 800, maze.getMaze());
  Pellets pellets(20, 800, maze.getMaze());

  testCollectablesAddPoints(pacman, cherry, speedDot, pellets, maze);
  return 0;
}
