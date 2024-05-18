class Cherry : public Collectables {
    private:
        int gridSize;
        int cellSize;
        int points = 100;
        int n = 1; // Number of cherries to be placed
        int **maze;
        sf::Texture cherryTexture;
    public:
        Cherry(){}
        Cherry(int gs,int width,int ** mz) : gridSize(gs), cellSize(width/gridSize), maze(mz) {
            cherryTexture.loadFromFile("cherry.png");
            placeRandomly();
        }
        
        virtual void draw(sf::RenderWindow& window) override {
            sf::RectangleShape cherry(sf::Vector2f(cellSize, cellSize));
            cherry.setFillColor(sf::Color::White);
            cherry.setTexture(&cherryTexture);
            for (int y = 0; y < gridSize; ++y) {
                for (int x = 0; x < gridSize; ++x) {
                    if (maze[y][x] == 3) {
                        cherry.setPosition(x * cellSize, y * cellSize);
                        window.draw(cherry);
                    }
                }
            }
        }

        int addPoints(Pacman pacman){
            sf::Vector2f pos = pacman.getPosition();
            int X = pos.x / (cellSize);
            int Y = pos.y / (cellSize);
            if(maze[Y][X] == 3){
                maze[Y][X] = 8;
                placeRandomly();
                return points;
            }
            return 0;
        };

        void placeRandomly(){
            int count = 0;
            while (count < n) {
                int x = rand() % gridSize;
                int y = rand() % gridSize;
                if (maze[x][y] == 0 || maze[x][y] == 8) {
                    maze[x][y] = 3;
                    count++;
                }
            }
        };
};