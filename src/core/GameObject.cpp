#include "GameObject.h"
#include "Transform.h"
#include <SDL2/SDL_scancode.h>

namespace engine
{
    GameObject::GameObject()
    {}

    GameObject::GameObject(SDL_Texture* _tex, const Vector2<float>& _pos, const Vector2<int>& _scale, std::string _tag = "")
        :   sprite({_tex}), transform({_pos, _scale})
    {
        collider.rectCollider.x = transform.position.x;
        collider.rectCollider.y = transform.position.y;
        collider.rectCollider.w = transform.scale.x;
        collider.rectCollider.h = transform.scale.y;

        sprite.src.x = 0;
        sprite.src.y = 0;
        sprite.src.w = 32;
        sprite.src.h = 32;

        sprite.dst.x = 0;
        sprite.dst.y = 0;
        sprite.dst.w = transform.scale.x;
        sprite.dst.h = transform.scale.y;

    }

    void GameObject::Update(const float& dt)
    {
        sprite.dst.w = transform.scale.x;
        sprite.dst.h = transform.scale.y;
        
        collider.rectCollider.x = transform.position.x;
        collider.rectCollider.y = transform.position.y;
        collider.rectCollider.w = transform.scale.x;
        collider.rectCollider.h = transform.scale.y;
    }

    void GameObject::Render(SDL_Renderer* renderer, SDL_Rect& screenDst)
    {
        SDL_RenderCopy(renderer, sprite.texture, &sprite.src, &screenDst);
    }

    const std::string& GameObject::GetTag() const
    {
        return tag;
    }
}