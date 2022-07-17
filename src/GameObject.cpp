#include "GameObject.h"


GameObject::GameObject(SDL_Texture* _tex, Vector2<float> _pos, Vector2<int> _scale)
{
    sprite.texture = _tex;

    transform.position = _pos;
    transform.scale = _scale;

    sprite.src.x = transform.position.x;
    sprite.src.y = transform.position.y;
    sprite.src.w = transform.scale.x;
    sprite.src.h = transform.scale.y;

	sprite.dst.w = transform.scale.x;
	sprite.dst.h = transform.scale.y;
}

