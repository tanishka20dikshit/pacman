#include <iostream>              // Include the iostream library for console input/output
#include <SFML/Graphics.hpp>     // Include the SFML Graphics module for rendering
#include "Elements.h"            // Include the Elements header
#include "Cherry.h"              // Include the Cherry header

// Function to test setting the position of the Cherry object
void testSetPosition(Cherry cherry) {
    sf::Vector2f newPosition(100.0f, 200.0f);  // Define a new position for the Cherry
    cherry.setPosition(newPosition);  // Set the position of the Cherry

    sf::Vector2f position = cherry.getPosition();  // Get the position of the Cherry
    // Check if the position matches the expected values
    if (position.x == 100.0f && position.y == 200.0f) {
        std::cout << "testSetPosition passed!" << std::endl;
    } else {
        std::cout << "testSetPosition failed: expected (100, 200), got (" << position.x << ", " << position.y << ")" << std::endl;
    }
}

// Function to test getting the default position of the Cherry object
void testGetPosition(Cherry cherry) {
    sf::Vector2f defaultPosition = cherry.getPosition();  // Get the default position of the Cherry

    // Check if the position matches the expected default values
    if (defaultPosition.x == 0.0f && defaultPosition.y == 0.0f) {
        std::cout << "testGetPosition passed!" << std::endl;
    } else {
        std::cout << "testGetPosition failed: expected (0, 0), got (" << defaultPosition.x << ", " << defaultPosition.y << ")" << std::endl;
    }
}

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 800), "Cherry Unit Test");  // Create a window for rendering

    Maze maze(20, 20);  // Create a Maze object with grid size 20x20

    Cherry cherry(20, 800, maze.getMaze());  // Create a Cherry object with grid size, window size, and maze reference

    testSetPosition(cherry);  // Run the test for setting the position of the Cherry
    testGetPosition(cherry);  // Run the test for getting the default position of the Cherry

    return 0;  // Exit the program
}
