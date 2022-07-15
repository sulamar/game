#pragma once
#include "Window.h"
#include "Player.h"
#include "Map.h"
#include "Math.h"
#include <memory>

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
