#include <SDL2/SDL_image.h>
#include <iostream>
#include "GameObject.h"
#include <memory>
#include <string>
#include "Sprite.h"

namespace engine
{
    class Animation
    {
    public:
        Animation(int _speed, int _frames, int _index);
        Animation();
        void Play(Sprite& sprite);

    private:
        int frames;
        int speed;
        int index;
    };
}
