#include "game.h"
#include <iostream>
#include "SDL.h"

Game::Game(std::size_t grid_width, std::size_t grid_height, std::size_t screen_width, std::size_t screen_height)
    : player(grid_width, grid_height),
      terrain(grid_width, grid_height, screen_width, screen_height),
      engine(dev()),
      random_w(0, static_cast<int>(grid_width - 1)),
      random_h(0, static_cast<int>(grid_height - 1)) {
  PlaceFood();
}

void Game::Run(Controller const &controller, Renderer &renderer,
               std::size_t target_frame_duration) {
  Uint32 title_timestamp = SDL_GetTicks();
  Uint32 frame_start;
  Uint32 frame_end;
  Uint32 frame_duration;
  int frame_count = 0;
  bool running = true;
  srand (time(NULL));
  terrain.Generate();

  while (running) {
    frame_start = SDL_GetTicks();

    // Input, Update, Render - the main game loop.
    controller.HandleInput(running, player);
    Update();
    renderer.Render(player, food, terrain);

    frame_end = SDL_GetTicks();

    // Keep track of how long each loop through the input/update/render cycle
    // takes.
    frame_count++;
    frame_duration = frame_end - frame_start;

    // After every second, update the window title.
    if (frame_end - title_timestamp >= 1000) {
      renderer.UpdateWindowTitle(score, frame_count);
      frame_count = 0;
      title_timestamp = frame_end;
    }

    // If the time for this frame is too small (i.e. frame_duration is
    // smaller than the target ms_per_frame), delay the loop to
    // achieve the correct frame rate.
    if (frame_duration < target_frame_duration) {
      SDL_Delay(target_frame_duration - frame_duration);
    }
    if (!player.alive) {
      running = false;
    };
  }
}

void Game::PlaceFood() {
  float width = 0.95;
  float height = 0.95;
  float x0, x1, y0, y1;
  
  while (true) {
    x0 = (float)random_w(engine);
    y0 = (float)random_h(engine);
    x1 = x0 + width;
    y1 = y0 + height;
    
    if (!player.PlayerCell(x0, y0)) {
      terrain.PushToTop(x0, y0, width, height);
      if (!player.PlayerCell(x0, y0)) {
        food.x = x0;
        food.y = y0;
        return;
      }
    }
  }
}

void Game::Update() {
  if (!player.alive) return;

  player.Update();

  int new_x = static_cast<int>(player.position_x);
  int new_y = static_cast<int>(player.position_y);

  // Check if there's food over here
  if (food.x == new_x && food.y == new_y) {
    score++;
    PlaceFood();
  } else if (food.x <= 0.0) {
    PlaceFood();
  }
  terrain.CollidesWith(player);
  terrain.Advance(player, food);
}

int Game::GetScore() const { return score; }