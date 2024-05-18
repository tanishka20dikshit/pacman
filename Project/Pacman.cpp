class Pacman : public Entities {
    private:
        sf::Texture pacmanTexture;
        sf::Texture pacmanfTexture;
        sf::Sprite pacman;
        sf::Clock clock;
        sf::Clock clk;
        int cellSize;
        int gridSize;
        float speed = 250.0f;
        bool boost = false;
        bool changed = false;
    public:
        Pacman(){}

        Pacman(sf::RenderWindow& window,int gs) : gridSize(gs) {
            cellSize = window.getSize().x / gridSize;
            pacmanTexture.loadFromFile("images/pacman.png");
            pacmanfTexture.loadFromFile("images/pacman-full.png");
            pacman.setTexture(pacmanTexture);
            pacman.setOrigin(pacmanTexture.getSize().x / 2, pacmanTexture.getSize().y / 2);
            pacman.setPosition(window.getSize().x / 2, window.getSize().y / 2);
            pacman.setScale(cellSize / pacman.getLocalBounds().width, cellSize / pacman.getLocalBounds().height);
        }

        virtual void draw(sf::RenderWindow& window) override {
            if(clk.getElapsedTime().asSeconds() > 0.2f) {
                changed = !changed;
                pacman.setTexture(changed ? pacmanfTexture : pacmanTexture);
                clk.restart();
            } 
            window.draw(pacman);
        }

        virtual bool move(int direction,Maze maze,float time) override {
            sf::Vector2f movement(0.0f, 0.0f);
            float fSpeed = time * speed *(boost ? 2.0f : 1.0f);
            if (direction == 0) {
                movement.x = -fSpeed;
                pacman.setRotation(180.0f);
            }else if (direction == 1) {
                movement.x = fSpeed;
                pacman.setRotation(0.0f);
            }else if (direction == 2) {
                movement.y = -fSpeed;
                pacman.setRotation(-90.0f);
            }
            else if (direction == 3) {
                movement.y = fSpeed;
                pacman.setRotation(90.0f);
            }
            sf::Vector2f newPos = pacman.getPosition() + movement;
            int X = newPos.x / (cellSize);
            int Y = newPos.y / (cellSize);
            sf::Vector2f pos(newPos.x,newPos.y);
            if(!maze.isWall(X,Y)){
                if(direction == 0 || direction == 1){
                    pos = sf::Vector2f(newPos.x,Y*cellSize+(cellSize/2));
                }else if(direction == 2 || direction == 3){
                    pos = sf::Vector2f(X*cellSize+(cellSize/2),newPos.y);
                }else{
                    pos = sf::Vector2f(X*cellSize+(cellSize/2),Y*cellSize+(cellSize/2));
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

        virtual float getSpeed(){
            return speed;
        }
        
        void increaseSpeed(bool toggle) {
            if (toggle) {
                clock.restart();
                boost = true;
            } else if (boost) {
                float seconds = clock.getElapsedTime().asSeconds();
                if (seconds > 5) {
                    boost = false;
                }
            }
        }
};