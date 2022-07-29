#pragma once
#include "../../graphics/Window.h"
#include <SDL2/SDL.h>
#include <memory>

namespace tools
{
    //Gets time in seconds from start InitSDL
    inline float TimeInSeconds()
    {
        return ((float)SDL_GetTicks() * 0.001f);
    }

    //Gets current monitors refreshrate
    inline int GetRefreshRate(SDL_Window* window)
    {
        int displayIndex = SDL_GetWindowDisplayIndex(window);

		SDL_DisplayMode mode;

		SDL_GetDisplayMode(displayIndex, 0, &mode);

		return mode.refresh_rate;
    }


}