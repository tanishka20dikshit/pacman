class Pacman : public Entities {
    private:
        sf::Texture pacmanTexture;
        sf::Sprite pacman;
        int cellSize;
        int gridSize;
        float speed = 0.15f;
        sf::Clock clock;
        bool boost = false;
    public:
        Pacman(){}
        Pacman(sf::RenderWindow& window,int gs){
            gridSize = gs;
            cellSize = window.getSize().x / gridSize;
            pacmanTexture.loadFromFile("pacman.png");
            pacman.setTexture(pacmanTexture);
            pacman.setOrigin(pacmanTexture.getSize().x / 2, pacmanTexture.getSize().y / 2);
            pacman.setPosition(window.getSize().x / 2, window.getSize().y / 2);
            pacman.setScale(cellSize / pacman.getLocalBounds().width, cellSize / pacman.getLocalBounds().height);
        }
        virtual void draw(sf::RenderWindow& window) override {
            window.draw(pacman);
        }
        virtual bool move(int direction,Maze maze) override {
            sf::Vector2f movement(0.0f, 0.0f);
            if (direction == 0) {
                movement.x = -speed;
                pacman.setRotation(180.0f);
            }else if (direction == 1) {
                movement.x = speed;
                pacman.setRotation(0.0f);
            }else if (direction == 2) {
                movement.y = -speed;
                pacman.setRotation(-90.0f);
            }
            else if (direction == 3) {
                movement.y = speed;
                pacman.setRotation(90.0f);
            }
            sf::Vector2f newPos = pacman.getPosition() + movement;
            int newX = newPos.x / (cellSize);
            int newY = newPos.y / (cellSize);
            if(!maze.isWall(newX,newY)){
                sf::Vector2f pos(newPos.x,newPos.y);
                if(direction == 0 || direction == 1){
                    pos = sf::Vector2f(newPos.x,newY*cellSize+(cellSize/2));
                }else if(direction == 2 || direction == 3){
                    pos = sf::Vector2f(newX*cellSize+(cellSize/2),newPos.y);
                }else{
                    pos = sf::Vector2f(newX*cellSize+(cellSize/2),newY*cellSize+(cellSize/2));
                }
                pacman.setPosition(pos);
            }else{
                return false;
            }
            return true;
        }
        virtual void setPosition(const sf::Vector2f& newPos) override {
            pacman.setPosition(newPos);
        }
        virtual sf::Vector2f getPosition() const override {
            return pacman.getPosition();
        }
        void increaseSpeed(bool toggle) {
            if (toggle) {
                clock.restart();
                boost = true;
            } else if (boost) {
                sf::Time elapsed = clock.getElapsedTime();
                float seconds = elapsed.asSeconds();
                if (seconds < 5) {
                    speed = 0.3f;
                } else {
                    speed = 0.15f;
                    boost = false;
                }
            }
        }
};