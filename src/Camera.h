#pragma once
#include "GameObject.h"

class Camera : public GameObject
{
public:
    Camera(Vector2<float> _pos);
    Camera(){}
};