class Ghost : public Entities {
    private:
        int change = 0;
        int cellSize;
        int gridSize;
        float speed = 250.0f;
        sf::Texture ghostTexture;
        sf::Sprite ghost;
    public:
        Ghost(){}

        Ghost(sf::RenderWindow& window,int gs,int x, int y, std::string color) : gridSize(gs) {
            cellSize = window.getSize().x / gridSize;
            ghostTexture.loadFromFile("images/ghost_"+color+".png");
            ghost.setTexture(ghostTexture);
            ghost.setOrigin(ghostTexture.getSize().x / 2, ghostTexture.getSize().y / 2);
            ghost.setScale(cellSize / ghost.getLocalBounds().width, cellSize / ghost.getLocalBounds().height);
            ghost.setPosition(y * cellSize + (cellSize / 2), x * cellSize + (cellSize / 2));
            std::cout << "Ghost installed lol" << std::endl;
        }

        virtual void draw(sf::RenderWindow& window) override {
            window.draw(ghost);
        }

        virtual bool move(int direction,Maze maze,float time) override {
            float fSpeed = time * speed;
            sf::Vector2f ghostMov = getMovement(change,fSpeed);
            sf::Vector2f ghostPos = ghost.getPosition() + ghostMov;
            int gridX = ghostPos.x / cellSize;
            int gridY = ghostPos.y / cellSize;
            if (!maze.isWall(gridX, gridY)) {
                sf::Vector2f Gpos(ghostPos.x, ghostPos.y);
                if (change == 0 || change == 2) {
                    Gpos = sf::Vector2f(ghostPos.x, gridY * cellSize + (cellSize / 2));
                } else if (change == 1 || change == 3) {
                    Gpos = sf::Vector2f(gridX * cellSize + (cellSize / 2), ghostPos.y);
                } else {
                    Gpos = sf::Vector2f(gridX * cellSize + (cellSize / 2), gridY * cellSize + (cellSize / 2));
                }
                ghost.setPosition(Gpos);
            } else {
                change = rand() % 4;
            }
            return true;
        }

        virtual void setPosition(const sf::Vector2f& newPos) override {
            ghost.setPosition(newPos);
        }

        virtual sf::Vector2f getPosition() const override {
            return ghost.getPosition();
        }

        sf::Vector2f getMovement(int change,float fSpeed) {
            sf::Vector2f ghostMov(0.0f, 0.0f);
            switch (change) {
                case 0:
                    ghostMov.x = fSpeed;
                    break;
                case 1:
                    ghostMov.y = fSpeed;
                    break;
                case 2:
                    ghostMov.x = -fSpeed;
                    break;
                case 3:
                    ghostMov.y = -fSpeed;
                    break;
            }
            return ghostMov;
        }

        virtual float getSpeed(){
            return speed;
        }
        
        bool checkDeath(Pacman p){
            sf::Vector2f PacPos = p.getPosition();
            sf::Vector2f GhostPos = ghost.getPosition();
            int pacX = PacPos.x / cellSize;
            int pacY = PacPos.y / cellSize;
            int ghostX = GhostPos.x / cellSize;
            int ghostY = GhostPos.y / cellSize;
            if(pacX == ghostX && pacY == ghostY){
                return true;
            }
            return false;
        }
};