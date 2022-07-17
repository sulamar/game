#pragma once
#include <SDL2/SDL.h>
#include "Sprite.h"
#include "Transform.h"

class GameObject
{
public:
    GameObject(SDL_Texture* _tex, Vector2<float> _pos, Vector2<int> _scale);
    GameObject(){}

    Transform transform;
    Sprite sprite;
    
};