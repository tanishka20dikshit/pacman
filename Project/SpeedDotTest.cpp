#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "SpeedDot.cpp"
#include "Pacman.cpp"  // Ensure this file defines the Pacman class with relevant methods.
#include "Collectables.cpp"  // Ensure this file defines the Collectables class.
#include "Maze.cpp"
#include "Entities.cpp"  // Ensure this file defines any dependencies.
 // Test drawing speed dot
  void testSpeedDotDrawing(sf::RenderWindow &window, SpeedDot speedDot)
  {  
   while (window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event)) 
    {window.clear();
    speedDot.draw(window);
    window.display();
    if (event.type == sf::Event::Closed) {
      window.close();
    }}
  }
  std::cout << "Speed Dot drawing test passed!" << std::endl;
};

void testInitializationAndPlacement(SpeedDot speeddot, Maze maze) {
        std::cout << "Test Initialization and Placement\n";
        int dotCount = 0;
        for (int y = 0; y < maze.gridSize; ++y) {
            for (int x = 0; x < maze.gridSize; ++x) {
                if (maze.maze[y][x] == 2) {
                    dotCount++;
                }
            }
        }
        if (dotCount == 3) {
            std::cout << "Passed: Correct number of SpeedDots placed.\n";
        } else {
            std::cout << "Failed: Incorrect number of SpeedDots placed (" << dotCount << ").\n";
        }
    }

    void testAddPoints(SpeedDot speedDot,Maze maze,Pacman pacman) {
        std::cout << "Test addPoints Method\n";

        pacman.setPosition(sf::Vector2f(0, 0));

        // Manually place a SpeedDot at Pacman's initial position
        maze.maze[0][0] = 2;

        int points = speedDot.addPoints(pacman);
        if (points == 50) {
            std::cout << "Passed: Pacman collected SpeedDot and received points.\n";
        } else {
            std::cout << "Failed: Pacman did not collect SpeedDot correctly (" << points << " points).\n";
        }

        if (maze.maze[0][0] == 8) {
            std::cout << "Passed: SpeedDot removed from maze after collection.\n";
        } else {
            std::cout << "Failed: SpeedDot not removed from maze after collection.\n";
        }
};

int main() {
    srand(static_cast<unsigned>(time(0)));  // Seed random number generator
    // Initilize Window for testing purpose
  sf::RenderWindow window(sf::VideoMode(800, 600), "Speed Dot Unit Test");

  // Initialize Pacman object
  Pacman pacman(window, 20);

  // Initialize Maze
  Maze maze(20, 20);

  // Initialize speed dot object
  SpeedDot speedDot(20, 800, maze.maze);

 // Test drawing speed dot
  testSpeedDotDrawing(window, speedDot);


 // Test Initialization And Placement
testInitializationAndPlacement(speedDot, maze);
//Test Add Points 
testAddPoints(speedDot, maze,pacman) ;
    return 0;
}
