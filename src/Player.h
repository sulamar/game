#pragma once
#include "Math.h"
#include "GameObject.h"

class Player : public GameObject
{

public:
    Player(SDL_Texture* _tex, Vector2<float> _pos, Vector2<int> _scale);
    Player(){}
    void HandleInput(SDL_Event& e);

private:
    float speed;
};