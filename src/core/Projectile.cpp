#include "Projectile.h"

namespace engine
{
    Projectile::Projectile()
    {}

    Projectile::Projectile(SDL_Texture* tex, float _mass, Vector2<float> _velocity, Vector2<float> _acceleration)
    {
        rigidBody.mass = _mass;
        rigidBody.velocity = _velocity;
        rigidBody.acceleration = _acceleration;

        sprite.texture = tex;
    }
}