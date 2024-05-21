
#include "Entities.h"

#include <SFML/Graphics.hpp>

#include "Elements.h"
#include "Maze.h"

Entities::Entities() {};
bool Entities::move(int direction, Maze maze, float time) { return false; }
float Entities::getSpeed() { return speed; }
