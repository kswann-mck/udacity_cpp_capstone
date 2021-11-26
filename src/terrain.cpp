#include "terrain.h"
#include <cmath>
#include <iostream>
#include <algorithm>

/*
As the player moves to the right, new terrain columns are added to 
the right hand side, and the position of the player, food and terrain
blocks are shifted accordingly. Blocks that are no long on the screen to the left
are removed
*/
void Terrain::Advance(Player &player, SDL_Point &food) {
  if (advance_n % 10 == 0) {
    if (player.position_x >= grid_width-6) {

      float move_distance = player.velocity_x;

      // add a new column
      int next_height = Terrain::NextColumnHeight();
      std::vector<SDL_Point> terrain_column = Terrain::NewColumn(next_height, grid_width+1);
      int last_column_height = terrain_column.size();
      terrain_blocks.push_back(terrain_column);

      // move the x position of all the current blocks back 1 grid width
      for (int column = 0; column < terrain_blocks.size(); column++){
        for (int height = 0; height < terrain_blocks[column].size(); height++) {
          terrain_blocks[column][height].x -= move_distance;
        }
      }

      // move the player back one grid width
      player.position_x -= move_distance;
      //player.velocity_x *= 0.5;

      // move the food back one move distance
      food.x -= move_distance;

      // if the first column is now off the screen
      if ((terrain_blocks[0][0].x+1) <= 0) {
        // remove the first column
        terrain_blocks.erase(terrain_blocks.begin());
      }
    }
  }
  advance_n += 1;
}

/*
Generates an int representing the height of the next column to be generated in
the terrain
*/
int Terrain::NextColumnHeight() {
  int up_down = rand() % 3 -1; // random -1, 0, 1
  int next_height = last_column_height + up_down;

  // each row must have a base block
  if (next_height < min_height) {
    next_height = min_height;
  }

  // the blocks can't be higher than half the hight
  if (next_height > max_height) {
    next_height = max_height;
  }

  return next_height;
}

/*
Generates the next column which is a vector of SDL_Point objects
*/
std::vector<SDL_Point> Terrain::NewColumn(int height, int current_width) {
  std::vector<SDL_Point> terrain_column;
  for (int hi = grid_height - 1; hi >= grid_height-height; hi--) {
      SDL_Point terrain_block{
        static_cast<int>(current_width),
        static_cast<int>(hi)};
      terrain_column.push_back(terrain_block);
  }
  return terrain_column;
}

/*
Generates the initial terrain columns to fill the screen on initialization
*/
void Terrain::Generate() {
    int next_height = 0;
    std::vector<SDL_Point> terrain_column;

    for (int wi = 0; wi < grid_width; wi++) {
      next_height = Terrain::NextColumnHeight();
      terrain_column = Terrain::NewColumn(next_height, wi);
      last_column_height = terrain_column.size();
      terrain_blocks.push_back(terrain_column);
    }
}

/*
Checks if the player has collided with any of the terrain blocks and adjusts the
player position and velocity such that the player is kept to the outside of the terrain blocks.
*/
void Terrain::CollidesWith(Player &player) {
  float x0 = player.position_x;
  float x1 = x0 + player.width;
  float y0 = player.position_y;
  float y1 = y0 + player.height;
  
  for (std::vector<SDL_Point> column: terrain_blocks) {
    for (SDL_Point point: column) {
      float px0 = point.x;
      float px1 = (px0 + 1);
      float py0 = point.y;
      float py1 =(py0 + 1);

      float y_adjustment;
      float x_adjustment;
      
      // top contact
      if (y1 >= py0 && y1 < py1 && (x1 >= px0 && x1 < px1 || x0 > px0 && x0 <= px1 || x0 > px0 && x1 < px1)) { // we've crossed from the left
        player.position_y = (py0-player.height); // push above the block surface
        player.velocity_y = 0;

      // left contact
      } else if (x1 >= px0 && x1 < px1 && (y1 > py0 && y1 <= py1 || y0 > py0 && y0 <= py1 || y0 > py0 && y1 < py1)) { // we've crossed from the left
        player.position_x = (px0-player.width)-0.0001; // push to the left
        player.velocity_x = 0;
      }
      // right contact
      else if (x0 > px0 && x0 <= px1 && (y1 > py0 && y1 <= py1 || y0 > py0 && y0 <= py1 || y0 > py0 && y1 < py1)) { // we've crossed from the left
        player.position_x = px1+0.0001; // push to the right
        player.velocity_x = 0;
      }

    }
  }
}

/*
After a randomly generated position for the next food item is created,
if it interferes with the terrain blocks, it is pushed "up" until it's at the top of
the column
*/
void Terrain::PushToTop(float &x0, float &y0, float width, float height) {

  float x1 = x0 + width;
  float y1 = y0 + height;

  // check for collision and adjust wrt terrain
  for (std::vector<SDL_Point> column: terrain_blocks) {
    for (SDL_Point point: column) {
      float px0 = point.x;
      float px1 = (px0 + 1);
      float py0 = point.y;
      float py1 =(py0 + 1);
      
      // if any part of the food position lays on the same x position as the column
      if ((x0 >= px0 && x0 <= px1) || (x1 >= px0 && x1 <= px1)) {
        // push the position up to the top of the block
        if (y1 >= py0) {
          y1 = py0-0.0001;
          y0 = y1-height;
        }
      }
    }
  }
}

