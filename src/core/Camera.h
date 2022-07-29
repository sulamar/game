#pragma once
#include "GameObject.h"
#include <memory>

namespace engine
{
    class Camera : public GameObject
    {
    public:
        Camera();
        Camera(const Vector2<int>& size, const Vector2<float>& _pos);
       

        //Sets target to follow
        void SetTarget(GameObject& _target);

        //Follows target
        void FollowTarget(const float& dt);

        //std::unique_ptr<GameObject>& GetTarget();

    private:
        GameObject* target;
    };
}