#include "Tile.h"

namespace engine
{
    Tile::Tile()
    {}

    Tile::Tile(SDL_Texture* _tex, const Vector2<float>& _pos, const Vector2<int>& _scale)
    {   
        sprite.texture = _tex;
        
        transform.scale = _scale;

        transform.position = _pos;

        collider.rectCollider.x = transform.position.x;
        collider.rectCollider.y = transform.position.y;
        collider.rectCollider.w = transform.scale.x;
        collider.rectCollider.h = transform.scale.y;
        
        sprite.src.x = 0;
        sprite.src.y = 0;
        sprite.src.w = 32;
        sprite.src.h = 32;
        sprite.dst.w = transform.scale.x;
        sprite.dst.h = transform.scale.y;
    }

    void Tile::Update(const float& dt)
    {
        /*sprite.dst.w = transform.scale.x;
        sprite.dst.h = transform.scale.y;*/
        
        collider.rectCollider.x = transform.position.x;
        collider.rectCollider.y = transform.position.y;
        collider.rectCollider.w = transform.scale.x;
        collider.rectCollider.h = transform.scale.y;
    }


    TileImage::TileImage(SDL_Texture* texture, const Vector2<int>& _scale)
    {
        sprite.texture = texture;
        transform.scale = _scale;
    }

    TileImage::TileImage()
    {}
}