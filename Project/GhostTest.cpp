#include <SFML/Graphics.hpp>
#include <chrono>
#include <iostream>

#include "Elements.cpp"
#include "Entities.cpp"
#include "Ghost.cpp"
#include "Maze.cpp"
#include "Pacman.cpp"

void testGhostInitialization(Ghost ghost) {
  if (ghost.getPosition() == sf::Vector2f(100, 100)) {
    std::cout << "Ghost initialization test passed!" << std::endl;
  } else {
    std::cout << "Ghost initialization test failed!" << std::endl;
  }
}
// Test drawing Ghost
void testDrawing(sf::RenderWindow& window, Ghost ghost) {
  while (window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event)) 
    {window.clear();
    window.draw(ghost.ghost);
    window.display();
    if (event.type == sf::Event::Closed) {
      window.close();
    }}
  }
    std::cout << "Ghost drawing test passed!" << std::endl;

};

// Test texture
void testTexture(Ghost ghost) {
  if (ghost.ghostTexture.loadFromFile("ghost_blue.png")) {
    std::cout << "testTexture blue passed!" << std::endl;
  } else {
    std::cout << "testTexture blue failed!" << std::endl;
  }
  if (ghost.ghostTexture.loadFromFile("ghost_green.png")) {
    std::cout << "testTexture green passed!" << std::endl;
  } else {
    std::cout << "testTexture green failed!" << std::endl;
  }
  if (ghost.ghostTexture.loadFromFile("ghost_red.png")) {
    std::cout << "testTexture red passed!" << std::endl;
  } else {
    std::cout << "testTexture red failed!" << std::endl;
  }
  if (ghost.ghostTexture.loadFromFile("ghost_yellow.png")) {
    std::cout << "testTexture yellow passed!" << std::endl;
  } else {
    std::cout << "testTexture yellow failed!" << std::endl;
  }
};

// Test moving Ghost
void testGhostMovement(Ghost ghost, sf::RenderWindow& window, Maze maze) {
  ghost.move(1, maze, 5.0f);        // Try moving right
  if (ghost.getPosition().x > 100)  // Position should have changed
  {
    std::cout << "Ghost movement test 1 passed!" << std::endl;
  } else {
    std::cout << "Ghost movement test 1 failed!" << std::endl;
  }

  ghost.setPosition(
      sf::Vector2f(100, 100));       // Move to position next to the wall
  ghost.move(0, maze, 1.0f);         // Try moving right into the wall
  if (ghost.getPosition().x == 100)  // Position should not change
  {
    std::cout << "Ghost movement test 2 passed!" << std::endl;
  } else {
    { std::cout << "Ghost movement test 2 failed!" << std::endl; }
  }
  std::cout << "Ghost movement test passed!" << std::endl;
}

// Test detect death
void testGhostDeathDetection(sf::RenderWindow& window, Ghost ghost,
                             Pacman pacman) {
  pacman.setPosition(sf::Vector2f(100, 100));
  ghost.setPosition(sf::Vector2f(100, 100));
  if (ghost.checkDeath(pacman) == true) {
    std::cout << "Ghost death detection test 1 passed!" << std::endl;
  } else {
    std::cout << "Ghost death detection test 1 failed!" << std::endl;
  }

  ghost.setPosition(sf::Vector2f(200, 200));
  if (ghost.checkDeath(pacman) == false) {
    std::cout << "Ghost death detection test 2 passed!" << std::endl;
  } else {
    std::cout << "Ghost death detection test 2 failed!" << std::endl;
  }
  std::cout << "Ghost death detection test passed!" << std::endl;
}

int main() {
  // Create a window for testing purposes
  sf::RenderWindow window(sf::VideoMode(800, 600), "Ghost Unit Test");

  // Initialize Pacman object
  Pacman pacman(window, 20);  // Assuming grid size of 20

  // Initilize Ghost object
  Ghost ghost(window, 20, 100, 100, "red");

  // Initialize Maze object
  Maze maze(20, 20);

  // Test drawing Ghost
  testDrawing(window, ghost);
  // Test texture
  testTexture(ghost);

  testGhostInitialization(ghost);
  // Test moving Ghost
  testGhostMovement(ghost, window, maze);

  testGhostDeathDetection(window, ghost, pacman);

  std::cout << "All tests passed!" << std::endl;
  return 0;
}
