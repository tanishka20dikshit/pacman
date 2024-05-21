#include <iostream>
#include <SFML/Graphics.hpp>
#include "Elements.h"
#include "Cherry.h"


void testSetPosition(Cherry cherry ) {
    sf::Vector2f newPosition(100.0f, 200.0f);
    cherry.setPosition(newPosition);

    sf::Vector2f position = cherry.getPosition();
    if (position.x == 100.0f && position.y == 200.0f) {
        std::cout << "testSetPosition passed!" << std::endl;
    } else {
        std::cout << "testSetPosition failed: expected (100, 200), got (" << position.x << ", " << position.y << ")" << std::endl;
    }
}

void testGetPosition(Cherry cherry) {
    sf::Vector2f defaultPosition = cherry.getPosition();

    if (defaultPosition.x == 0.0f && defaultPosition.y == 0.0f) {
        std::cout << "testGetPosition passed!" << std::endl;
    } else {
        std::cout << "testGetPosition failed: expected (0, 0), got (" << defaultPosition.x << ", " << defaultPosition.y << ")" << std::endl;
    }
}

int main() {
     // Initilize Window for testing purpose
  sf::RenderWindow window(sf::VideoMode(800, 600), "Cherry Unit Test");

  // Initialize Maze
  Maze maze(20, 20);

  // Initialize cherry object
  Cherry cherry(20, 800, maze.getMaze());

    testSetPosition(cherry);
    testGetPosition(cherry);

    return 0;
}
