Pacman Game - README

Overview
Welcome to the Pacman game developed using the SFML library! This project is a classic arcade game where you control Pacman, navigate through a maze, eat all the dots, and avoid the ghosts. This README will guide you through the setup, controls, and additional information about the project.

Table of Contents
1.Features
2.Requirements
3.Installation
4.Running the Game
5.Controls
6.Game Rules
7.Project Structure
8.Contributing
9.License
10.Acknowledgements


Features
Classic Pacman gameplay
Smooth animations and graphics using SFML
Multiple levels with increasing difficulty
High score tracking
Sound effects and background music



Requirements
To build and run this game, you need the following:
1.A C++ compiler (GCC, Clang, MSVC, etc.)
2.SFML library (Simple and Fast Multimedia Library)



Installation
SFML Setup
- Download and install the SFML library from the official website.
- Follow the SFML setup guide for your specific operating system and development environment.
- Clone the Repository
= Clone the project repository from GitHub:
git clone [https://github.com/yourusername/pacman-game.git](https://github.com/AxisGe0/pacman.git)
cd pacman

Build the Project
Open the Makefile and ensure the paths to the SFML library and include files are correctly set.
Build the project using make:
make


Running the Game
After successfully building the project, you can run the game executable:
./test_runner


Controls
Arrow Keys: Move Pacman (Up, Down, Left, Right)


Game Rules
Navigate Pacman through the maze to eat all the dots cherrys.
Avoid the ghosts; if they catch Pacman, you lose a life.
Eating a power pellet will allow Pacman to eat the ghosts for a short period.
The game is over when Pacman loses all lives.


Project Structure
makefile

Pacman-Game/
├── images/             # Game assets (textures)
├── sounds/             # Game assets (sounds)
├── testFiles/          # Unit test  files
├── Makefile            # Makefile for building the project
└── README.md           # This README file


Contributing
We welcome contributions to this project! To contribute:

Fork the repository.
Create a new branch (git checkout -b feature-branch).
Commit your changes (git commit -am 'Add new feature').
Push to the branch (git push origin feature-branch).
Create a new Pull Request.


License
This project is licensed under the MIT License. See the LICENSE file for details.

Acknowledgements
Inspired by the classic Pacman game by Namco.
Developed using the SFML library.
Happy gaming!

