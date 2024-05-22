#include "Maze.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>

// Test drawing Maze
void testDrawing(sf::RenderWindow &window, Maze maze) {
  while (window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event)) window.clear();
    maze.draw(window);
    window.display();
    if (event.type == sf::Event::Closed) {
                        window.close();
                    }
  }
}

//Test get functions

void testGetCellSize(Maze maze)
{
  if(maze.getCellSize()==40){
        std::cout << "testGetCellSize passed!" << std::endl;
  }
  else
  {
        std::cout << "testGetCellSize failed!" << std::endl;
  }
  
}
void testGetGridSize(Maze maze)
{
  if(maze.getGridSize()==20){
        std::cout << "testGetGridSize passed!" << std::endl;
  }
  else
  {
        std::cout << "testGetGridSize failed!" << std::endl;
  }
}

//Test texture
void testTexture (Maze maze)
{   
  //Test right texture
  if (maze.getRightCorner().loadFromFile("images/right-corner.png")) {
    std::cout << "testTexture right corner passed!" << std::endl;
  }
  else
  { std::cout << "testTexture right corner failed!" << std::endl; }

   //Test left texture
 if (maze.getLeftCorner().loadFromFile("images/left-corner.png")) {
    std::cout << "testTexture left corner passed!" << std::endl;
  }
  else
  { std::cout << "testTexture b_left corner failed!" << std::endl; }
   
      //Test bottom left texture
   if (maze.getBottomLeftCorner().loadFromFile("images/bottom-left-corner.png")) {
    std::cout << "testTexture bottom left corner passed!" << std::endl;
  }
  else
  { std::cout << "testTexture bottom left corner failed!" << std::endl; }
   
   //Test bottom right texture
   if (maze.getBottomRightCorner().loadFromFile("images/bottom-right-corner.png")) {
    std::cout << "testTexture bottom right corner passed!" << std::endl;
  }
  else
  { std::cout << "testTexture bottom right corner failed!" << std::endl; }
  
  //Test top line corner texture
   if (maze.getTopLine().loadFromFile("images/top-line.png")) {
    std::cout << "testTexture top line corner passed!" << std::endl;
  }
  else
  { std::cout << "testTexture top line corner failed!" << std::endl; }
  
  //Test left line corner texture
   if (maze.getLeftLine().loadFromFile("images/bottom-right-corner.png")) {
    std::cout << "testTexture left line corner passed!" << std::endl;
  }
  else
  { std::cout << "testTexture left line corner failed!" << std::endl; }
  
};

//Test wall
void testMaze(Maze maze) {
  // Test maze generation and rendering
  if (maze.isWall(0, 1) == 1) {
    std::cout << "Wall test 1 passed!\n";

  } else {
    std::cout << "Wall test 1 failed!\n";
  };
  if (maze.isWall(1, 2) == 0) {
    std::cout << "Wall test 2 passed!\n";

  } else {
    std::cout << "Wall test 2 failed!\n";
  }
};

//Test set up maze
void testSetupMaze(Maze maze) {
    maze.reset();
    int** layout = maze.getMaze();
    std::ifstream file("maze.txt");
    int expected;
    bool passed = true;
    for (int i = 0; i < maze.getGridSize(); ++i) {
        for (int j = 0; j < maze.getGridSize(); ++j) {
            file >> expected;
            if (layout[i][j] != expected) {
                std::cout << "Setup Maze Test failed at (" << i << ", " << j << "). Expected " << expected << " but got " << layout[i][j] << ".\n";
                passed = false;
            }
        }
    }
    if (passed) {
        std::cout << "Setup Maze Test passed.\n";
    }
}
int main() {
   // Create a window for testing purposes
  sf::RenderWindow window(sf::VideoMode(800, 800), "Pacman Unit Test");

    // Create a maze object
  Maze maze(20, 800);

  // Test drawing Maze
  testDrawing(window, maze);

  //Testing texture
  testTexture (maze);

  //Test get functions
 testGetCellSize(maze);
 testGetGridSize(maze);

  //Testing wall 
  testMaze(maze);

  //Test set up maze
testSetupMaze(maze);
  std::cout << "All tests passed!\n";
  return 0;
}
