#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <ctime>
#include <iostream>

#include "Cherry.h"
#include "Collectables.h"
#include "Maze.h"
#include "Pacman.h"

// Test drawing cherry
void testCherryDrawing(sf::RenderWindow &window,Cherry cherry) 
{  
    sf::Event event;
    while (window.pollEvent(event)) {
      window.clear();
      cherry.draw(window);
      window.display();
      if (event.type == sf::Event::Closed) {
        window.close();
      }
    }
  std::cout << "Cherry drawing test passed!" << std::endl;
}

// Test texture
void testTexture(Cherry cherry) {
  if (cherry.cherryTexture.loadFromFile("cherry.png")) {
    std::cout << "testTexture cherry passed!" << std::endl;
  } else {
    std::cout << "testTexture cherry failed!" << std::endl;
  }
}

// Test cherry placement
void testCherryPlacement(Cherry cherry, Maze maze) {
  // Check if cherries are placed on the grid
  bool cherryPlaced = false;
  for (int y = 0; y < maze.gridSize; ++y) {
    for (int x = 0; x < maze.gridSize; ++x) {
      if (maze.maze[y][x] == 3) {
        cherryPlaced = true;
        break;
      }
    }
    if (cherryPlaced) break;
  }

  if (cherryPlaced) {
    std::cout << "Test Passed: Cherry placed correctly.\n";
  } else {
    std::cout << "Test Failed: Cherry not placed on the grid.\n";
  }
}

void testCherryPoints(Pacman pacman, Cherry cherry, Maze maze) {
  // Manually place a cherry at a known location
  maze.maze[1][1] = 3;
  pacman.setPosition(sf::Vector2f(1 * cherry.cellSize, 1 * (cherry.cellSize)));

  // Pacman eats the cherry
  int points = cherry.addPoints(pacman);

  if (points == 100 && maze.maze[1][1] == 8) {
    std::cout << "Test Passed: Cherry correctly consumed and points added.\n";
  } else {
    std::cout << "Test Failed: Cherry not consumed correctly.\n";
  }
}

int main() {
  srand(static_cast<unsigned>(time(0)));
  // Initilize Window for testing purpose
  sf::RenderWindow window(sf::VideoMode(800, 600), "Cherry Unit Test");

  // Initialize Pacman object
  Pacman pacman(window, 20);

  // Initialize Maze
  Maze maze(20, 20);

  // Initialize cherry object
  Cherry cherry(20, 800, maze.maze);

  // Test drawing cherry
  testCherryDrawing(window, cherry);

  // Test texture
  testTexture(cherry);

  // Test cherry placement
  testCherryPlacement(cherry, maze);

  // Test cherry points
  testCherryPoints(pacman, cherry, maze);

  return 0;
}
