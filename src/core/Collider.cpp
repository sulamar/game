#include "Collider.h"

namespace engine
{
    Collider::Collider()
    {}

    bool Collider::AABB(const Collider& other)
    {
        if(
            rectCollider.x + rectCollider.w > other.rectCollider.x &&
            other.rectCollider.x + other.rectCollider.w > rectCollider.x &&
            rectCollider.y + rectCollider.h >= other.rectCollider.y &&
            other.rectCollider.y + other.rectCollider.h >= rectCollider.y
            )
        {
            return true;
        }

        return false;
    }

    Vector2<int> Collider::GetPlaceOfCollision(const Collider& other)
    {
        if(rectCollider.x + rectCollider.w > other.rectCollider.x)
            return Vector2<int>(1, 0);
        
        else if(rectCollider.x < other.rectCollider.x + other.rectCollider.w)
            return Vector2<int>(-1, 0);
        
        else if(rectCollider.y + rectCollider.h > other.rectCollider.y)
            return Vector2<int>(0, 1);
        
        else if(rectCollider.y < other.rectCollider.y + other.rectCollider.h)
            return Vector2<int>(0, -1);
        
        return Vector2<int>();

    }
}