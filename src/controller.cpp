#include "controller.h"
#include <iostream>
#include "SDL.h"
#include "player.h"

void Controller::ChangeDirection(Player &player, Player::Direction input,
                                 Player::Direction opposite) const {
  switch (input) {
    case Player::Direction::kUp:
      player.velocity_y -= 0.2;
      break;

    case Player::Direction::kDown:
      player.velocity_y += 0.1;
      break;

    case Player::Direction::kLeft:
      player.velocity_x -= 0.1;
      break;

    case Player::Direction::kRight:
      player.velocity_x += 0.1;
      break;
  }
  return;
}

void Controller::HandleInput(bool &running, Player &player) const {
  SDL_Event e;
  while (SDL_PollEvent(&e)) {
    if (e.type == SDL_QUIT) {
      running = false;
    } else {
    //} else if (e.type == SDL_KEYDOWN) {

      SDL_PumpEvents();
      const Uint8* keystates = SDL_GetKeyboardState( NULL );

      if (keystates[SDL_GetScancodeFromKey(SDLK_UP)]) {
          ChangeDirection(player, Player::Direction::kUp,
                          Player::Direction::kDown);
      }
      if (keystates[SDL_GetScancodeFromKey(SDLK_DOWN)]) {
          ChangeDirection(player, Player::Direction::kDown,
                          Player::Direction::kUp);
      }
      if (keystates[SDL_GetScancodeFromKey(SDLK_LEFT)]) {
        ChangeDirection(player, Player::Direction::kLeft,
                          Player::Direction::kRight);
      }
      if (keystates[SDL_GetScancodeFromKey(SDLK_RIGHT)]) {
        ChangeDirection(player, Player::Direction::kRight,
                          Player::Direction::kLeft);
      }
    }
  }
}