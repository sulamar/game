#pragma once
#include "graphics/Window.h"
#include "core/Player.h"
#include "core/Map.h"
#include "utils/math/Math.h"
#include <memory>
#include "core/Camera.h"
#include "core/World.h"
#include <list>
#include "utils/tools/Framerate.h"
#include "core/Tile.h"
#include <SDL2/SDL_mixer.h>
#include <unordered_map>

namespace engine
{
    namespace Game
    {    
        //Inits SDL
        bool Init();

        //Runs game (contains mainloop)
        void Run();
    };
}
