#include <SFML/Graphics.hpp>
#include <iostream>
#include "Cherry.h"
#include "Collectables.h"
#include "Maze.h"
#include "Pellets.h"
#include "SpeedDot.h"

// Function to test adding points for collectables
void testCollectablesAddPoints(Pacman pacman, Cherry cherry, SpeedDot speedDot, Pellets pellets, Maze maze) {
    // Test adding points for cherry
    maze.getMaze()[0][0] = 3; // Set cherry position in maze
    pacman.setPosition(sf::Vector2f(0, 0)); // Set pacman position
    if (cherry.addPoints(pacman) != 100) { // Check if points added correctly
        std::cerr << "testCollectablesAddPoints Cherry failed. " << std::endl;
    } else {
        std::cout << "testCollectablesAddPoints Cherry  passed." << std::endl;
    }

    // Test adding points for speed dot
    pacman.setPosition(sf::Vector2f(0, 0)); // Reset pacman position
    maze.getMaze()[0][0] = 2; // Set speed dot position in maze
    if (speedDot.addPoints(pacman) != 50) { // Check if points added correctly
        std::cerr << "testCollectablesAddPoints Speed dot failed. " << std::endl;
    } else {
        std::cout << "testCollectablesAddPoints Speed dot  passed." << std::endl;
    }

    // Test adding points for pellets
    pacman.setPosition(sf::Vector2f(0, 0)); // Reset pacman position
    maze.getMaze()[0][0] = 0; // Set pellet position in maze
    if (pellets.addPoints(pacman) != 10) { // Check if points added correctly
        std::cerr << "testCollectablesAddPoints Pellets failed. " << std::endl;
    } else {
        std::cout << "testCollectablesAddPoints Pellets  passed." << std::endl;
    }
}

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 800), "Cherry Unit Test");

    Maze maze(20, 20);

    Pacman pacman(window, 20);

    Cherry cherry(20, 800, maze.getMaze());
    SpeedDot speedDot(20, 800, maze.getMaze());
    Pellets pellets(20, 800, maze.getMaze());

    // Run the test function
    testCollectablesAddPoints(pacman, cherry, speedDot, pellets, maze);
    return 0;
}
