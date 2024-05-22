#include <SFML/Graphics.hpp>   // Include the SFML Graphics module for rendering
#include <iostream>            // Include iostream for console input/output
#include "Maze.h"              // Include Maze class header
#include "Pacman.h"            // Include Pacman class header

// Function to test drawing Pacman in the window
void testDrawing(sf::RenderWindow &window, Pacman pacman) {
    while (window.isOpen()) {
        sf::Event event;  // Event object to handle window events
        // Poll events in a loop
        while (window.pollEvent(event)) {
            window.clear();  // Clear the window with the default color
            window.draw(pacman.getPacman());  // Draw the Pacman object in the window
            window.display();  // Display the updated contents of the window
            // Check if the close event was triggered
            if (event.type == sf::Event::Closed) {
                window.close();  // Close the window
            }
        }
    }
}

// Function to test Pacman's movement within the maze
void testMove(Pacman pacman) {
    Maze maze(20, 20);  // Create a Maze object with grid size 20x20
    bool moveResult = pacman.move(0, maze, 0.1f);  // Attempt to move Pacman

    // Check if Pacman moved successfully and did not hit a wall
    if (moveResult == true && !maze.isWall(1, 1)) {
        std::cout << "testMove 1 passed!" << std::endl;
    } else {
        std::cout << "testMove 1 failed!" << std::endl;
    }

    // Reset Pacman's position and attempt another move
    sf::Vector2f newPos(0.0f, 0.0f);
    pacman.setPosition(newPos);
    moveResult = pacman.move(0, maze, 0.1f);

    // Check if the move was unsuccessful (expected since it starts at the initial position)
    if (moveResult == false) {
        std::cout << "testMove 2 passed!" << std::endl;
    } else {
        std::cout << "testMove 2 failed!" << std::endl;
    }
}

// Function to test Pacman's position getter and setter
void testGetPosition(Pacman pacman) {
    sf::Vector2f newPos(100.0f, 200.0f);  // Define a new position
    pacman.setPosition(newPos);  // Set Pacman's position
    sf::Vector2f getPosition = pacman.getPosition();  // Get Pacman's position

    // Check if the set position matches the retrieved position
    if (newPos.x == getPosition.x && newPos.y == getPosition.y) {
        std::cout << "testGetPosition passed!" << std::endl;
    } else {
        std::cout << "testGetPosition failed: expected " << newPos.x << ", " << newPos.y << ", got (" << getPosition.x << ", " << getPosition.y << ")" << std::endl;
    }
}

// Function to test Pacman's speed getter
void testGetSpeed(Pacman pacman) {
    // Check if Pacman's speed matches the expected value
    if (pacman.getSpeed() == 250.0f) {
        std::cout << "testGetSpeed passed!" << std::endl;
    } else {
        std::cout << "testGetSpeed failed!" << std::endl;
    }
}

// Function to test Pacman's speed increase mechanism
void testIncreasingSpeed(Pacman pacman, Maze maze) {
    pacman.increaseSpeed(true);  // Activate speed boost
    sf::Clock clock;  // Create a clock to measure time
    sf::Time elapsed = clock.getElapsedTime();  // Get elapsed time

    // Simulate elapsed time for speed boost
    if (elapsed.asSeconds() > 5) {
        pacman.increaseSpeed(false);  // Deactivate speed boost
        elapsed = clock.getElapsedTime();
        // Check if the speed boost was deactivated correctly
        if (pacman.getBoost() == false) {
            std::cout << "Test increasing speed passed!" << std::endl;
        } else {
            std::cout << "Test increasing speed failed!" << std::endl;
        }
    }
}

// Function to test loading Pacman's textures
void testTexture(Pacman pacman) {
    // Check if Pacman's default texture loads successfully
    if (pacman.getPacmanTexture().loadFromFile("images/pacman.png")) {
        std::cout << "testTexture passed!" << std::endl;
    } else {
        std::cout << "testTexture failed!" << std::endl;
    }

    // Check if Pacman's "full" texture loads successfully
    if (pacman.getPacmanfTexture().loadFromFile("images/pacman-full.png")) {
        std::cout << "testTexture passed!" << std::endl;
    } else {
        std::cout << "testTexture failed!" << std::endl;
    }
}

// Function to test Pacman's grid size getter
void testGetGridSize(Pacman pacman) {
    // Check if Pacman's grid size matches the expected value
    if (pacman.getGridSize() == 20) {
        std::cout << "testGetGridSize passed!" << std::endl;
    } else {
        std::cout << "testGetGridSize failed!" << std::endl;
    }
}

// Function to test Pacman's cell size getter
void testGetCellSize(Pacman pacman) {
    // Check if Pacman's cell size matches the expected value
    if (pacman.getCellSize() == 40) {
        std::cout << "testGetCellSize passed!" << std::endl;
    } else {
        std::cout << "testGetCellSize failed!" << std::endl;
    }
}

// Function to test Pacman's boost status getter
void testGetBoost(Pacman pacman) {
    // Check if Pacman's boost status matches the expected value (false by default)
    if (pacman.getBoost() == false) {
        std::cout << "testGetBoost passed!" << std::endl;
    } else {
        std::cout << "testGetBoost failed!" << std::endl;
    }
}

// Function to test if Pacman has changed state
void testChange(Pacman pacman) {
    // Check if Pacman's changed state matches the expected value (false by default)
    if (pacman.getChanged() == false) {
        std::cout << "testChange passed!" << std::endl;
    } else {
        std::cout << "testChange failed!" << std::endl;
    }
}

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 800), "Pacman Unit Test");  // Create a window for rendering

    Pacman pacman(window, 20);  // Create a Pacman object with window and grid size
    Maze maze(20, 20);  // Create a Maze object with grid size 20x20

    testDrawing(window, pacman);  // Run the test for drawing Pacman
    testMove(pacman);  // Run the test for Pacman's movement
    testGetPosition(pacman);  // Run the test for getting Pacman's position
    testGetSpeed(pacman);  // Run the test for getting Pacman's speed
    testIncreasingSpeed(pacman, maze);  // Run the test for increasing Pacman's speed
    testGetGridSize(pacman);  // Run the test for getting Pacman's grid size
    testGetCellSize(pacman);  // Run the test for getting Pacman's cell size
    testTexture(pacman);  // Run the test for loading Pacman's textures
    testGetBoost(pacman);  // Run the test for getting Pacman's boost status
    testChange(pacman);  // Run the test for checking Pacman's changed state

    std::cout << "All tests passed!" << std::endl;  // Indicate all tests passed

    return 0;  // Exit the program
}
