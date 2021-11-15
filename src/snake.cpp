#include "snake.h"
#include <cmath>
#include <iostream>
#include <algorithm>



void Snake::Update() {
  SDL_Point prev_cell{
      static_cast<int>(head_x),
      static_cast<int>(
          head_y)};  // We first capture the head's cell before updating.
  UpdateHead();
  SDL_Point current_cell{
      static_cast<int>(head_x),
      static_cast<int>(head_y)};  // Capture the head's cell after updating.
}

void Snake::UpdateHead() {

  head_y += velocity_y;
  head_x += velocity_x;

  velocity_x *= 0.95; // friction
  velocity_y += 0.01;

  if (head_x < 0) {
    head_x = 0;
    velocity_x = 0;
  }
  else if (head_x > grid_width-width) {
    head_x = (float)grid_width-width;
    //velocity_x = 0;
  }
  if (head_y < 0) {
    head_y = 0;
    velocity_y = 0;
  }
  else if (head_y > grid_height-height) {
    head_y = (float)grid_height-height;
    velocity_y = 0;
  }
}

// Inefficient method to check if cell is occupied by snake.
bool Snake::SnakeCell(int x, int y) {
  if (x == static_cast<int>(head_x) && y == static_cast<int>(head_y)) {
    return true;
  }
  return false;
}