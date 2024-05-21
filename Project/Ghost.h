<<<<<<< HEAD

#include <SFML/Graphics.hpp>
#ifndef GHOST_H
#define GHOST_H
#include "Entities.h"
#include "Pacman.h"

class Ghost : public Entities {
 private:
  int change = 0;
  int cellSize;
  int gridSize;
  float speed = 250.0f;
  sf::Texture ghostTexture;
  sf::Sprite ghost;

 public:
  Ghost();
  Ghost(sf::RenderWindow& window, int gs, int x, int y, std::string color);

   int getChange();
  int getCellSize();
  int getGridSize();
  sf::Texture getGhostTexture();
  sf::Sprite getGhost();

  virtual void draw(sf::RenderWindow& window);

  virtual bool move (int direction, Maze maze, float time) override;

  virtual void setPosition(const sf::Vector2f& newPos);

  virtual sf::Vector2f getPosition() const;

  sf::Vector2f getMovement(int change, float fSpeed);

  virtual float getSpeed() override;

  bool checkDeath(Pacman p);
};

=======
#ifndef GHOST_H
#define GHOST_H

#include <SFML/Graphics.hpp>
#include "Entities.h"
#include "Maze.h"
#include "Pacman.h"
#include <iostream>

class Ghost : public Entities {
    private:
        int change = 0;
        int cellSize;
        int gridSize;
        float speed = 250.0f;
        sf::Texture ghostTexture;
        sf::Sprite ghost;

    public:
        Ghost();
        Ghost(sf::RenderWindow& window, int gs, int x, int y, std::string color);
        void draw(sf::RenderWindow& window) override;
        bool move(int direction, Maze maze, float time) override;
        void setPosition(const sf::Vector2f& newPos) override;
        sf::Vector2f getPosition() const override;
        sf::Vector2f getMovement(int change, float fSpeed);
        float getSpeed();
        bool checkDeath(Pacman p);
};

>>>>>>> abcc5d7128c62abc84e12feeadabe743d0576259
#endif