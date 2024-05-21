#include "Game.h"
<<<<<<< HEAD

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <fstream>
#include <iostream>

#include "Cherry.h"
#include "Collectables.h"
#include "Elements.h"
#include "Entities.h"
#include "Ghost.h"
#include "Maze.h"
#include "Pacman.h"
#include "Pellets.h"
#include "SpeedDot.h"

Game::Game(int h, int w)
    : height(h),
      width(w),
      window(sf::VideoMode(w, h), "Pacman"),
      maze(20, width),
      player(window, 20),
      pellets(20, width, maze.getMaze()),
      speedDot(20, width, maze.getMaze()),
      cherry(20, width, maze.getMaze()) {
  player.setPosition(sf::Vector2f(740, 740));
  ghosts[0] = new Ghost(window, 20, 1, 1, "red");
  ghosts[1] = new Ghost(window, 20, 6, 18, "blue");
  ghosts[2] = new Ghost(window, 20, 8, 7, "green");
  ghosts[3] = new Ghost(window, 20, 16, 1, "yellow");

  /// Details
  font.loadFromFile("CrackMan.TTF");
  score.setFont(font);
  score.setCharacterSize(20);
  score.setFillColor(sf::Color::Yellow);
  score.setStyle(sf::Text::Bold);
  score.setPosition(30, 330);
  livesText.setFont(font);
  livesText.setCharacterSize(20);
  livesText.setFillColor(sf::Color::Yellow);
  livesText.setStyle(sf::Text::Bold);
  livesText.setPosition(650, 330);

  /// Start Screen
  title = sf::Text("PACMAN", font, 100);
  title.setFillColor(sf::Color::Yellow);
  sf::FloatRect titleBounds = title.getLocalBounds();
  title.setOrigin(titleBounds.left + titleBounds.width / 2.0f,
                  titleBounds.top + titleBounds.height / 2.0f);
  title.setPosition(window.getSize().x / 2.0f, 200);

  playText = sf::Text("PLAY GAME", font, 30);
  playText.setFillColor(sf::Color::White);
  sf::FloatRect textBounds = playText.getLocalBounds();
  playText.setOrigin(textBounds.left + textBounds.width / 2.0f,
                     textBounds.top + textBounds.height / 2.0f);
  playText.setPosition(window.getSize().x / 2.0f, 500);

  highScoreText = sf::Text("HIGH SCORE: 0", font, 20);
  highScoreText.setFillColor(sf::Color::White);
  sf::FloatRect highScoreTextBounds = highScoreText.getLocalBounds();
  highScoreText.setPosition(10, 15);

  /// Sound
  buffer.loadFromFile("sounds/sound_siren.wav");
  siren.setBuffer(buffer);
  buffer_ready.loadFromFile("sounds/sound_ready.mp3");
  sound_ready.setBuffer(buffer_ready);
  buffer_die.loadFromFile("sounds/sound_die.mp3");
  sound_die.setBuffer(buffer_die);
  siren.setLoop(true);

  /// High score
  std::ifstream file("highscore.txt");
  file >> highScore;
}
sf::Font Game::getFont() { return this->font; };
sf::Text Game::getScore() { return this->score; };
sf::Text Game::getLivesText() { return this->livesText; };
sf::Text Game::getTitle() { return this->title; };
sf::Text Game::getPlayText() { return this->playText; };
sf::Text Game::getHighScoreText() { return this->highScoreText; };
int Game::getWidth() { return this->width; };
int Game::getHeight() { return this->height; };
int Game::getHighScore() { return this->highScore; };
int Game::getPoints() { return this->points; };
int Game::getLives() { return this->lives; };
int Game::getDirection() { return this->direction; };
bool Game::getIsAlive() { return this->isAlive; };
bool Game::getCanGameStart() { return this->canGameStart; };
bool Game::getIsDying() { return this->isDying; };
void Game::run() {
  auto sTime = std::chrono::high_resolution_clock::now();
  while (window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
        window.close();
      }
    }
    Game::handleClicks();
    Game::handleKeys();
    auto cTime = std::chrono::high_resolution_clock::now();
    std::chrono::duration<float> elapsed = cTime - sTime;
    sTime = cTime;
    float time = elapsed.count();
    if (isAlive and !isDying) {
      if (!player.move(direction, maze, time)) {
        direction = 4;
      }
      for (int i = 0; i < 4; ++i) {
        ghosts[i]->move(0, maze, time);
        if (ghosts[i]->checkDeath(player)) {
          lives--;
          if (lives == 0) {
            isDying = true;
            clock_die.restart();
          } else {
            player.setPosition(sf::Vector2f(740, 740));
          }
        };
      }
      points += pellets.addPoints(player);
      points += speedDot.addPoints(player);
      points += cherry.addPoints(player);
      score.setString("P* " + std::to_string(points));
      livesText.setString("Lives " + std::to_string(lives));
    }
    if (isDying) {
      if (clock_die.getElapsedTime().asSeconds() > 1.5) {
        isDying = false;
        Game::resetGame();
      } else {
        if (sound_die.getStatus() != sf::Sound::Playing) {
          siren.stop();
          sound_die.play();
        }
      }
    }
    Game::render();
  }
}

