#include <SFML/Graphics.hpp>
#include <iostream>
#include "Elements.h"    // Include Elements header file
#include "Entities.h"    // Include Entities header file
#include "Ghost.h"       // Include Ghost header file
#include "Maze.h"        // Include Maze header file
#include "Pacman.h"      // Include Pacman header file

// Function to test the move() method for Ghost and Pacman
void testMove(Ghost ghost, Pacman pacman){
    Maze maze(20, 800); // Create a Maze object with grid size 20x20 and window size 800x800

    int testDirection = 2;  // Set a test direction for movement
    float testTime = 1.0f;  // Set a test time for movement

    // Call the move() method for both Ghost and Pacman
    bool result_ghost = ghost.move(testDirection, maze, testTime);
    bool result_pacman = pacman.move(testDirection, maze, testTime);

    // Check if both move() methods returned true as expected
    if (result_ghost == true && result_pacman == true){
        std::cout << "Test Passed: move() returned true as expected." << std::endl;
    } else {
        std::cout << "Test Failed: move() did not return true as expected." << std::endl;
    }
}

// Function to test the getSpeed() method for Ghost and Pacman
void testSpeed(Ghost ghost, Pacman pacman){
    // Get the speed of Ghost and Pacman
    float speed_ghost = ghost.getSpeed();
    float speed_pacman = pacman.getSpeed();

    // Check if both speeds are as expected (250.0f)
    if (speed_ghost == 250.0f && speed_pacman == 250.0f){
        std::cout << "Test Speed Passed" << std::endl;
    } else {
        std::cout << "Test Speed Failed" << std::endl;
    }
}

int main(){
    sf::RenderWindow window(sf::VideoMode(800, 800), "Ghost Test"); // Create a render window

    // Create a Ghost object with specified parameters
    Ghost ghost(window, 20, 10, 60, "red");
    
    // Create a Pacman object with specified parameters
    Pacman pacman(window, 20);

    // Run the tests for move() and getSpeed() methods
    testMove(ghost, pacman);
    testSpeed(ghost, pacman);

    return 0; // Exit the program
}
