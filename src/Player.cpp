#include "Player.h"

Player::Player(SDL_Texture* _tex, Vector2<float> _pos, Vector2<int> _scale)
{
    sprite.texture = _tex;

    transform.position = _pos;
    transform.scale = _scale;

    sprite.src.x = transform.position.x;
    sprite.src.y = transform.position.y;
    sprite.src.w = transform.scale.x;
    sprite.src.h = transform.scale.y;

	sprite.dst.w = transform.scale.x;
	sprite.dst.h = transform.scale.y;

    speed = 5.0f;
}

void Player::HandleInput(SDL_Event& e)
{
    if(e.type == SDL_KEYDOWN)
	{
		switch(e.key.keysym.sym)
		{
			case SDLK_a:
                transform.velocity.x = -1;
				transform.position.x += transform.velocity.x * speed;
				break;
			case SDLK_d:
                transform.velocity.x = 1;
				transform.position.x += transform.velocity.x * speed; 
				break;
			case SDLK_w:
                transform.velocity.y = -1;    
				transform.position.y += transform.velocity.y * speed;
				break;
			case SDLK_s:
                transform.velocity.y = 1;
				transform.position.y += transform.velocity.y * speed;
				break;
			default:
				break;
		}
	}
	
}