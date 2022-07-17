#pragma once
#include "Utils/Math/Math.h"
#include "GameObject.h"

class Player : public GameObject
{

public:
    Player(SDL_Texture* _tex, Vector2<float> _pos, Vector2<int> _scale);
    Player(){}

    //Handles all players input (movement etc...)
    void HandleInput(SDL_Event& e);

private:
    //Players movement speed
    float speed;
};