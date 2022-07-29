#include "Animation.h"
#include <SDL2/SDL_timer.h>

namespace engine
{
    Animation::Animation(int _speed, int _frames, int _index)
        : speed(_speed), frames(_frames), index(_index)
    {

    }

    Animation::Animation()
    {

    }
    
    void Animation::Play(Sprite& sprite)
    {
        sprite.src.x = (index * sprite.src.w) + (sprite.src.w * (SDL_GetTicks() / speed % frames));
        //sprite.src.x = sprite.src.w * (SDL_GetTicks() / speed % frames);
    }
}