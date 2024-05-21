#include "Maze.cpp"
#include <SFML/Graphics.hpp>
#include <iostream>

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

void testTexture (Maze maze)
{   
  //Test right texture
  if (maze.right_corner.loadFromFile("right-corner.png")) {
    std::cout << "testTexture right corner passed!" << std::endl;
  }
  else
  { std::cout << "testTexture right corner failed!" << std::endl; }

   //Test left texture
 if (maze.left_corner.loadFromFile("left-corner.png")) {
    std::cout << "testTexture left corner passed!" << std::endl;
  }
  else
  { std::cout << "testTexture b_left corner failed!" << std::endl; }
   
      //Test bottom left texture
   if (maze.b_left_corner.loadFromFile("bottom-left-corner.png")) {
    std::cout << "testTexture bottom left corner passed!" << std::endl;
  }
  else
  { std::cout << "testTexture bottom left corner failed!" << std::endl; }
   
   //Test bottom right texture
   if (maze.b_right_corner.loadFromFile("bottom-right-corner.png")) {
    std::cout << "testTexture bottom right corner passed!" << std::endl;
  }
  else
  { std::cout << "testTexture bottom right corner failed!" << std::endl; }
};


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

int main() {
   // Create a window for testing purposes
  sf::RenderWindow window(sf::VideoMode(800, 600), "Pacman Unit Test");

    // Create a maze object
  Maze maze(20, 800);

  // Test drawing Maze
testDrawing(window, maze);

  //Testing texture
  testTexture (maze);

  //Testing wall 
  testMaze(maze);
  std::cout << "All tests passed!\n";
  return 0;
}
