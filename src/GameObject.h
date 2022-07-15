#pragma once
#include <SDL2/SDL.h>
#include "Sprite.h"
#include "Transform.h"

class GameObject
{
public:
    Transform transform;

    Sprite GetSprite() const;
    SDL_Texture* tex;
protected:
    Sprite sprite;
};