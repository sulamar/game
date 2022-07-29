#include "Camera.h"
#include "GameObject.h"

namespace engine
{
    Camera::Camera()
    {}
    
    Camera::Camera(const Vector2<int>& size, const Vector2<float>& _pos)
    {
        transform.position = _pos;
        transform.scale = size;
    }

    void Camera::SetTarget(GameObject& _target)
    {
        target = &_target;
        transform.position = target->transform.position;
    }

    void Camera::FollowTarget(const float& dt)
    {
        Vector2<float> pos = target->transform.position;

        if(transform.position.x < 0)
                transform.position.x = 0;
        if(transform.position.y < 0)
                transform.position.y = 0;

        transform.position = pos - Vector2<float>((float)transform.scale.x / 2, (float)transform.scale.y / 2);
    }

    /*std::unique_ptr<GameObject>& Camera::GetTarget()
    {
        return target;
    }*/
}