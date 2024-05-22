#include <SFML/Graphics.hpp>
#include <iostream>
#include "Collectables.h"       // Include Collectables header file
#include "Entities.h"           // Include Entities header file
#include "Maze.h"               // Include Maze header file
#include "Pacman.h"             // Include Pacman header file
#include "Pellets.h"            // Include Pellets header file

// Function to test the drawing of pellets on the window
void testPelletsDrawing(sf::RenderWindow &window, Pellets pellets){
    while (window.isOpen()){
        sf::Event event;
        while (window.pollEvent(event)){
            window.clear();        // Clear the window
            pellets.draw(window);  // Draw the pellets
            window.display();      // Display the updated window
            if (event.type == sf::Event::Closed){ // Close the window if the close event is triggered
                window.close();
            }
        }
    }
    std::cout << "Pellets drawing test passed!" << std::endl; // Output success message
}

// Function to test the addPoints method of the Pellets class
void testAddPoints(Pellets pellets, Maze maze, Pacman pacman){
    pacman.setPosition(sf::Vector2f(40.0f, 40.0f));  // Set Pacman's position to (40, 40)
    int points = pellets.addPoints(pacman);          // Add points when Pacman collects pellets
    // Check if the correct points were awarded
    if (points == 10){
        std::cout << "Test addPoints 1 passed: Pacman collected Pellets and received points.\n";
    } else {
        std::cout << "Test addPoints 1 failed: Pacman did not collect Pellets correctly (" << points << " points).\n";
    }
    points = pellets.addPoints(pacman);  // Add points again to check if pellets are removed
    // Check if the pellets were correctly removed after collection
    if (points == 0){
        std::cout << "Test addPoints 2 passed: Pellets removed from maze after collection.\n";
    } else {
        std::cout << "Test addPoints 2 failed: Pellets not removed from maze after collection.\n";
    }

    pacman.setPosition(sf::Vector2f(200.0f, 100.0f)); // Move Pacman to a new position without pellets
    pellets.addPoints(pacman);                       // Call addPoints method again
    points = pellets.addPoints(pacman);              // Check the points
    // Check if no points were awarded when there are no pellets
    if (points != 0){
        std::cerr << "Test add points 3 failed: Points should be 0 when there is no pellet." << std::endl;
    } else {
        std::cout << "Test add points 3 passed: Pacman gains no point" << std::endl;
    }
}

// Function to test the getGridSize method of the Pellets class
void testGetGridSize(Pellets pellets){
    if (pellets.getGridSize() == 20){
        std::cout << "testGetGridSize passed!" << std::endl;
    } else {
        std::cout << "testGetGridSize failed!" << std::endl;
    }
}

// Function to test the getCellSize method of the Pellets class
void testGetCellSize(Pellets pellets){
    if (pellets.getCellSize() == 40){
        std::cout << "testGetCellSize passed!" << std::endl;
    } else {
        std::cout << "testGetCellSize failed!" << std::endl;
    }
}

// Function to test the getPoints method of the Pellets class
void testGetPoints(Pellets pellets){
    if (pellets.getPoints() == 10){
        std::cout << "testGetPoints passed!" << std::endl;
    } else {
        std::cout << "testGetPoints failed!" << std::endl;
    }
}

int main(){
    srand(static_cast<unsigned>(time(0)));  // Seed the random number generator

    sf::RenderWindow window(sf::VideoMode(800, 800), "Speed Dot Unit Test");  // Create a render window

    Pacman pacman(window, 20);  // Create a Pacman object

    Maze maze(20, 20);  // Create a Maze object with grid size 20x20

    Pellets pellets(20, 800, maze.getMaze());  // Create a Pellets object with grid size, window size, and maze reference

    testPelletsDrawing(window, pellets);  // Run the test for drawing pellets

    testAddPoints(pellets, maze, pacman);  // Run the test for adding points when Pacman collects pellets

    testGetGridSize(pellets);  // Run the test for getting the grid size of pellets

    testGetCellSize(pellets);  // Run the test for getting the cell size of pellets

    testGetPoints(pellets);  // Run the test for getting the points value of pellets

    return 0;  // Exit the program
}
