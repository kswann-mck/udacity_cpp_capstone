#ifndef SNAKE_H
#define SNAKE_H

#include <vector>
#include "SDL.h"

class Snake {
 public:
  enum class Direction { kUp, kDown, kLeft, kRight };

  Snake(int grid_width, int grid_height)
      : grid_width(grid_width),
        grid_height(grid_height),
        head_x(0),
        head_y(0) {}

  void Update();

  bool SnakeCell(int x, int y);

  Direction direction = Direction::kUp;

  float velocity_x{0.0};
  float velocity_y{0.0};
  bool alive{true};
  float head_x;
  float head_y;
  float width{0.8};
  float height{0.8};

 private:
  void UpdateHead();
  int grid_width;
  int grid_height;
};

#endif