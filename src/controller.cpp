#include "controller.h"
#include <iostream>
#include "SDL.h"
#include "snake.h"

void Controller::ChangeDirection(Snake &snake, Snake::Direction input,
                                 Snake::Direction opposite) const {
  switch (input) {
    case Snake::Direction::kUp:
      snake.velocity_y -= 0.2;
      break;

    case Snake::Direction::kDown:
      snake.velocity_y += 0.1;
      break;

    case Snake::Direction::kLeft:
      snake.velocity_x -= 0.1;
      break;

    case Snake::Direction::kRight:
      snake.velocity_x += 0.1;
      break;
  }
  return;
}

void Controller::HandleInput(bool &running, Snake &snake) const {
  SDL_Event e;
  while (SDL_PollEvent(&e)) {
    if (e.type == SDL_QUIT) {
      running = false;
    } else {
    //} else if (e.type == SDL_KEYDOWN) {

      SDL_PumpEvents();
      const Uint8* keystates = SDL_GetKeyboardState( NULL );

      if (keystates[SDL_GetScancodeFromKey(SDLK_UP)]) {
          ChangeDirection(snake, Snake::Direction::kUp,
                          Snake::Direction::kDown);
      }
      if (keystates[SDL_GetScancodeFromKey(SDLK_DOWN)]) {
          ChangeDirection(snake, Snake::Direction::kDown,
                          Snake::Direction::kUp);
      }
      if (keystates[SDL_GetScancodeFromKey(SDLK_LEFT)]) {
        ChangeDirection(snake, Snake::Direction::kLeft,
                          Snake::Direction::kRight);
      }
      if (keystates[SDL_GetScancodeFromKey(SDLK_RIGHT)]) {
        ChangeDirection(snake, Snake::Direction::kRight,
                          Snake::Direction::kLeft);
      }
    }
  }
}