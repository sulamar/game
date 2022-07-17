#include "Camera.h"

Camera::Camera(Vector2<int> size, Vector2<float> _pos)
{
    transform.position = _pos;
    transform.scale = size;
}

void Camera::SetTarget(std::shared_ptr<GameObject> _target)
{
    target = _target;
    transform.position = target->transform.position;
}

void Camera::FollowTarget()
{
    Vector2<float> pos = target->transform.position;

    if(transform.position.x < 0)
			transform.position.x = 0;
	if(transform.position.y < 0)
			transform.position.y = 0;

    transform.position = pos - (Vector2<float>(transform.scale.x / 2, transform.scale.y / 2));
}

