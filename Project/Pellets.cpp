class Pellets : public Collectables {
    private:
        int gridSize;
        int cellSize;
        int points = 10;
        int **maze;
    public:
        Pellets(){}
        Pellets(int gs,int width,int ** mz) : gridSize(gs), cellSize(width/gridSize), maze(mz) {}
        virtual void draw(sf::RenderWindow& window) override {
            sf::CircleShape dot(cellSize / 12);
            dot.setFillColor(sf::Color::White);
            float offset = (cellSize - dot.getRadius() * 2) / 2;
            for (int y = 0; y < gridSize; ++y) {
                for (int x = 0; x < gridSize; ++x) {
                    if (maze[y][x] == 0) {
                        dot.setPosition(x * cellSize + offset, y * cellSize + offset);
                        window.draw(dot);
                    }
                }
            }
        }

        int addPoints(Pacman pacman){
            sf::Vector2f pos = pacman.getPosition();
            int X = pos.x / (cellSize);
            int Y = pos.y / (cellSize);
            if(maze[Y][X] == 0){
                maze[Y][X] = 8;
                return points;
            }
            return 0;
        };
};