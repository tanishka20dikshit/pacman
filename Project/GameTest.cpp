#include <iostream>
#include <cassert>
#include "Game.cpp"

void testInitialization(Game& game, int w, int h) {
    // Test if the Game object initializes correctly
    assert(game.points == 0);
    assert(game.lives == 1);
    assert(!game.isAlive);
    assert(game.height == h);
    assert(game.width == w);
    assert(game.font.loadFromFile("CrackMan.TTF"));
    std::cout << "Initialization test passed!" << std::endl;
}

void testHandlingKeys(Game& game) {
    // Test if the handlingKeys method updates direction correctly
    
    // Simulate key press events and check the direction
    game.handlingKeys();
    // Since we can't simulate actual key presses without a framework,
    // we just test if the function can be called without errors.
    std::cout << "Handling keys test passed!" << std::endl;
}


void testRender(Game& game) {
    // Test if the render method works without crashing
    game.render(); // Call render to check if it executes without errors
    game.isAlive = true;
    game.render();
    std::cout << "Render method test passed!" << std::endl;
}

int main() {
    int w = 600;
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

