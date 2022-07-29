#pragma once
#include <SDL2/SDL.h>
#include "../utils/math/Math.h"

namespace engine
{
    class Collider
    {
    public:
        Collider();
           
        SDL_Rect rectCollider; 

        bool AABB(const Collider& other);
        Vector2<int> GetPlaceOfCollision(const Collider& other);
    };
}
