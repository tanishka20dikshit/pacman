class SpeedDot : public Collectables {
    private:
        int gridSize;
        int cellSize;
        int points = 50;
        int n = 3; // Number of speed dots to be placed
        int **maze;
        float scaleFactor = 1.0f;
        bool isScalingDown = false;
        sf::Clock animationClock;
    public:
        SpeedDot(){}
        SpeedDot(int gs,int width,int ** mz): gridSize(gs), cellSize(width/gridSize), maze(mz) {
            placeRandomly();
        }
        void placeRandomly() {
            int count = 0;
            while (count < n) {
                int x = rand() % gridSize;
                int y = rand() % gridSize;
                if (maze[x][y] == 0) {
                    maze[x][y] = 2;
                    count++;
                }
            }
        }
        virtual void draw(sf::RenderWindow& window) override {
            sf::CircleShape dot((cellSize / 3)*scaleFactor);
            dot.setFillColor(sf::Color::White);
            float offset = (cellSize - dot.getRadius() * 2) / 2;
            for (int y = 0; y < gridSize; ++y) {
                for (int x = 0; x < gridSize; ++x) {
                    if (maze[y][x] == 2) {
                        dot.setPosition(x * cellSize + offset, y * cellSize + offset);
                        window.draw(dot);
                    }
                }
            }
            if (animationClock.getElapsedTime().asMilliseconds() > 10) {
                if (isScalingDown) {
                    scaleFactor -= 0.01f;
                    if (scaleFactor <= 0.5f) {
                        isScalingDown = false;
                    }
                } else {
                    scaleFactor += 0.01f;
                    if (scaleFactor >= 1.0f) {
                        isScalingDown = true; 
                    }
                }
                animationClock.restart();
            }
        }

        int addPoints(Pacman &pacman){
            sf::Vector2f pos = pacman.getPosition();
            int X = pos.x / (cellSize);
            int Y = pos.y / (cellSize);
            pacman.increaseSpeed(false);
            if(maze[Y][X] == 2){
                maze[Y][X] = 8;
                //sf::sleep(sf::seconds(0.3));
                pacman.increaseSpeed(true);
                return points;
            }
            return 0;
        };
};