void Game::handleKeys() {
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
    direction = 0;
  } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
    direction = 1;
  } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
    direction = 2;
  } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
    direction = 3;
  }
}

void Game::handleClicks() {
  if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && !isAlive && canGameStart) {
    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
    if (playText.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
      isAlive = true;
      siren.play();
    }
  }
}

void Game::render() {
  window.clear();
  if (!isAlive) {
    window.draw(title);
    window.draw(highScoreText);
    highScoreText.setString("HIGH SCORE: " + std::to_string(highScore));
    if (!canGameStart) {
      if (sound_ready.getStatus() != sf::Sound::Playing) {
        sound_ready.play();
      }
      if (clock.getElapsedTime().asSeconds() > 4) {
        canGameStart = true;
      }
    } else {
      window.draw(playText);
    }
  } else {
    maze.draw(window);
    for (int i = 0; i < 4; ++i) {
      ghosts[i]->draw(window);
    }
    pellets.draw(window);
    speedDot.draw(window);
    cherry.draw(window);
    player.draw(window);
    window.draw(score);
    window.draw(livesText);
  }
  window.display();
}

void Game::resetGame() {
  isAlive = false;
  canGameStart = false;
  clock.restart();
  lives = 3;
  direction = 0;
  if (points > highScore) {
    highScore = points;
    std::ofstream("highscore.txt") << highScore;
  }
  points = 0;
  maze.reset();
  speedDot.placeRandomly();
  cherry.placeRandomly();
  for (int i = 0; i < 4; ++i) {
    delete ghosts[i];
  }
  ghosts[0] = new Ghost(window, 20, 1, 1, "red");
  ghosts[1] = new Ghost(window, 20, 6, 18, "blue");
  ghosts[2] = new Ghost(window, 20, 8, 7, "green");
  ghosts[3] = new Ghost(window, 20, 16, 1, "yellow");
  player.setPosition(sf::Vector2f(740, 740));
}

Game::~Game() {
  for (int i = 0; i < 4; ++i) {
    delete ghosts[i];
  }
  for (int i = 0; i < 20; ++i) {
    delete maze.getMaze()[i];
  }
  delete[] maze.getMaze();
  }
=======
Game::Game(int h, int w) :
    height(h),
    width(w),
    window(sf::VideoMode(w,h), "Pacman"),
    maze(20, width),
    player(window, 20),
    pellets(20,width,maze.getMaze()),
    speedDot(20,width,maze.getMaze()),
    cherry(20,width,maze.getMaze())
{
    player.setPosition(sf::Vector2f(740, 740));
    ghosts[0] = new Ghost(window, 20, 1, 1,"red");
    ghosts[1] = new Ghost(window, 20, 6, 18,"blue");
    ghosts[2] = new Ghost(window, 20, 8, 7,"green");
    ghosts[3] = new Ghost(window, 20, 16, 1,"yellow");

    /// Details
    font.loadFromFile("CrackMan.TTF");
    score.setFont(font);
    score.setCharacterSize(20);
    score.setFillColor(sf::Color::Yellow);
    score.setStyle(sf::Text::Bold);
    score.setPosition(30,330);
    livesText.setFont(font);
    livesText.setCharacterSize(20);
    livesText.setFillColor(sf::Color::Yellow);
    livesText.setStyle(sf::Text::Bold);
    livesText.setPosition(650,330);

    /// Start Screen
    title = sf::Text ("PACMAN", font, 100);
    title.setFillColor(sf::Color::Yellow);
    sf::FloatRect titleBounds = title.getLocalBounds();
    title.setOrigin(titleBounds.left + titleBounds.width / 2.0f, titleBounds.top + titleBounds.height / 2.0f);
    title.setPosition(window.getSize().x / 2.0f, 200);

    playText = sf::Text ("PLAY GAME", font, 30);
    playText.setFillColor(sf::Color::White);
    sf::FloatRect textBounds = playText.getLocalBounds();
    playText.setOrigin(textBounds.left + textBounds.width / 2.0f, textBounds.top + textBounds.height / 2.0f);
    playText.setPosition(window.getSize().x / 2.0f, 500);

    highScoreText = sf::Text ("HIGH SCORE: 0", font, 20);
    highScoreText.setFillColor(sf::Color::White);
    sf::FloatRect highScoreTextBounds = highScoreText.getLocalBounds();
    highScoreText.setPosition(10, 15);

    /// Sound
    buffer.loadFromFile("sounds/sound_siren.wav");
    siren.setBuffer(buffer);
    buffer_ready.loadFromFile("sounds/sound_ready.mp3");
    sound_ready.setBuffer(buffer_ready);
    buffer_die.loadFromFile("sounds/sound_die.mp3");
    sound_die.setBuffer(buffer_die);
    siren.setLoop(true);
    
    /// High score
    std::ifstream file("highscore.txt");
    file >> highScore;
}

