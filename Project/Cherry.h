#ifndef CHERRY_H
#define CHERRY_H

#include <iostream>
#include "Collectables.h"
#include "Pacman.h"

// Cherry class definition which inherits from Collectables
class Cherry : public Collectables {
    private:
        int gridSize; // Size of the grid in terms of cells (gridSize x gridSize)
        int cellSize; // Size of each cell in pixels
        int points = 100; // Points awarded for collecting a cherry
        int n = 1; // Number of cherries to be placed in the maze
        int **maze; // Pointer to the 2D maze array
        sf::Texture cherryTexture; // Texture for the cherry

    public:
        // Default constructor
        Cherry();
        
        // Parameterized constructor
        Cherry(int gs, int width, int **mz);
        
        // Override the draw method to render cherries on the window
        void draw(sf::RenderWindow& window) override;
        
        // Override the addPoints method to update points when Pacman eats a cherry
        int addPoints(Pacman pacman) override;
        
        // Method to place cherries randomly in the maze
        void placeRandomly();
        
        // Getter for gridSize
        int getGridSize() const;
        
        // Getter for cellSize
        int getCellSize() const;
        
        // Getter for points
        int getPoints() const;
        
        // Getter for number of cherries to be placed
        int getN() const;
        
        // Getter for maze
        int** getMaze() const;
        
        // Getter for cherryTexture
        sf::Texture getCherryTexture() const;
};

#endif
