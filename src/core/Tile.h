#pragma once

#include <SDL2/SDL.h>
#include <memory>
#include <iostream>
#include <string>
#include "Sprite.h"
#include "Transform.h"
#include "GameObject.h"

namespace engine
{
    class Tile : public GameObject
    {
    public:
        Tile(SDL_Texture* texture, const Vector2<float>& _pos, const Vector2<int>& _scale);
        Tile();

        void Update(const float& dt) override;
    };

    struct TileImage
    {
        TileImage(SDL_Texture* texture, const Vector2<int>& _scale);
        TileImage();
        Sprite sprite;
        Transform transform;
    };
}
