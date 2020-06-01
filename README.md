# Udacity C++ Nanodegree Capstone Snake Game

## About

This is the final capstone project in the [Udacity C++ Nanodegree Program](https://www.udacity.com/course/c-plus-plus-nanodegree--nd213). 

The poject chosen was the snake game that was provided as the starter code provided by udacity in this [repo] (https://github.com/udacity/CppND-Capstone-Snake-Game) and inspired by [this](https://codereview.stackexchange.com/questions/212296/snake-game-in-c-with-sdl) StackOverflow post.

<img src="snake_game.gif"/>

## Project Structure
Following are the main files containing classes along with their functionalities

- `renderer.cpp` and `renderer.h`: The Renderer component takes the game object and renders the game using the SDL library

- `game.cpp` and `game.h`: This is the game component which takes care of the important dynamics of the game pertaining to placements of the food item, and other game elements like the snake.

- `snake.cpp` and `snake.h`: These files contain the snake component that is the main object that interacts in the game and has important functionalities to grow and move around using controller component

- `controller.cpp` and `controller.h`: The controller component sets the way the keybpard controls are linked with the snake's movements.

- `metadata.h`: The metadata component investigates system information and stores them as class members

- `main.cpp`: The code that is called upon execution. It first instantiates an object each for the above mentioned components. It loops through each component updating, fetching and displaying data.

When the game is run, it first uses the metadata to display information about the platform the game is being run on.

Then the player gets to choose difficult by setting the starting speed of the snake. Once the valid entry is registered, the game window is displayed and the user can play the game using arrow keys as input. The game ends if the snake dies and the players score is displayed along with the high score.

## Dependencies for Running Locally
* cmake >= 3.7
  * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1 (Linux, Mac), 3.81 (Windows)
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* SDL2 >= 2.0
  * All installation instructions can be found [here](https://wiki.libsdl.org/Installation)
  * Note that for Linux, an `apt` or `apt-get` installation is preferred to building from source.
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools](https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)

## Basic Build Instructions

1. Clone this repo.
2. Make a build directory in the top level directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./SnakeGame`.

## Rubric points addressed
### Loops, Functions, I/O
| Rubric point  | Location |
| ------------- | ------------- |
| The project demonstrates an understanding of C++ functions and control structures.  |   There are multiple functions in each component to achieve modularity
| The project reads data from a file and process the data, or the program writes data to a file.  | the highscore feature in [metadata.h](https://github.com/pranavbajoria93/Udacity-CppND-Capstone-Snake-Game/blob/c380204dc0b492070db858c416957c7980ac0bbd/src/metadata.h#L36)
The project accepts user input and processes the input.  |  choose difficulty feature in [Snake.cpp line 95](https://github.com/pranavbajoria93/Udacity-CppND-Capstone-Snake-Game/blob/c380204dc0b492070db858c416957c7980ac0bbd/src/snake.cpp#L95)

### Object Oriented Programming
| Rubric point  | Location |
| ------------- | ------------- |
| The project uses Object Oriented Programming techniques.  |   Yes
Classes use appropriate access specifiers for class members. | [thisPlatform private data member](https://github.com/pranavbajoria93/Udacity-CppND-Capstone-Snake-Game/blob/c380204dc0b492070db858c416957c7980ac0bbd/src/metadata.h#L30)
Class constructors utilize member initialization lists. | Yes
Classes abstract implementation details from their interfaces. | platform info is automatically fetched upon class initialization of metadata class
Classes encapsulate behavior. | All functionalities related to the data w.r.t the game is encapsulated in metadata class

### Memory Management
| Rubric point  | Location |
| ------------- | ------------- |
| The project makes use of references in function declarations.  |   [metadata.h line 61](https://github.com/pranavbajoria93/Udacity-CppND-Capstone-Snake-Game/blob/c380204dc0b492070db858c416957c7980ac0bbd/src/metadata.h#L61)
The project uses destructors appropriately. | [Renderer](src/Renderer.cpp) and [Beeper](src/Beeper.cpp)
The project uses scope / Resource Acquisition Is Initialization (RAII) where appropriate. | Yes, check all the files
The project follows the Rule of 5. | Yes, check all the files


## Rubric explained

1. There are multiple functions in each component to achieve modularity
2. The reading and writing to a data stream is achieved by adding the highscore feature in the `metadata` file.
3. Game's start speed is set by getting command line input from user
4. As explained in the about section, the entire project is well structured with various classes. All concepts like encapsulation, abstraction, inheritance and polymorphism are displayed.
5. The project makes use of references in function declarations- setHighScore() in metaData.h.
