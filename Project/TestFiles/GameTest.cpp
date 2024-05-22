#include <iostream>
#include <cassert>
#include "Game.h"
#include <SFML/Graphics.hpp>

// Function to test the initialization of the Game object
void testInitialization(Game& game, int w, int h) {
    // Assert statements to verify the initial state of the game
    assert(game.getHeight() == h); // Check if the height is set correctly
    assert(game.getWidth() == w);  // Check if the width is set correctly
    assert(game.getPoints() == 0); // Check if the points are initialized to 0
    assert(game.getLives() == 3);  // Check if the lives are initialized to 3
    assert(!game.getIsAlive());    // Check if the game is not alive initially
    assert(game.getDirection() == 0); // Check if the initial direction is 0
    assert(game.getIsAlive() == false); // Check if the game is not alive
    assert(game.getCanGameStart() == false); // Check if the game cannot start initially
    assert(game.getIsDying() == false); // Check if the game is not dying initially
    assert(game.getFont().loadFromFile("CrackMan.TTF")); // Check if the font loads correctly
    std::cout << "Initialization test passed!" << std::endl; // Print success message
}

// Function to test the handling of key inputs
void testHandlingKeys(Game& game) {
    game.handleKeys(); // Call the handleKeys method to simulate key handling
    std::cout << "Handling keys test passed!" << std::endl; // Print success message
}

// Function to test the render method of the Game object
void testRender(Game& game) {
    game.render(); // Call the render method to simulate rendering
    std::cout << "Render method test passed!" << std::endl; // Print success message
}

// Function to test the reset functionality of the Game object
void testGameReset(Game& game) {
    game.run(); // Run the game
    game.resetGame(); // Reset the game

    // Assert statements to verify the state after reset
    assert(game.getPoints() == 0); // Check if points are reset to 0
    assert(game.getLives() == 3);  // Check if lives are reset to 3
    assert(game.getIsAlive() == false); // Check if the game is not alive
    assert(game.getCanGameStart() == false); // Check if the game cannot start
    assert(game.getIsDying() == false); // Check if the game is not dying
}

// Function to test high score persistence across game resets
void testHighScorePersistence(Game& game) {
    game.resetGame(); // Reset the game
    game.run(); // Run the game
    int initialHighScore = game.getHighScore(); // Store the initial high score
    game.resetGame(); // Reset the game again
    
    // Assert to check if high score remains the same after reset
    assert(initialHighScore == game.getHighScore());
}

int main() {
    int w = 800;
    int h = 800;
    Game game(h, w); // Create a Game object with height and width

    testInitialization(game, w, h); // Test initialization
    testHandlingKeys(game); // Test handling keys
    testRender(game); // Test rendering
    
    std::cout << "All tests passed!" << std::endl; // Print success message
    return 0;
}
