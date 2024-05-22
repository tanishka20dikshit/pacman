#include <SFML/Graphics.hpp>   // Include the SFML Graphics module for rendering
#include <cstdlib>             // Include cstdlib for standard library functions (e.g., srand, rand)
#include <ctime>               // Include ctime for time functions
#include <iostream>            // Include iostream for console input/output
#include "Collectables.h"      // Include the Collectables header
#include "Entities.h"          // Include the Entities header
#include "Maze.h"              // Include the Maze header
#include "Pacman.h"            // Include the Pacman header
#include "SpeedDot.h"          // Include the SpeedDot header

// Function to test drawing the SpeedDot in the window
void testSpeedDotDrawing(sf::RenderWindow &window, SpeedDot speedDot) {
    while (window.isOpen()) {
        sf::Event event;  // Event object to handle window events
        // Poll events in a loop
        while (window.pollEvent(event)) {
            window.clear();  // Clear the window with the default color
            speedDot.draw(window);  // Draw the SpeedDot object in the window
            window.display();  // Display the updated contents of the window
            // Check if the close event was triggered
            if (event.type == sf::Event::Closed) {
                window.close();  // Close the window
            }
        }
    }
    std::cout << "Speed Dot drawing test passed!" << std::endl;
}

// Function to test the initialization and placement of SpeedDots in the maze
void testInitializationAndPlacement(SpeedDot speedDot, Maze maze) {
    std::cout << "Test Initialization and Placement\n";
    int dotCount = 0;  // Counter for SpeedDots
    // Iterate through the maze grid
    for (int y = 0; y < maze.getGridSize(); ++y) {
        for (int x = 0; x < maze.getGridSize(); ++x) {
            // Check if the current cell contains a SpeedDot
            if (maze.getMaze()[y][x] == 2) {
                dotCount++;
            }
        }
    }
    // Verify if the number of placed SpeedDots matches the expected count
    if (dotCount == speedDot.getN()) {
        std::cout << "Passed: Correct number of SpeedDots placed.\n";
    } else {
        std::cout << "Failed: Incorrect number of SpeedDots placed (" << dotCount << ").\n";
    }
}

// Function to test adding points when Pacman collects a SpeedDot
void testAddPoints(SpeedDot speedDot, Maze maze, Pacman pacman) {
    std::cout << "Test addPoints Method\n";

    pacman.setPosition(sf::Vector2f(0, 0));  // Set Pacman's position to (0, 0)

    maze.getMaze()[0][0] = 2;  // Place a SpeedDot at (0, 0) in the maze

    int points = speedDot.addPoints(pacman);  // Pacman collects the SpeedDot
    // Check if the collected points match the expected points for SpeedDot
    if (points == speedDot.getPoints()) {
        std::cout << "Passed: Pacman collected SpeedDot and received points.\n";
    } else {
        std::cout << "Failed: Pacman did not collect SpeedDot correctly (" << points << " points).\n";
    }

    // Verify if the SpeedDot was removed from the maze after collection
    if (maze.getMaze()[0][0] == 8) {
        std::cout << "Passed: SpeedDot removed from maze after collection.\n";
    } else {
        std::cout << "Failed: SpeedDot not removed from maze after collection.\n";
    }
}

// Function to test getting the grid size of the SpeedDot
void testGetGridSize(SpeedDot speedDot) {
    // Check if the grid size matches the expected value
    if (speedDot.getGridSize() == 20) {
        std::cout << "testGetGridSize passed!" << std::endl;
    } else {
        std::cout << "testGetGridSize failed!" << std::endl;
    }
}

// Function to test getting the cell size of the SpeedDot
void testGetCellSize(SpeedDot speedDot) {
    // Check if the cell size matches the expected value
    if (speedDot.getCellSize() == 40) {
        std::cout << "testGetCellSize passed!" << std::endl;
    } else {
        std::cout << "testGetCellSize failed!" << std::endl;
    }
}

// Function to test getting the points value of the SpeedDot
void testGetPoints(SpeedDot speedDot) {
    // Check if the points value matches the expected value
    if (speedDot.getPoints() == 50) {
        std::cout << "testGetPoints passed!" << std::endl;
    } else {
        std::cout << "testGetPoints failed!" << std::endl;
    }
}

// Function to test getting the number of SpeedDots
void testgetN(SpeedDot speedDot) {
    // Check if the number of SpeedDots matches the expected value
    if (speedDot.getN() == 3) {
        std::cout << "testgetN passed!" << std::endl;
    } else {
        std::cout << "testgetN failed!" << std::endl;
    }
}

// Function to test getting the scale factor of the SpeedDot
void testGetScaleFactor(SpeedDot speedDot) {
    // Check if the scale factor matches the expected value
    if (speedDot.getScaleFactor() == 1.0f) {
        std::cout << "testGetScaleFactor passed!" << std::endl;
    } else {
        std::cout << "testGetScaleFactor failed!" << std::endl;
    }
}

// Function to test if the SpeedDot is scaling down
void testGetIsScalingDown(SpeedDot speedDot) {
    // Check if the scaling down status matches the expected value
    if (speedDot.getIsScalingDown() == false) {
        std::cout << "testGetSpeed passed!" << std::endl;
    } else {
        std::cout << "testGetSpeed failed!" << std::endl;
    }
}

int main() {
    srand(static_cast<unsigned>(time(0)));  // Seed the random number generator

    sf::RenderWindow window(sf::VideoMode(800, 800), "Speed Dot Unit Test");  // Create a window for rendering

    Pacman pacman(window, 20);  // Create a Pacman object with the window and grid size

    Maze maze(20, 20);  // Create a Maze object with grid size 20x20

    SpeedDot speedDot(20, 800, maze.getMaze());  // Create a SpeedDot object with grid size, window size, and maze reference

    testSpeedDotDrawing(window, speedDot);  // Run the test for drawing SpeedDot

    testInitializationAndPlacement(speedDot, maze);  // Run the test for SpeedDot initialization and placement

    testAddPoints(speedDot, maze, pacman);  // Run the test for adding points when collecting SpeedDot

    testGetGridSize(speedDot);  // Run the test for getting grid size of SpeedDot

    testGetCellSize(speedDot);  // Run the test for getting cell size of SpeedDot

    testGetPoints(speedDot);  // Run the test for getting points value of SpeedDot

    testgetN(speedDot);  // Run the test for getting the number of SpeedDots

    testGetScaleFactor(speedDot);  // Run the test for getting the scale factor of SpeedDot

    testGetIsScalingDown(speedDot);  // Run the test for checking if SpeedDot is scaling down

    return 0;  // Exit the program
}
