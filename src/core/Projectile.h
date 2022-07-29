#include "GameObject.h"

namespace engine
{
    class Projectile : public PhysicsObject
    {
    public:
        Projectile(SDL_Texture* tex, float _mass, Vector2<float> _velocity, Vector2<float> _acceleration);
        Projectile();
    };
}
