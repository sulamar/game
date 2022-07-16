#pragma once
#include "Window.h"
#include "Player.h"
#include "Map.h"
#include "Math.h"
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
    
    void Init();
    void Run();
};
