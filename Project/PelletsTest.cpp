#include <SFML/Graphics.hpp>
#include <iostream>

#include "Collectables.h"
#include "Entities.h"
#include "Maze.h"
#include "Pacman.h"  // Assuming Pacman has getPosition() method
#include "Pellets.h"

// Test drawing speed dot
void testPelletsDrawing(sf::RenderWindow &window, Pellets pellets) {
  while (window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event)) {
      window.clear();
      pellets.draw(window);
      window.display();
      if (event.type == sf::Event::Closed) {
        window.close();
      }
    }
  }
  std::cout << "Speed Dot drawing test passed!" << std::endl;
};

void testAddPoints(Pellets pellets, Maze maze, Pacman pacman) {
  // addPoints method with Pacman at a position containing a pellet
  pacman.setPosition(sf::Vector2f(40.0f, 40.0f));
  int points = pellets.addPoints(pacman);
  if (points == 10) {
    std::cout << "Test addPoints 1 passed: Pacman collected Pellets and "
                 "received points.\n";
  } else {
    std::cout
        << "Test addPoints 1 failed: Pacman did not collect Pellets correctly ("
        << points << " points).\n";
  }
  // Test case 3: remove pellets method after Pacman eating
  points = pellets.addPoints(pacman);
  if (points == 0) {
    std::cout << "Test addPoints 2 passed: Pellets removed from maze after "
                 "collection.\n";
  } else {
    std::cout << "Test addPoints 2 failed: Pellets not removed from maze after "
                 "collection.\n";
  }

  // Test case 3: addPoints method with Pacman at a position without a pellet
  pacman.setPosition(
      sf::Vector2f(200.0f, 100.0f));   // Pacman at (200, 200), which should
                                       // initially contain a pellet
  pellets.addPoints(pacman);           // Pacman eats the pellet
  points = pellets.addPoints(pacman);  // Pacman tries to eat again
  if (points != 0) {
    std::cerr << "Test add points 3 failed: Points should be 0 when there is "
                 "no pellet."
              << std::endl;
  } else {
    std::cout << "Test add points 3 passed: Pacman gains no point" << std::endl;
  }
};

// Test get grid size
void testGetGridSize(Pellets pellets) {
  if (pellets.getGridSize() == 20) {
    std::cout << "testGetGridSize passed!" << std::endl;
  } else {
    std::cout << "testGetGridSize failed!" << std::endl;
  }
}

// Test get cell size
void testGetCellSize(Pellets pellets) {
  if (pellets.getCellSize() == 40) {
    std::cout << "testGetCellSize passed!" << std::endl;
  } else {
    std::cout << "testGetCellSize failed!" << std::endl;
  }
}

// Test get points
void testGetPoints(Pellets pellets) {
  if (pellets.getPoints() == 10) {
    std::cout << "testGetPoints passed!" << std::endl;
  } else {
    std::cout << "testGetPoints failed!" << std::endl;
  }
}

// Unit test
int main() {
  srand(
      static_cast<unsigned>(time(0)));  // Seed random number generator
                                        // Initilize Window for testing purpose
  sf::RenderWindow window(sf::VideoMode(800, 600), "Speed Dot Unit Test");

  // Initialize Pacman object
  Pacman pacman(window, 20);

  // Initialize Maze
  Maze maze(20, 20);

  // Initialize speed dot object
  Pellets pellets(20, 800, maze.getMaze());

  // Test drawing speed dot
  testPelletsDrawing(window, pellets);

  // Test Add Points
  testAddPoints(pellets, maze, pacman);

  // Test get grid size
  testGetGridSize(pellets);

  // Test get cell size
  testGetCellSize(pellets);

  // Test get points
  testGetPoints(pellets);

  return 0;
}