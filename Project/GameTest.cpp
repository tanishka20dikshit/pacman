
#include <iostream>
#include <cassert>
#include "Game.h"
#include <SFML/Graphics.hpp>

void testInitialization(Game& game, int w, int h) {
    // Test if the Game object initializes correctly
    assert(game.getHeight() == h);
    assert(game.getWidth() == w);
    assert(game.getPoints() == 0);
    assert(game.getLives() == 3);
    assert(!game.getIsAlive());
    assert(game.getDirection() == 0);
    assert(game.getIsAlive() == false);
    assert(game.getCanGameStart() == false);
    assert(game.getIsDying() == false);
    assert(game.getFont().loadFromFile("CrackMan.TTF"));
    std::cout << "Initialization test passed!" << std::endl;
}

void testHandlingKeys(Game& game) {
    // Test if the handlingKeys method updates direction correctly
    
    // Simulate key press events and check the direction
    game.handleKeys();
    // Since we can't simulate actual key presses without a framework,
    // we just test if the function can be called without errors.
    std::cout << "Handling keys test passed!" << std::endl;
}


void testRender(Game& game) {
    // Test if the render method works without crashing
    game.render(); // Call render to check if it executes without errors
    std::cout << "Render method test passed!" << std::endl;
}

//Test game reset
void testGameReset(Game& game) {
    
    // Simulate some gameplay changes
    game.run();
    game.resetGame();
    
    // Test reset points and lives
    assert(game.getPoints()==0);
    assert(game.getLives()==3);

    // Test reset state flags
    assert(game.getIsAlive() == false);
    assert(game.getCanGameStart() == false);
    assert(game.getIsDying() == false);
}

//Test if the High Score is still persisted
void testHighScorePersistence(Game& game) {
    
    // Simulate some gameplay changes to set a high score
    game.resetGame();
    game.run();
    int initialHighScore = game.getHighScore();
    game.resetGame();
    
    // Ensure high score is updated and persistent
    assert(initialHighScore==game.getHighScore());
}

int main() {
    int w = 800;
    int h = 800;
    Game game(h,w);
    // Run test cases
    testInitialization(game,w,h);
    testHandlingKeys(game);
    //testRun(game);
    testRender(game);
    
    std::cout << "All tests passed!" << std::endl;
    return 0;
}

