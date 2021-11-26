# CPPND: Capstone Unicorn Run Game

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
* SDL2_Image
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools](https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)

## Basic Build Instructions

1. Clone this repo.
2. Make a build directory in the top level directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./UnicornGame`.


## CC Attribution-ShareAlike 4.0 International


Shield: [![CC BY-SA 4.0][cc-by-sa-shield]][cc-by-sa]

This work is licensed under a
[Creative Commons Attribution-ShareAlike 4.0 International License][cc-by-sa].

[![CC BY-SA 4.0][cc-by-sa-image]][cc-by-sa]

[cc-by-sa]: http://creativecommons.org/licenses/by-sa/4.0/
[cc-by-sa-image]: https://licensebuttons.net/l/by-sa/4.0/88x31.png
[cc-by-sa-shield]: https://img.shields.io/badge/License-CC%20BY--SA%204.0-lightgrey.svg
