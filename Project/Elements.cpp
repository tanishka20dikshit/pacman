#include <SFML/Graphics.hpp>
#include "Elements.h"

Elements::Elements() {};
void Elements::draw(sf::RenderWindow& window){};
void Elements::setPosition(const sf::Vector2f& newPos) { position = newPos; }
sf::Vector2f Elements::getPosition() const { return position; }
