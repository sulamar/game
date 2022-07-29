#pragma once
#include <SDL2/SDL.h>
#include "Sprite.h"
#include "Transform.h"
#include "../graphics/Window.h"
#include "Collider.h"
#include "Rigidbody.h"

namespace engine
{
    class GameObject
    {
    public:
        GameObject(SDL_Texture* _tex, const Vector2<float>& _pos, const Vector2<int>& _scale, std::string _tag); 
        GameObject();

        virtual void Update(const float& dt);
        
        virtual void Render(SDL_Renderer* renderer, SDL_Rect& screenDst);

        const std::string& GetTag() const;

        Sprite sprite;
        Transform transform;
        Collider collider;
    
    private:
        std::string tag;
    };

    class PhysicsObject : public GameObject
    {
    public:
        Rigidbody rigidBody;
    };
}
