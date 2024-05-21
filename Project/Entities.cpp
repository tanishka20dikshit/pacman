<<<<<<< HEAD

#include "Entities.h"

#include <SFML/Graphics.hpp>

#include "Elements.h"
#include "Maze.h"

Entities::Entities() {};
bool Entities::move(int direction, Maze maze, float time) { return false; }
float Entities::getSpeed() { return speed; }
=======
#include "Entities.h"

Entities::Entities() {}

bool Entities::move(int direction, Maze maze, float time) {
    return false; // Default implementation returns false
}

float Entities::getSpeed() {
    return speed; // Default implementation returns speed
}
>>>>>>> abcc5d7128c62abc84e12feeadabe743d0576259
