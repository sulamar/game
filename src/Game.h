#pragma once
#include "Window.h"
#include "Player.h"
#include "Map.h"
#include "Utils/Math/Math.h"
#include <memory>
#include "Camera.h"
#include "World.h"
#include <list>

class Game
{
public:
    Game()
    {}
    ~Game()
    {}
    
    //Inits SDL
    void Init();

    //Runs game (contains mainloop)
    void Run();
};
