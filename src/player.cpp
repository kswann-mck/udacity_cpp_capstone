#include "player.h"
#include <cmath>
#include <iostream>
#include <algorithm>



void Player::Update() {
  SDL_Point prev_cell{
      static_cast<int>(position_x),
      static_cast<int>(position_y)};  // We first capture the position's cell before updating.
  UpdatePosition();
  SDL_Point current_cell{
      static_cast<int>(position_x),
      static_cast<int>(position_y)};  // Capture the position cell after updating.
}

void Player::UpdatePosition() {

  position_y += velocity_y;
  position_x += velocity_x;

  velocity_x *= 0.95; // friction
  velocity_y += 0.01;

  if (position_x < 0) {
    position_x = 0;
    velocity_x = 0;
  }
  else if (position_x > grid_width-width) {
    position_x = (float)grid_width-width;
  }
  if (position_y < 0) {
    position_y = 0;
    velocity_y = 0;
  }
  else if (position_y > grid_height-height) {
    position_y = (float)grid_height-height;
    velocity_y = 0;
  }
}

// Inefficient method to check if cell is occupied by player.
bool Player::PlayerCell(int x, int y) {
  if (x == static_cast<int>(position_x) && y == static_cast<int>(position_y)) {
    return true;
  }
  return false;
}