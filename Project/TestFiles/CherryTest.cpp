#include <SFML/Graphics.hpp>   // Include the SFML Graphics module for rendering
#include <cstdlib>             // Include standard library for random number generation
#include <ctime>               // Include time library for seeding random generator
#include <iostream>            // Include iostream for console input/output
#include "Cherry.h"            // Include Cherry class header
#include "Collectables.h"      // Include Collectables class header
#include "Maze.h"              // Include Maze class header
#include "Pacman.h"            // Include Pacman class header

// Function to test drawing the cherry object in the window
void testCherryDrawing(sf::RenderWindow &window, Cherry cherry) {
    // Main loop that runs until the window is closed
    while (window.isOpen()) {
        sf::Event event;  // Event object to handle window events
        // Poll events in a loop
        while (window.pollEvent(event)) {
            window.clear();       // Clear the window with the default color
            cherry.draw(window);  // Draw the cherry object in the window
            window.display();     // Display the updated contents of the window
            // Check if the close event was triggered
            if (event.type == sf::Event::Closed) {
                window.close();  // Close the window
            }
        }
    }
    std::cout << "Cherry drawing test passed!" << std::endl;  // Indicate that the drawing test passed
}

// Function to test loading the cherry texture from file
void testTexture(Cherry cherry) {
    // Attempt to load the cherry texture from file
    if (cherry.getCherryTexture().loadFromFile("images/cherry.png")) {
        std::cout << "testTexture cherry passed!" << std::endl;  // Texture loaded successfully
    } else {
        std::cout << "testTexture cherry failed!" << std::endl;  // Failed to load the texture
    }
}

// Function to test placing the cherry in the maze
void testCherryPlacement(Cherry cherry) {
    bool cherryPlaced = false;  // Flag to check if the cherry is placed
    // Loop through the maze grid
    for (int y = 0; y < cherry.getGridSize(); ++y) {
        for (int x = 0; x < cherry.getGridSize(); ++x) {
            // Check if the current cell contains a cherry
            if (cherry.getMaze()[y][x] == 3) {
                cherryPlaced = true;  // Cherry found, set the flag to true
                break;  // Break out of the inner loop
            }
        }
        if (cherryPlaced)
            break;  // Break out of the outer loop if cherry is placed
    }

    // Print test result based on whether the cherry was found
    if (cherryPlaced) {
        std::cout << "Test Passed: Cherry placed correctly.\n";
    } else {
        std::cout << "Test Failed: Cherry not placed on the grid.\n";
    }
}

// Function to test if Pacman correctly consumes the cherry and gains points
void testCherryPoints(Pacman pacman, Cherry cherry) {
    // Place a cherry at a specific location in the maze
    cherry.getMaze()[1][1] = 3;
    // Set Pacman's position to the location of the cherry
    pacman.setPosition(sf::Vector2f(1 * cherry.getCellSize(), 1 * cherry.getCellSize()));

    // Add points for consuming the cherry
    int points = cherry.addPoints(pacman);

    // Check if the points are correctly added and the cherry is consumed
    if (points == 100 && cherry.getMaze()[1][1] == 8) {
        std::cout << "Test Passed: Cherry correctly consumed and points added.\n";
    } else {
        std::cout << "Test Failed: Cherry not consumed correctly.\n";
    }
}

int main() {
    srand(static_cast<unsigned>(time(0)));  // Seed the random number generator with the current time
    sf::RenderWindow window(sf::VideoMode(800, 800), "Cherry Unit Test");  // Create a window for rendering

    Pacman pacman(window, 20);  // Create a Pacman object
    Maze maze(20, 20);          // Create a Maze object
    Cherry cherry(20, 800, maze.getMaze());  // Create a Cherry object with the maze

    testCherryDrawing(window, cherry);  // Run the test for drawing the cherry
    testTexture(cherry);                // Run the test for loading the cherry texture
    testCherryPlacement(cherry);        // Run the test for placing the cherry in the maze
    testCherryPoints(pacman, cherry);   // Run the test for Pacman consuming the cherry

    return 0;  // Exit the program
}
