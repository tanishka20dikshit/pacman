
#ifndef ELEMENTS_H
#define ELEMENTS_H
#include <SFML/Graphics.hpp>
class Elements {
protected:
    sf::Vector2f position;
public:
    Elements();
    virtual void draw(sf::RenderWindow& window);
    virtual void setPosition(const sf::Vector2f& newPos);
    virtual sf::Vector2f getPosition() const;
};

#endif