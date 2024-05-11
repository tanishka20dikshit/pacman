class Maze : public Elements {
    private:
        int gridSize;
        int cellSize;
        sf::Texture right_corner;
        sf::Texture left_corner;
        sf::Texture b_right_corner;
        sf::Texture b_left_corner;
        sf::Texture top_line;
        sf::Texture left_line;
    public:
        int **maze;
        Maze(){}
        Maze(int gs,int width){
            right_corner.loadFromFile("right-corner.png");
            left_corner.loadFromFile("left-corner.png");
            b_left_corner.loadFromFile("bottom-left-corner.png");
            b_right_corner.loadFromFile("bottom-right-corner.png");
            top_line.loadFromFile("top-line.png");
            left_line.loadFromFile("left-line.png");
            top_line.setSmooth(true);
            left_line.setSmooth(true);
            gridSize = gs;
            cellSize = width/gridSize;
            maze = new int*[gridSize];
            for (int i = 0; i < gridSize; ++i) {
                maze[i] = new int[gridSize];
            }
            int layout[gridSize][gridSize] = {
                {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
                {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
                {1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1},
                {1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1},
                {1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 0, 1},
                {1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 0, 1},
                {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
                {1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1},
                {1, 1, 1, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 1, 1, 1, 1, 1},
                {1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1},
                {1, 0, 0, 0, 0, 0, 1, 0, 1, 1, 1, 1, 0, 1, 0, 0, 0, 0, 0, 1},
                {1, 0, 1, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 1, 1, 1, 0, 1},
                {1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1},
                {1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 1},
                {1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1},
                {1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1},
                {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
                {1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1},
                {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
                {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
            };
            for (int i = 0; i < gridSize; ++i) {
                for (int j = 0; j < gridSize; ++j) {
                    maze[i][j] = layout[i][j];
                }
            }
        }
        virtual void draw(sf::RenderWindow& window) override {
            sf::RectangleShape shape(sf::Vector2f(cellSize, cellSize));
            for (int i = 0; i < gridSize; i++) {
                for (int j = 0; j < gridSize; j++) {
                    shape.setPosition(j * cellSize, i * cellSize);
                    if (maze[i][j] == 1) {
                        bool up = (i > 0 && maze[i-1][j] == 1);
                        bool down = (i < gridSize - 1 && maze[i+1][j] == 1);
                        bool left = (j > 0 && maze[i][j-1] == 1);
                        bool right = (j < gridSize - 1 && maze[i][j+1] == 1);
                        bool upLeft = (i > 0 && j > 0 && maze[i-1][j-1] == 1);
                        bool upRight = (i > 0 && j < gridSize - 1 && maze[i-1][j+1] == 1);
                        bool downLeft = (i < gridSize - 1 && j > 0 && maze[i+1][j-1] == 1);
                        bool downRight = (i < gridSize - 1 && j < gridSize - 1 && maze[i+1][j+1] == 1);
                        if(right && down && !downRight){
                            shape.setTexture(&left_corner);
                        }else if(left && down && !downLeft){
                            shape.setTexture(&right_corner);
                        }else if(up && left && !upLeft){
                            shape.setTexture(&b_right_corner);
                        }else if(up && right && !upRight){
                            shape.setTexture(&b_left_corner);
                        }else if(up && down){
                            shape.setTexture(&left_line);
                        }else if(left && right){
                            shape.setTexture(&top_line);
                        }
                        else{
                            shape.setTexture(nullptr);
                            if(!right && left){
                                shape.setPosition((j * cellSize)-cellSize/2, i * cellSize);
                                shape.setTexture(&top_line);
                            }else if(up && !down){
                                shape.setPosition((j * cellSize), (i * cellSize)-cellSize/2);
                                shape.setTexture(&left_line);
                            }else if(!left && right){
                                shape.setPosition((j * cellSize)+cellSize/2, i * cellSize);
                                shape.setTexture(&top_line);
                            }
                        }
                        if(up && left && upLeft && !right && !down){
                            shape.setTexture(&b_right_corner);
                            shape.setPosition(j * cellSize, i * cellSize);
                        }
                        if(up && right && upRight && !left && !down){
                            shape.setTexture(&b_left_corner);
                            shape.setPosition(j * cellSize, i * cellSize);
                        }
                        if(down && right && downRight && !left && !up){
                            shape.setTexture(&left_corner);
                            shape.setPosition(j * cellSize, i * cellSize);
                        }
                        if(down && left && downLeft && !right && !up){
                            shape.setTexture(&right_corner);
                            shape.setPosition(j * cellSize, i * cellSize);
                        }
                        if(up && down && left && right){
                            shape.setTexture(nullptr);
                        }
                        if (shape.getTexture() != nullptr){
                            window.draw(shape);
                        }
                    }
                }
            }
        }
        virtual void setPosition(const sf::Vector2f& newPos) override {
        }

        virtual sf::Vector2f getPosition() const override {
            return sf::Vector2f();
        }
        bool isWall(int x,int y){
            return !(maze[y][x] != 1);
        }
};