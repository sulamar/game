#pragma once
#include "GameObject.h"
#include <memory>

class Camera : public GameObject
{
public:
    Camera(Vector2<int> size, Vector2<float> _pos);
    Camera(){}

    //Sets target to follow
    void SetTarget(std::shared_ptr<GameObject> _target);

    //Follows target
    void FollowTarget();

private:
    std::shared_ptr<GameObject> target;
};