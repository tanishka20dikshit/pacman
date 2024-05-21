#include <iostream>
#include "Entities.cpp"
#include "Maze.cpp"
#include "Elements.cpp"
#include "Ghost.cpp"
#include "Pacman.cpp"
#include "Entities.cpp"

int main() {
    // Create an instance of the Entities class
    sf::RenderWindow window(sf::VideoMode(800, 600), "Ghost Test");
    Ghost ghost(window, 20, 180, 60,"red");
    Pacman pacman(window, 20);
    
    // Define a Maze object
    Maze maze(20,20);
    
    // Define test variables
    int testDirection = 0; // Example direction
    float testTime = 5.0f; // Example time
    
    // Call the move method
    bool result_ghost = ghost.move(testDirection, maze, testTime);
    bool result_pacman = pacman.move(testDirection, maze, testTime);

    // Check the result and print the outcome
    if (result_ghost == true && result_pacman == true ) {
        std::cout << "Test Passed: move() returned true as expected." << std::endl;
    } else {
        std::cout << "Test Failed: move() did not return false as expected." << std::endl;
    }
    
    return 0;
}
