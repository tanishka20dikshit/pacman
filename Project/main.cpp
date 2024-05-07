#include <SFML/Graphics.hpp>
#include <iostream>
#include "Game.cpp"
int main(){
    Game game(800,800);
    game.run();
    return 0;
}