#include "../utils/math/Math.h"

namespace engine
{
    struct Rigidbody
    {
    public:
        Vector2<float> force;
        Vector2<float> velocity;
        Vector2<float> acceleration;
        float gravity;
        
        float mass;
    };
}
