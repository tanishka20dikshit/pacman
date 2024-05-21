<<<<<<< HEAD
#include <SFML/Graphics.hpp>
#include "Elements.h"

Elements::Elements() {};
void Elements::draw(sf::RenderWindow& window){};
void Elements::setPosition(const sf::Vector2f& newPos) { position = newPos; }
sf::Vector2f Elements::getPosition() const { return position; }
=======
#include "Elements.h"

Elements::Elements() {}

void Elements::setPosition(const sf::Vector2f& newPos) {
    //////////
}

sf::Vector2f Elements::getPosition() const {
    return position;
}
>>>>>>> abcc5d7128c62abc84e12feeadabe743d0576259
