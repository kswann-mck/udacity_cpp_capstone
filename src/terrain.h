#ifndef TERRAIN_H
#define TERRAIN_H

#include <vector>
#include "SDL.h"
#include "player.h"

/*
Class to represent the terrain blocks, and operations related to them
*/
class Terrain {
 public:

  Terrain(const std::size_t grid_width, const std::size_t grid_height,
          const std::size_t screen_width, const std::size_t screen_height)
      : grid_width(grid_width),
        grid_height(grid_height),
        screen_width(screen_width),
        screen_height(screen_height) {
          block_width = screen_width / grid_width;
          block_height = screen_height / grid_height;
          max_height = grid_height / 2;
          min_height = 1;
          last_column_height = 0;
        };

  int NextColumnHeight(); // get the height of the next column.
  std::vector<SDL_Point> NewColumn(int height, int current_width);
  void Generate(); // generates a random board of terrain blocks
  void Advance(Player &player, SDL_Point &food); // moves the board forward one column
  void CollidesWith(Player &player); //detects if the player bounding box is colliding with any terrain blocks
  void PushToTop(float &x0, float &y0, float width, float height);

  std::vector<std::vector<SDL_Point>> terrain_blocks; // 2d array of points to hold blocks

 private:
  const std::size_t screen_width;
  const std::size_t screen_height;
  const std::size_t grid_width;
  const std::size_t grid_height;
  std::size_t block_width;
  std::size_t block_height;
  int max_height;
  int min_height;
  int last_column_height;
  int advance_n{0};
};

#endif