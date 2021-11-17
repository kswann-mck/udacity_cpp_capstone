#ifndef PLAYER_H
#define PLAYER_H

#include <vector>
#include "SDL.h"

class Player {
 public:
  enum class Direction { kUp, kDown, kLeft, kRight };

  Player(int grid_width, int grid_height)
      : grid_width(grid_width),
        grid_height(grid_height),
        position_x(0),
        position_y(0) {}

  void Update();

  bool PlayerCell(int x, int y);

  Direction direction = Direction::kUp;

  float velocity_x{0.0};
  float velocity_y{0.0};
  bool alive{true};
  float position_x;
  float position_y;
  float width{0.8};
  float height{0.8};

 private:
  void UpdatePosition();
  int grid_width;
  int grid_height;
};

#endif