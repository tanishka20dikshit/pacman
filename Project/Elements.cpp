class Elements {
private:
    sf::Vector2f position;
public:
    Elements() {}

    virtual void draw(sf::RenderWindow& window) = 0;
    virtual void setPosition(const sf::Vector2f& newPos) { position = newPos; }
    virtual sf::Vector2f getPosition() const { return position; }
};