void Game::run() {
    auto sTime = std::chrono::high_resolution_clock::now();
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }
        handleClicks();
        handleKeys();
        auto cTime = std::chrono::high_resolution_clock::now();
        std::chrono::duration<float> elapsed = cTime - sTime;
        sTime = cTime;
        float time = elapsed.count();
        if(isAlive and !isDying){
            if (!player.move(direction, maze, time)) {
                direction = 4;
            }
            for (int i = 0; i < 4; ++i) {
                ghosts[i]->move(0, maze, time);
                if (ghosts[i]->checkDeath(player)){
                    lives--;
                    if(lives == 0){
                        isDying = true;
                        clock_die.restart();
                    }else{
                        player.setPosition(sf::Vector2f(740, 740));
                    }
                };
            }
            points += pellets.addPoints(player);
            points += speedDot.addPoints(player);
            points += cherry.addPoints(player);
            score.setString("P* " + std::to_string(points));
            livesText.setString("Lives " + std::to_string(lives));
        }
        if(isDying){
            if(clock_die.getElapsedTime().asSeconds() > 1.5){
                isDying = false;
                resetGame(); 
            }else{
                if(sound_die.getStatus() != sf::Sound::Playing){
                    siren.stop();
                    sound_die.play();
                }
            }
        }
        render();
    }
}

void Game::handleKeys() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        direction = 0;
    }else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        direction = 1;
    }else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        direction = 2;
    }else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        direction = 3;
    }
}

void Game::handleClicks() {
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && !isAlive && canGameStart) {
        sf::Vector2i mousePos = sf::Mouse::getPosition(window);
        if (playText.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
            isAlive = true; 
            siren.play();
        }
    }
}

void Game::render() {
    window.clear();
    if(!isAlive){
        window.draw(title);
        window.draw(highScoreText);
        highScoreText.setString("HIGH SCORE: " + std::to_string(highScore));
        if(!canGameStart){
            if(sound_ready.getStatus() != sf::Sound::Playing){
                sound_ready.play();
            }
            if(clock.getElapsedTime().asSeconds() > 4){
                canGameStart = true;
            }
        }else{
            window.draw(playText);
        }
    }else{
        maze.draw(window);
        for (int i = 0; i < 4; ++i) {
            ghosts[i]->draw(window);
        }
        pellets.draw(window);
        speedDot.draw(window);
        cherry.draw(window);
        player.draw(window);
        window.draw(score);
        window.draw(livesText);
    }
    window.display();
}

void Game::resetGame(){
    isAlive = false;
    canGameStart = false;
    clock.restart();
    lives = 3;
    direction = 0;
    if(points > highScore){
        highScore = points;
        std::ofstream("highscore.txt") << highScore;
    }
    points = 0;
    maze.reset();
    speedDot.placeRandomly();
    cherry.placeRandomly();
    for (int i = 0; i < 4; ++i) {
        delete ghosts[i];
    }
    ghosts[0] = new Ghost(window, 20, 1, 1,"red");
    ghosts[1] = new Ghost(window, 20, 6, 18,"blue");
    ghosts[2] = new Ghost(window, 20, 8, 7,"green");
    ghosts[3] = new Ghost(window, 20, 16, 1,"yellow");
    player.setPosition(sf::Vector2f(740, 740));
}

Game::~Game() {
    for (int i = 0; i < 4; ++i) {
        delete ghosts[i];
    }
}
>>>>>>> abcc5d7128c62abc84e12feeadabe743d0576259
