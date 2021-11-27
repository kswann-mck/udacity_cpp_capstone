#include "renderer.h"
#include <iostream>
#include <experimental/filesystem>
#include <string>

Renderer::Renderer(const std::size_t screen_width,
                   const std::size_t screen_height,
                   const std::size_t grid_width, const std::size_t grid_height)
    : screen_width(screen_width),
      screen_height(screen_height),
      grid_width(grid_width),
      grid_height(grid_height) {
  // Initialize SDL
  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    std::cerr << "SDL could not initialize.\n";
    std::cerr << "SDL_Error: " << SDL_GetError() << "\n";
  }

  // Create Window
  sdl_window = SDL_CreateWindow("Unicorn Run", SDL_WINDOWPOS_CENTERED,
                                SDL_WINDOWPOS_CENTERED, screen_width,
                                screen_height, SDL_WINDOW_SHOWN);

  if (nullptr == sdl_window) {
    std::cerr << "Window could not be created.\n";
    std::cerr << " SDL_Error: " << SDL_GetError() << "\n";
  }


  // Create renderer
  sdl_renderer = SDL_CreateRenderer(sdl_window, -1, SDL_RENDERER_ACCELERATED);
  if (nullptr == sdl_renderer) {
    std::cerr << "Renderer could not be created.\n";
    std::cerr << "SDL_Error: " << SDL_GetError() << "\n";
  }

  //Initialize PNG loading
  int imgFlags = IMG_INIT_PNG;
  if( !( IMG_Init( imgFlags ) & imgFlags ) )
  {
      printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
  }

  printf("About to load images.");
  LoadPlayerImage();
  LoadTerrainImage();
  LoadFoodImage();
}

Renderer::~Renderer() {
  SDL_DestroyWindow(sdl_window);
  SDL_Quit();
}

/*
Renders the background, terrain, player and food to the screen
*/
void Renderer::Render(Player const player, SDL_Point const &food, Terrain const terrain) {
  SDL_Rect block;
  block.w = screen_height / grid_height;
  block.h = screen_height / grid_height;

  // Clear screen
  SDL_SetRenderDrawColor(sdl_renderer, 135, 206, 235, 0xFF);
  SDL_RenderClear(sdl_renderer);

  // Render food
  SDL_SetRenderDrawColor(sdl_renderer, 0xFF, 0xCC, 0x00, 0xFF); // sky blue color
  block.x = food.x * block.w;
  block.y = food.y * block.h;
  SDL_RenderFillRect(sdl_renderer, &block);
  // Render Food Image
  SDL_RenderCopy(sdl_renderer, food_image, NULL, &block);

  // Render terrain
  SDL_SetRenderDrawColor(sdl_renderer, 0xFF, 0xCF, 0x00, 0xFF);
  for (std::vector<SDL_Point> column: terrain.terrain_blocks) {
    for (SDL_Point const point : column) {
      block.x = point.x * block.w;
      block.y = point.y * block.h;
      SDL_RenderFillRect(sdl_renderer, &block);
      SDL_RenderCopy(sdl_renderer, terrain_image, NULL, &block);
    }
  }

  // Render player's position
  block.x = player.position_x * (float)block.w;
  block.y = player.position_y * (float)block.h;
  block.w = block.w * player.width;
  block.h = block.h * player.height;

  if (player.alive) {
    SDL_SetRenderDrawColor(sdl_renderer, 0x00, 0x7A, 0xCC, 0xFF);
  } else {
    SDL_SetRenderDrawColor(sdl_renderer, 0xFF, 0x00, 0x00, 0xFF);
  }
  SDL_RenderFillRect(sdl_renderer, &block);

  // Render Player Image
  SDL_RenderCopy(sdl_renderer, player_image, NULL, &block);

  // Update Screen
  SDL_RenderPresent(sdl_renderer);
}

void Renderer::UpdateWindowTitle(int score, int fps) {
  std::string title{"Player Score: " + std::to_string(score) + " FPS: " + std::to_string(fps)};
  SDL_SetWindowTitle(sdl_window, title.c_str());
}

void Renderer::LoadPlayerImage() {

  std::experimental::filesystem::path p = std::experimental::filesystem::current_path();
  std::string path = p.string() + "/../src/img/player.png";

  //Load image at specified path
  SDL_Surface *loadedSurface = IMG_Load( path.c_str() );

  if( loadedSurface == NULL )
  {
      printf( "Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError() );
  }
  else
  {
      //Convert surface to screen format
      player_image = SDL_CreateTextureFromSurface(sdl_renderer, loadedSurface);
      if( player_image == NULL )
      {
          printf( "Unable to optimize image %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
      }

      //Get rid of old loaded surface
      SDL_FreeSurface( loadedSurface );
  }
}

void Renderer::LoadTerrainImage() {

  std::experimental::filesystem::path p = std::experimental::filesystem::current_path();
  std::string path = p.string() + "/../src/img/grass.png";

  //Load image at specified path
  SDL_Surface *loadedSurface = IMG_Load( path.c_str() );

  if( loadedSurface == NULL )
  {
      printf( "Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError() );
  }
  else
  {
      //Convert surface to screen format
      terrain_image = SDL_CreateTextureFromSurface(sdl_renderer, loadedSurface);
      if( terrain_image == NULL )
      {
          printf( "Unable to optimize image %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
      }

      //Get rid of old loaded surface
      SDL_FreeSurface( loadedSurface );
  }
}


void Renderer::LoadFoodImage() {

  std::experimental::filesystem::path p = std::experimental::filesystem::current_path();
  std::string path = p.string() + "/../src/img/food.png";

  //Load image at specified path
  SDL_Surface *loadedSurface = IMG_Load( path.c_str() );

  if( loadedSurface == NULL )
  {
      printf( "Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError() );
  }
  else
  {
      //Convert surface to screen format
      food_image = SDL_CreateTextureFromSurface(sdl_renderer, loadedSurface);
      if( food_image == NULL )
      {
          printf( "Unable to optimize image %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
      }

      //Get rid of old loaded surface
      SDL_FreeSurface( loadedSurface );
  }
}
