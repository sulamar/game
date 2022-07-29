#pragma once
#include "../utils/math/Math.h"
#include "GameObject.h"
#include "Projectile.h"
#include "Animation.h"
#include <unordered_map>
#include <vector>

namespace engine
{
    class Player : public PhysicsObject
    {


    public:
        Player(SDL_Texture* _tex, const Vector2<float>& _pos, const Vector2<int>& _scale);
        Player();

        //Handles all players input (movement etc...)
        void HandleInput(const Uint8* state, const float& dt);

        void Update(const float& dt) override;

        void UpdateProjectiles();

        void Render(SDL_Renderer* renderer, SDL_Rect& screenDst) override;

        Vector2<float> positionOffset;

        bool isJumping;
        bool isGrounded;

        float fallSpeed;

        enum PlayerStates
        {
            IDLE,
            GROUNDED,
            JUMPING
        };

       PlayerStates playersState;

    private:
        void ShootProjectile();
        //Players  direction
        Vector2<int> direction;

        //Animations
        std::unordered_map<const char*, Animation> animations;
        
        //Projectiles
        std::vector<Projectile*> projectiles;
        //Players healthpoints
        int health;

        //Jumps player
        void Jump();

        float speedOffset;

        bool isIdle;

        int keyState;


        float jumpHeight;

        float speed;


        SDL_RendererFlip flip;

    };
}
