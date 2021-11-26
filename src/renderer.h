#ifndef RENDERER_H
#define RENDERER_H

#include <vector>
#include "SDL.h"
#include "SDL_image.h"
#include "player.h"
#include "terrain.h"

class Renderer {
 public:
  Renderer(const std::size_t screen_width, const std::size_t screen_height,
           const std::size_t grid_width, const std::size_t grid_height);
  ~Renderer();

  void Render(Player const player, SDL_Point const &food, Terrain const terrain);
  void UpdateWindowTitle(int score, int fps);
  void LoadPlayerImage();
  void LoadTerrainImage();
  void LoadFoodImage();

 private:
  SDL_Window *sdl_window;
  SDL_Renderer *sdl_renderer;
  SDL_Texture *player_image = NULL;
  SDL_Texture *terrain_image = NULL;
  SDL_Texture *food_image = NULL;

  const std::size_t screen_width;
  const std::size_t screen_height;
  const std::size_t grid_width;
  const std::size_t grid_height;
};

#endif