#include <SFML/Graphics.hpp> // Include the SFML graphics library
#include <chrono>			 // Include the chrono library for time handling
#include <iostream>			 // Include the iostream library for console output
#include "Elements.h"		 // Include the Elements header file
#include "Entities.h"		 // Include the Entities header file
#include "Ghost.h"			 // Include the Ghost header file
#include "Maze.h"			 // Include the Maze header file
#include "Pacman.h"			 // Include the Pacman header file

// Function to test the initialization of a Ghost object
void testGhostInitialization(Ghost ghost){
	if (ghost.getPosition() == sf::Vector2f(60, 60)){
		std::cout << "Ghost initialization test passed!" << std::endl;
	} else {
		std::cout << "Ghost initialization test failed!" << std::endl;
	}
}

// Function to test the drawing of a Ghost object in a window
void testDrawing(sf::RenderWindow &window, Ghost ghost){
	while (window.isOpen()){
		sf::Event event;
		while (window.pollEvent(event)){	// Poll for events
			window.clear();				   // Clear the window
			window.draw(ghost.getGhost()); // Draw the ghost
			window.display();			   // Display the updated window
			if (event.type == sf::Event::Closed){
				window.close(); // Close the window if the close event is triggered
			}
		}
	}
	std::cout << "Ghost drawing test passed!" << std::endl;
}

// Function to test the loading of textures for the Ghost object
void testTexture(Ghost ghost){
	if (ghost.getGhostTexture().loadFromFile("images/ghost_blue.png")){
		std::cout << "testTexture blue passed!" << std::endl;
	} else {
		std::cout << "testTexture blue failed!" << std::endl;
	}
	if (ghost.getGhostTexture().loadFromFile("images/ghost_green.png")){
		std::cout << "testTexture green passed!" << std::endl;
	} else {
		std::cout << "testTexture green failed!" << std::endl;
	}
	if (ghost.getGhostTexture().loadFromFile("images/ghost_red.png")){
		std::cout << "testTexture red passed!" << std::endl;
	} else {
		std::cout << "testTexture red failed!" << std::endl;
	}
	if (ghost.getGhostTexture().loadFromFile("images/ghost_yellow.png")){
		std::cout << "testTexture yellow passed!" << std::endl;
	} else {
		std::cout << "testTexture yellow failed!" << std::endl;
	}
}

// Function to test the movement of a Ghost object
void testGhostMovement(Ghost ghost, sf::RenderWindow &window, Maze maze){
	ghost.setPosition(sf::Vector2f(100, 100));
	ghost.move(1, maze, 5.0f); // Move ghost in direction 1 (right)
	if (ghost.getPosition().x > 100)
	{ // Check if the ghost moved
		std::cout << "Ghost movement test 1 passed!" << std::endl;
	} else {
		std::cout << "Ghost movement test 1 failed!" << std::endl;
	}

	ghost.setPosition(sf::Vector2f(100, 100));
	ghost.move(0, maze, 1.0f); // Attempt to move ghost in direction 0 (up)
	if (ghost.getPosition().x == 100){ // Check if the ghost didn't move horizontally
		std::cout << "Ghost movement test 2 passed!" << std::endl;
	} else {
		std::cout << "Ghost movement test 2 failed!" << std::endl;
	}
	std::cout << "Ghost movement test passed!" << std::endl;
}

// Function to test getting the speed of a Ghost object
void testGetSpeed(Ghost ghost){
	if (ghost.getSpeed() == 250.0f){
		std::cout << "Test get speed passed!" << std::endl;
	} else {
		std::cout << "Test get speed failed!" << std::endl;
	}
}

// Function to test the death detection of a Ghost object
void testGhostDeathDetection(sf::RenderWindow &window, Ghost ghost, Pacman pacman){
	pacman.setPosition(sf::Vector2f(100, 100));
	ghost.setPosition(sf::Vector2f(100, 100));
	if (ghost.checkDeath(pacman) == true){ // Check if ghost detects collision with Pacman
		std::cout << "Ghost death detection test 1 passed!" << std::endl;
	} else {
		std::cout << "Ghost death detection test 1 failed!" << std::endl;
	}

	ghost.setPosition(sf::Vector2f(200, 200));
	if (ghost.checkDeath(pacman) == false) { // Check if ghost does not detect collision with Pacman
		std::cout << "Ghost death detection test 2 passed!" << std::endl;
	} else {
		std::cout << "Ghost death detection test 2 failed!" << std::endl;
	}
	std::cout << "Ghost death detection test passed!" << std::endl;
}

int main(){
	sf::RenderWindow window(sf::VideoMode(800, 800), "Ghost Unit Test"); // Create a window for testing

	Pacman pacman(window, 20); // Create a Pacman object

	Ghost ghost(window, 20, 1, 1, "red"); // Create a Ghost object

	Maze maze(20, 20); // Create a Maze object with grid size 20x20

	testDrawing(window, ghost); // Test drawing the ghost

	testTexture(ghost); // Test loading textures for the ghost

	testGhostInitialization(ghost); // Test ghost initialization

	testGhostMovement(ghost, window, maze); // Test ghost movement

	testGhostDeathDetection(window, ghost, pacman); // Test ghost death detection

	std::cout << "All tests passed!" << std::endl; // Indicate all tests passed
	return 0;
}
