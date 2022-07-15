#pragma once
#include <SDL2/SDL.h>

struct Sprite
{
    SDL_Texture* texture;
    SDL_Rect src;
    SDL_Rect dst;
};