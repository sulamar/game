#include "Player.h"
#include "../utils/tools/Framerate.h"
#include "../graphics/Window.h"
#include "Transform.h"
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_scancode.h>
#include <cstddef>
#include <sys/types.h>

namespace engine
{
	Player::Player()
	{}
	
	Player::Player(SDL_Texture* _tex, const Vector2<float>& _pos, const Vector2<int>& _scale)
		: health(100)
	{
		sprite.texture = _tex;

		transform.position = _pos;
		transform.scale = _scale;

		collider.rectCollider.x = transform.position.x + 40; //40 is offset
        collider.rectCollider.y = transform.position.y;
        collider.rectCollider.w = transform.scale.x / 6; //32 * 3 / 6 = 16
        collider.rectCollider.h = transform.scale.y;
        
		sprite.src.x = 0;
		sprite.src.y = 0;
		sprite.src.w = 32;
		sprite.src.h = 32;

		sprite.dst.x = transform.position.x;
		sprite.dst.y = transform.position.y;
		sprite.dst.w = transform.scale.x;
		sprite.dst.h = transform.scale.y;

		rigidBody.mass = 50.0f;
		rigidBody.gravity = 4.0f;
		rigidBody.velocity = Vector2<float>(0.0f, 0.0f);

		isGrounded = false;
		isJumping = false;

		speedOffset = 0.0f;

		positionOffset = Vector2<float>(0.0f,11.0f);

		speed = 64.0f * 5.0f;

		jumpHeight = -256.0f * 2;

		fallSpeed = rigidBody.gravity;

		animations["idle"] = Animation(250, 2, 0);
		animations["walk"] = Animation(200, 2, 2);
		animations["jump"] = Animation(100, 1, 5);
		animations["jumpInDirection"] = Animation(100, 1, 6);

	}

	void Player::ShootProjectile()
	{
		//projectiles.emplace(TextureManager::LoadTexture("../files/images/projectile.png", renderer), 50, Vector2<float>(0, 0), Vector2<float>(0, 20));
	}

	void Player::UpdateProjectiles()
	{

	}

	void Player::Update(const float& dt) 
	{
		sprite.dst.w = transform.scale.x;
        sprite.dst.h = transform.scale.y;

		collider.rectCollider.x = transform.position.x + 40; //40 is offset
        collider.rectCollider.y = transform.position.y;
		collider.rectCollider.w = transform.scale.x / 6; //32 * 3 / 6 = 16
        collider.rectCollider.h = transform.scale.y; //+ positionOffset.y;

		transform.position.y += fallSpeed * dt;

		UpdateProjectiles();

		if(isGrounded == false)
		{
			animations["jump"].Play(sprite);
		}
		

	}

	void Player::Render(SDL_Renderer* renderer, SDL_Rect& screenDst)
	{
		SDL_RenderCopyEx(renderer, sprite.texture, &sprite.src, &screenDst, 0, nullptr, flip);
	}

	void Player::HandleInput(const Uint8* state, const float& dt)
	{
		if(state[SDL_SCANCODE_D])
		{
			isIdle = false;

			if(!isJumping)
				animations["walk"].Play(sprite);

			keyState = -1;
			flip = SDL_FLIP_HORIZONTAL;

			direction.x = 1;
			rigidBody.velocity.x = speed * direction.x;
			transform.position.x += rigidBody.velocity.x * dt;
		}

		if(state[SDL_SCANCODE_A])
		{
			isIdle = false;

			if(!isJumping)
				animations["walk"].Play(sprite);

			keyState = -1;
			flip = SDL_FLIP_NONE;

			direction.x = -1;
			rigidBody.velocity.x = speed * direction.x;
			transform.position.x += rigidBody.velocity.x * dt;
		}

		if(state[SDL_SCANCODE_SPACE])
		{
			if(isGrounded)
				Jump();
		}

		else if(!(state[SDL_SCANCODE_D]) && !(state[SDL_SCANCODE_A]))
		{
			isIdle = true;
			flip = SDL_FLIP_NONE;
		}

		if(isIdle)
			if(!isJumping)
				animations["idle"].Play(sprite);	
		
	}

	void Player::Jump()
	{
		isIdle = false;

		//animations["jump"].Play(sprite);

		isGrounded = false;
		isJumping = true;
		
		fallSpeed = jumpHeight;
	}
}