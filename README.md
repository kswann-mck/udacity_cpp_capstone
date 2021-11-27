# Unicorn Run Game
## Udacity C++ Nano Degree: Capstone Project

by Kitson Swann

## Project Summary

For my capstone I started with the [starter Snake Game](https://github.com/udacity/CppND-Capstone-Snake-Game), and modified it to create a new game. 
I wanted to make something that would be fun for my kids, so I modified the snake game and turned it into a side scrolling Mario style game, 
where you move a Unicorn along terrain, while collecting rainbows. 
You get points for each rainbow you capture, and if you fall down a hole, the game ends. 
As you move towards the right, the terrain is generated randomly by the game, allowing you to basically continuously run forever. 
To make this game I adapted the Snake Game code in a number of ways including:

- Changing the player into a unicorn without an expanding body and adding a graphic image overlay.
- Adding a rainbow image for the food.
- Adding a terain class that represents the terrain blocks that form the ground.
- Implementing some simple physics for the environment including velocity of the unicorn, jumping, gravity, friction and collision detection with the terain blocks.

<img src="unicorn.gif"/>

## Code Structure:

| Files                       | Purpose                                                                              |
| --------------------------- | ------------------------------------------------------------------------------------ |
| main.cpp                    | Main orchestrator that initializes the renderer and the game and runs it.            |
| controller.h/controller.cpp | Class that handles input from the user to move the character.                        |
| game.h/game.cpp             | Class that handles the main update/render loop operation of the game.                |
| player.h/player.cpp         | Class represending the player's position, velocity, health and size.                 |
| renderer.h/renderer.cpp     | Class containing the logic for rendering the player, terrain and food to the display |
| terrain.h/terrain.cpp       | Class representing the terrain blocks, and their generation and movement.            |

## Behaviour

After building according to the instructions below, when you run `./UnicornRunGame` a game
window will open and load the terrain, unicorn character and food. You can move the 
unicorn left and right using the arrow keys, and jump/fly using the up arrow. Gravity will
bring the unicorn back down if you release the jump key, and friction will slow your movement 
if you release the left and right arrows. If you fall down a hole, the game ends. For each
rainbow you catch, you get a point. As you move to the right, new terrain is generated randomly.

## Project Rubric Points

Each ruberic point addressed has a checkbox beside it and a link if applicable to example code 
that satisfies the requirement.

### Required

- A README with instructions is included with the project
    - [x] [The README is included with the project](#unicorn-run-game) and has [instructions for building/running](#dependencies-for-running-locally) the project.
    - [x] If any additional libraries are needed to run the project, these are indicated with cross-platform installation instructions.
- The README indicates which project is chosen.
    - [x] The README [describes the project you have built](#project-summary).
    - [x] The README also [indicates the file and class structure](#code-structure), along with the [expected behavior](#behaviour) or output of the program.
    - [x] The README includes information about each rubric point addressed.
- The README indicates which rubric points are addressed. 
    - [x] The README also indicates where in the code (i.e. files and line numbers) that the rubric points are addressed.
- The submission must compile and run.
    - [x] The project code must compile and run without errors.
    - [x] We strongly recommend using cmake and make, as provided in the starter repos.

### Optional

#### Loops, Functions, I/O
- The project demonstrates an understanding of C++ functions and control structures.
    - [x] A variety of control structures are used in the project.
      - Example loop in [terrain.cpp](src/terrain.cpp) lines 74 and 88.
    - [x] The project code is clearly organized into functions.
      - Example functions in [terrain.cpp](src/terrain.cpp) lines 6, 42, 70, 82, 119.
- The project reads data from a file and process the data, or the program writes data to a file.
    - [x] The project [reads data from an external file] or writes data to a file as part of the necessary operation of the program.
      - In [renderer.cpp](src/renderer.cpp) line 108 on, external image files are loaded into the game.
- The project accepts user input and processes the input.
    - [x] The project accepts input from a user as part of the necessary operation of the program.
      - This can be seen in the `Controller::HandleInput()` function in [controller.cpp](src/controller.cpp)

#### Object Oriented Programming
- The project uses Object Oriented Programming techniques.
    - [x] The project code is organized into classes with class attributes to hold the data, and class methods to perform tasks.
      - An example of this is the newly defined [terrain.h](src/terrain.h) file which is a class representing the terrain.
- Classes use appropriate access specifiers for class members.
    - [x] All class data members are explicitly specified as public, protected, or private.
- Class constructors utilize member initialization lists.
    - [x] All class members that are set to argument values are initialized through member initialization lists.
      - Example can be seen in the `Player` constructor in [player.h](src/player.h)
- Classes abstract implementation details from their interfaces.
    - [x] All class member functions document their effects, either through function names, comments, or formal documentation. Member functions do not change program state in undocumented ways.
      - See [terrain.cpp](src/terrain.cpp) as an example.
- Classes encapsulate behavior.
    - [x] Appropriate data and functions are grouped into classes. Member data that is subject to an invariant is hidden from the user. State is accessed via member functions.
      - See [terrain.h](src/terrain.h) and [terrain.cpp](src/terrain.cpp) for an example.
- Classes follow an appropriate inheritance hierarchy.
    - Inheritance hierarchies are logical. Composition is used instead of inheritance when appropriate. Abstract classes are composed of pure virtual functions. Override functions are specified.
- Overloaded functions allow the same function to operate on different parameters.
    - One function is overloaded with different signatures for the same function name.
- Derived class functions override virtual base class functions.
    - One member function in an inherited class overrides a virtual base class member function.
- Templates generalize functions in the project.
    - One function is declared with a template that allows it to accept a generic parameter.

#### Memory Management
- The project makes use of references in function declarations.
    - [x] At least two variables are defined as references, or two functions use pass-by-reference in the project code.
      - In the [terrain.h](src/terrain.cpp) line 28, the `void Advance(Player &player, SDL_Point &food)` function takes a reference to the player and food point.
      - Also on line 29 of the same file the `void CollidesWith(Player &player)` takes a reference to the player
      in order to check for collisions between the player and the terrain, and adjust the player position accordingly.
- The project uses destructors appropriately.
    - At least one class that uses unmanaged dynamically allocated memory, along with any class that otherwise needs to modify state upon the termination of an object, uses a destructor.
- The project uses scope / Resource Acquisition Is Initialization (RAII) where appropriate.
    - The project follows the Resource Acquisition Is Initialization pattern where appropriate, by allocating objects at compile-time, initializing objects when they are declared, and utilizing scope to ensure their automatic destruction.
- The project follows the Rule of 5.
    - For all classes, if any one of the copy constructor, copy assignment operator, move constructor, move assignment operator, and destructor are defined, then all of these functions are defined.
- The project uses move semantics to move data, instead of copying it, where possible.
    - For classes with move constructors, the project returns objects of that class by value, and relies on the move constructor, instead of copying the object.
- The project uses smart pointers instead of raw pointers.
    - The project uses at least one smart pointer: unique_ptr, shared_ptr, or weak_ptr. The project does not use raw pointers.

#### Concurrency
- The project uses multithreading.
    - The project uses multiple threads in the execution.
- A promise and future is used in the project.
    - A promise and future is used to pass data from a worker thread to a parent thread in the project code.
- A mutex or lock is used in the project.
    - A mutex or lock (e.g. std::lock_guard or `std::unique_lock) is used to protect data that is shared across multiple threads in the project code.
- A condition variable is used in the project.
    - A std::condition_variable is used in the project code to synchronize thread execution.


## Dependencies for Running Locally
* cmake >= 3.7
  * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1 (Linux, Mac), 3.81 (Windows)
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* SDL2 >= 2.0
  * All installation instructions can be found [here](https://wiki.libsdl.org/Installation)
  >Note that for Linux, an `apt` or `apt-get` installation is preferred to building from source. 
* SDL2_Image >= 2.0
  * All installation instructions can be found [here](https://www.libsdl.org/projects/SDL_image/)
  * For linux I recommend following the instructions [here](https://lazyfoo.net/tutorials/SDL/06_extension_libraries_and_loading_other_image_formats/linux/index.php)
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools](https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)

## Basic Build Instructions

1. Clone this repo.
2. Make a build directory in the top level directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./UnicornRunGame`.

Note that this has been tested in the Ubuntu workspace provided by udacity. Here is proof that it works there:

<img src="running_in_workspace.gif"/>

## CC Attribution-ShareAlike 4.0 International


Shield: [![CC BY-SA 4.0][cc-by-sa-shield]][cc-by-sa]

This work is licensed under a
[Creative Commons Attribution-ShareAlike 4.0 International License][cc-by-sa].

[![CC BY-SA 4.0][cc-by-sa-image]][cc-by-sa]

[cc-by-sa]: http://creativecommons.org/licenses/by-sa/4.0/
[cc-by-sa-image]: https://licensebuttons.net/l/by-sa/4.0/88x31.png
[cc-by-sa-shield]: https://img.shields.io/badge/License-CC%20BY--SA%204.0-lightgrey.svg
