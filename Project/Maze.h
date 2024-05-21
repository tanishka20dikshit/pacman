#ifndef MAZE_H
#define MAZE_H
#include "Elements.h"
#include <SFML/Graphics.hpp>
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
  int** maze;

 public:
  Maze();
  Maze(int gs, int width);
  int getGridSize() ;
  int getCellSize() ;
  int** getMaze();
  sf::Texture getRightCornerTexture();
  sf::Texture getLeftCornerTexture();
  sf::Texture getBottomRightCornerTexture() ;
  sf::Texture getBottomLeftCornerTexture() ;
  sf::Texture getTopLineCornerTexture();
  sf::Texture getLeftLineCornerTexture() ;
  virtual void draw(sf::RenderWindow& window);

  void reset();
  bool isWall(int x, int y);
  void setupMaze();
};
#endif