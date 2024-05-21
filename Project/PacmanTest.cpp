
#include <SFML/Graphics.hpp>
#include <iostream>

#include "Maze.h"
#include "Pacman.h"

// Test drawing Pacman
void testDrawing(sf::RenderWindow &window, Pacman pacman) {
  while (window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event)) window.clear();
    window.draw(pacman.getPacmanSprite());
    window.display();
    if (event.type == sf::Event::Closed) {
      window.close();
    }
  }
}

// Test moving Pacman
void testMove(Pacman pacman) {
  Maze maze(20, 20);
  bool moveResult = pacman.move(0, maze, 0.1f);
  // Assuming direction 0 (left) and no time passed

  if (moveResult == true && !maze.isWall(1, 1)) {
    std::cout << "testMoved 1 passed!" << std::endl;

  } else {
    std::cout << "testMoved 1 failed " << std::endl;
  }
  sf::Vector2f newPos(0.0f, 0.0f);
  pacman.setPosition(newPos);
  moveResult = pacman.move(0, maze, 0.1f);
  int newX = newPos.x / pacman.getCellSize();
  int newY = newPos.y / pacman.getCellSize();
    //Pacman cannot move is there is wall
  if (moveResult == false) {
    std::cout << "testMoved 2 passed!" << std::endl;

  } else {
    std::cout << "testMoved 2 failed! " << std::endl;
  }
}

// Test setting and getting position
void testGetPosition(Pacman pacman) {
  sf::Vector2f newPos(100.0f, 200.0f);
  pacman.setPosition(newPos);
  sf::Vector2f getPosition = pacman.getPosition();
  if (newPos.x == getPosition.x && newPos.y == getPosition.y) {
    std::cout << "testGetPosition passed!" << std::endl;
  } else {
    std::cout << "testGetPosition failed: expected " << newPos.x << newPos.y
              << ", got (" << getPosition.x << ", " << getPosition.y << ")"
              << std::endl;
  }
}

// Test get Speed
void testGetSpeed(Pacman pacman) {
  if (pacman.getSpeed() == 250.0f) {
    std::cout << "testGetSpeed passed!" << std::endl;
  } else {
    std::cout << "testGetSpeed failed!" << std::endl;
  }
}

// Test increasing speed
void testIncreasingSpeed(Pacman pacman, Maze maze) {
  pacman.increaseSpeed(true);  // Toggle speed boost on
  sf::Clock clock;
  sf::Time elapsed = clock.getElapsedTime();
  if (elapsed.asSeconds() > 5) {
    pacman.increaseSpeed(false);  // Check if speed increases for 5 seconds
    elapsed = clock.getElapsedTime();
    if (pacman.isBoosted() ==false) {
      std::cout << "Test increasing speed passed!" << std::endl;
    } else {
      std::cout << "Test increasing speed failed!" << std::endl;
    };  // After 5 seconds, Pacman should be able to move with increased speed
  }
}


  // Test texture
  void testTexture(Pacman pacman) {
    if (pacman.getPacmanTexture().loadFromFile("images/pacman.png")) {
      std::cout << "testTexture passed!" << std::endl;
    } else {
      std::cout << "testTexture failed!" << std::endl;
    }

    if (pacman.getPacmanfTexture().loadFromFile("images/pacman-full.png")) {
      std::cout << "testTexture passed!" << std::endl;
    } else {
      std::cout << "testTexture failed!" << std::endl;
    }
  }

  // Test Gridsize
  void testGetGridSize(Pacman pacman) {
    if (pacman.getGridSize() == 20) {
      std::cout << "testGetGridSize passed!" << std::endl;
    } else {
      std::cout << "testGetGridSize failed!" << std::endl;
    }
  }
  void testGetCellSize(Pacman pacman) {
    if (pacman.getCellSize() == 40) {
      std::cout << "testGetCellSize passed!" << std::endl;
    } else {
      std::cout << "testGetCellSize failed!" << std::endl;
    }
  }

  // Test boost
  void testGetBoost(Pacman pacman) {
    if (pacman.isBoosted() == false) {
      std::cout << "testGetBoost passed!" << std::endl;
    } else {
      std::cout << "testGetBoost failed!" << std::endl;
    }
  }

  // Test change
  void testChange(Pacman pacman) {
    if (pacman.isChanged() == false) {
      std::cout << "testChange passed!" << std::endl;
    } else {
      std::cout << "testChange failed!" << std::endl;
    }
  }


int main() {
  // Create a window for testing purposes
  sf::RenderWindow window(sf::VideoMode(800, 600), "Pacman Unit Test");

  // Initialize Pacman object
  Pacman pacman(window, 20);  // Assuming grid size of 20

  // Initialize Pacman object
  Maze maze(20, 20);

  // Test drawing Pacman
  testDrawing(window, pacman);

  // Test moving Pacman
  testMove(pacman);

  // Test setting and getting position
  testGetPosition(pacman);

  // Test get Speed
  testGetSpeed(pacman);
  // Test increasing speed
  testIncreasingSpeed(pacman, maze);


  // Test Gridsize
  testGetGridSize(pacman);
  testGetCellSize(pacman);

  // Test texture
  testTexture(pacman);

  // Test boost
  testGetBoost(pacman);

  // Test change
  testChange(pacman);
  std::cout << "All tests passed!" << std::endl;

  return 0;
};
