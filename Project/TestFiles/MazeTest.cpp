#include "Maze.h"            // Include the Maze header file
#include <SFML/Graphics.hpp> // Include the SFML graphics library
#include <iostream>          // Include the iostream library for console output
#include <fstream>           // Include the fstream library for file handling

// Function to test drawing the maze in a window
void testDrawing(sf::RenderWindow &window, Maze maze){
    while (window.isOpen()){
        sf::Event event;
        while (window.pollEvent(event)) // Poll for events
            window.clear();             // Clear the window
        maze.draw(window);              // Draw the maze
        window.display();               // Display the updated window
        if (event.type == sf::Event::Closed){
            window.close();             // Close the window if the close event is triggered
        }
    }
}

// Function to test the cell size of the maze
void testGetCellSize(Maze maze){
    if (maze.getCellSize() == 40){
        std::cout << "testGetCellSize passed!" << std::endl;
    } else {
        std::cout << "testGetCellSize failed!" << std::endl;
    }
}

// Function to test the grid size of the maze
void testGetGridSize(Maze maze){
    if (maze.getGridSize() == 20){
        std::cout << "testGetGridSize passed!" << std::endl;
    } else {
        std::cout << "testGetGridSize failed!" << std::endl;
    }
}

// Function to test loading of textures for the maze
void testTexture(Maze maze){
    if (maze.getRightCorner().loadFromFile("images/right-corner.png")){
        std::cout << "testTexture right corner passed!" << std::endl;
    } else {
        std::cout << "testTexture right corner failed!" << std::endl;
    }

    if (maze.getLeftCorner().loadFromFile("images/left-corner.png")){
        std::cout << "testTexture left corner passed!" << std::endl;
    } else {
        std::cout << "testTexture left corner failed!" << std::endl;
    }

    if (maze.getBottomLeftCorner().loadFromFile("images/bottom-left-corner.png")){
        std::cout << "testTexture bottom left corner passed!" << std::endl;
    } else {
        std::cout << "testTexture bottom left corner failed!" << std::endl;
    }

    if (maze.getBottomRightCorner().loadFromFile("images/bottom-right-corner.png")){
        std::cout << "testTexture bottom right corner passed!" << std::endl;
    } else {
        std::cout << "testTexture bottom right corner failed!" << std::endl;
    }

    if (maze.getTopLine().loadFromFile("images/top-line.png")){
        std::cout << "testTexture top line corner passed!" << std::endl;
    } else {
        std::cout << "testTexture top line corner failed!" << std::endl;
    }

    if (maze.getLeftLine().loadFromFile("images/bottom-right-corner.png")){
        std::cout << "testTexture left line corner passed!" << std::endl;
    } else {
        std::cout << "testTexture left line corner failed!" << std::endl;
    }
}

// Function to test if specific cells are walls
void testMaze(Maze maze){
    if (maze.isWall(0, 1) == 1){
        std::cout << "Wall test 1 passed!\n";
    } else {
        std::cout << "Wall test 1 failed!\n";
    }
    if (maze.isWall(1, 2) == 0){
        std::cout << "Wall test 2 passed!\n";
    } else {
        std::cout << "Wall test 2 failed!\n";
    }
}

// Function to test the setup of the maze from a file
void testSetupMaze(Maze maze){
    maze.reset(); // Reset the maze to its initial state
    int **layout = maze.getMaze();
    std::ifstream file("maze.txt");
    int expected;
    bool passed = true;
    for (int i = 0; i < maze.getGridSize(); ++i){
        for (int j = 0; j < maze.getGridSize(); ++j){
            file >> expected;
            if (layout[i][j] != expected){
                std::cout << "Setup Maze Test failed at (" << i << ", " << j << "). Expected " << expected << " but got " << layout[i][j] << ".\n";
                passed = false;
            }
        }
    }
    if (passed){
        std::cout << "Setup Maze Test passed.\n";
    }
}

int main(){
    sf::RenderWindow window(sf::VideoMode(800, 800), "Pacman Unit Test"); // Create a window for testing

    Maze maze(20, 800); // Create a Maze object with grid size 20x20 and window size 800x800

    testDrawing(window, maze); // Test drawing the maze

    testTexture(maze); // Test loading textures for the maze

    testGetCellSize(maze); // Test getting the cell size
    testGetGridSize(maze); // Test getting the grid size

    testMaze(maze); // Test specific wall positions in the maze

    testSetupMaze(maze); // Test the setup of the maze from a file

    std::cout << "All tests passed!\n"; // Indicate all tests passed
    return 0;
}
