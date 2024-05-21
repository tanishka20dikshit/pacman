#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <ctime>
#include <iostream>

#include "Collectables.h"  // Ensure this file defines the Collectables class.
#include "Entities.h"      // Ensure this file defines any dependencies.
#include "Maze.h"
#include "Pacman.h"  // Ensure this file defines the Pacman class with relevant methods.
#include "SpeedDot.h"
// Test drawing speed dot
void testSpeedDotDrawing(sf::RenderWindow &window, SpeedDot speedDot) {
  while (window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event)) {
      window.clear();
      speedDot.draw(window);
      window.display();
      if (event.type == sf::Event::Closed) {
        window.close();
      }
    }
  }
  std::cout << "Speed Dot drawing test passed!" << std::endl;
};

void testInitializationAndPlacement(SpeedDot speeddot, Maze maze) {
  std::cout << "Test Initialization and Placement\n";
  int dotCount = 0;
  for (int y = 0; y < maze.getGridSize(); ++y) {
    for (int x = 0; x < maze.getGridSize(); ++x) {
      if (maze.getMaze()[y][x] == 2) {
        dotCount++;
      }
    }
  }
  if (dotCount == speeddot.getNumberOfDots()) {
    std::cout << "Passed: Correct number of SpeedDots placed.\n";
  } else {
    std::cout << "Failed: Incorrect number of SpeedDots placed (" << dotCount
              << ").\n";
  }
}

void testAddPoints(SpeedDot speedDot, Maze maze, Pacman pacman) {
  std::cout << "Test addPoints Method\n";

  pacman.setPosition(sf::Vector2f(0, 0));

  // Manually place a SpeedDot at Pacman's initial position
  maze.getMaze()[0][0] = 2;

  int points = speedDot.addPoints(pacman);
  if (points == speedDot.getPoints()) {
    std::cout << "Passed: Pacman collected SpeedDot and received points.\n";
  } else {
    std::cout << "Failed: Pacman did not collect SpeedDot correctly (" << points
              << " points).\n";
  }

  if (maze.getMaze()[0][0] == 8) {
    std::cout << "Passed: SpeedDot removed from maze after collection.\n";
  } else {
    std::cout << "Failed: SpeedDot not removed from maze after collection.\n";
  }
};

// Test get grid size
void testGetGridSize(SpeedDot speedDot) {
  if (speedDot.getGridSize() == 20) {
    std::cout << "testGetGridSize passed!" << std::endl;
  } else {
    std::cout << "testGetGridSize failed!" << std::endl;
  }
}

// Test get cell size
void testGetCellSize(SpeedDot speedDot) {
  if (speedDot.getCellSize() == 40) {
    std::cout << "testGetCellSize passed!" << std::endl;
  } else {
    std::cout << "testGetCellSize failed!" << std::endl;
  }
}

// Test get points
void testGetPoints(SpeedDot speedDot) {
  if (speedDot.getPoints() == 50) {
    std::cout << "testGetPoints passed!" << std::endl;
  } else {
    std::cout << "testGetPoints failed!" << std::endl;
  }
}

// Test get Number Of Dots
void testgetNumberOfDots(SpeedDot speedDot) {
  if (speedDot.getNumberOfDots() == 3) {
    std::cout << "testGetNumberOfDots passed!" << std::endl;
  } else {
    std::cout << "testGetNumberOfDots failed!" << std::endl;
  }
}

// Test get Scale Factor
void testGetScaleFactor(SpeedDot speedDot) {
  if (speedDot.getScaleFactor() == 1.0f) {
    std::cout << "testGetScaleFactor passed!" << std::endl;
  } else {
    std::cout << "testGetScaleFactor failed!" << std::endl;
  }
}

// Test get is scaling down
void testGetIsScalingDown(SpeedDot speedDot) {
  if (speedDot.getIsScalingDown() == false) {
    std::cout << "testGetSpeed passed!" << std::endl;
  } else {
    std::cout << "testGetSpeed failed!" << std::endl;
  }
}

int main() {
  srand(static_cast<unsigned>(time(0)));  // Seed random number generator
  // Initilize Window for testing purpose
  sf::RenderWindow window(sf::VideoMode(800, 600), "Speed Dot Unit Test");

  // Initialize Pacman object
  Pacman pacman(window, 20);

  // Initialize Maze
  Maze maze(20, 20);

  // Initialize speed dot object
  SpeedDot speedDot(20, 800, maze.getMaze());

  // Test drawing speed dot
  testSpeedDotDrawing(window, speedDot);

  // Test Initialization And Placement
  testInitializationAndPlacement(speedDot, maze);

  // Test Add Points
  testAddPoints(speedDot, maze, pacman);

  // Test get grid size
  testGetGridSize(speedDot);
  // Test get cell size
  testGetCellSize(speedDot);

  // Test get points
  testGetPoints(speedDot);

  // Test get Number Of Dots
  testgetNumberOfDots(speedDot);

  // Test get Scale Factor
  testGetScaleFactor(speedDot);

  // Test get is scaling down
  testGetIsScalingDown(speedDot);
  return 0;
}
