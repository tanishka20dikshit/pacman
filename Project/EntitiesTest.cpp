#include <SFML/Graphics.hpp>
#include <iostream>

#include "Elements.h"
#include "Entities.h"
#include "Ghost.h"
#include "Maze.h"
#include "Pacman.h"

// test movement of different entities
void testMove(Ghost ghost, Pacman pacman) {
      // Define a Maze object
  Maze maze(20, 800);
  // Define test variables
  int testDirection = 2;  // Example direction
  float testTime = 1.0f;  // Example time

  // Call the move method
  bool result_ghost = ghost.move(testDirection, maze, testTime);
  bool result_pacman = pacman.move(testDirection, maze, testTime);

  // Check the result and print the outcome
  if (result_ghost == true && result_pacman == true) {
    std::cout << "Test Passed: move() returned true as expected." << std::endl;
  } else {
    std::cout << "Test Failed: move() did not return false as expected."
              << std::endl;
  }
}

// test speed of different entities
void testSpeed(Ghost ghost, Pacman pacman) {  // Call the move method
  float speed_ghost = ghost.getSpeed();
  float speed_pacman = pacman.getSpeed();

  // Check the result and print the outcome
  if (speed_ghost == 250.0f && speed_pacman == 250.0f) {
    std::cout << "Test Speed Passed" << std::endl;
  } else {
    std::cout << "Test Speed Failed"
              << std::endl;
  }
}
int main() {
  // Create an instance of the Entities class
  sf::RenderWindow window(sf::VideoMode(800, 600), "Ghost Test");
  Ghost ghost(window, 20, 10, 60, "red");
  Pacman pacman(window, 20);

  // test movement of different entities
  testMove(ghost, pacman);

  // test speed of different entities
  testSpeed(ghost, pacman);

  return 0;
}
