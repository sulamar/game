#include "Game.h"
#include "utils/math/Math.h"
#include <SDL2/SDL_keyboard.h>
#include <memory>
#include "core/GameStates.h"

namespace engine
{
	bool Game::Init()
	{
		if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
		{
			std::cout << "SDL could not be initialized!" << SDL_GetError() << std::endl;
			return 0;
		}

		if(!(IMG_Init(IMG_INIT_PNG)))
		{
			std::cout << "SDL_image could not be initialized!" << SDL_GetError() << std::endl;
			return 0;
		}

		return 1;

	}

	void Game::Run()
	{
		const unsigned int SCREEN_WIDTH = 1920;
		const unsigned int SCREEN_HEIGHT = 1080;
		
		const Vector2<int> tileScale(32 * 2, 32 * 2);
		const Vector2<int> playerScale(32 * 3, 32 * 3);

		//TODO To get level height and width from world render map function and give it to camera so camera does not go out of bounds...
		//TODO FIX PLAYER STUFF NO POINTERS?? REFERENCES?...
	
	    Window window("game", SCREEN_WIDTH, SCREEN_HEIGHT);
		float refreshRate = (float)tools::GetRefreshRate(window.GetWindow());

		Map map;

		Camera camera (Vector2<int>(SCREEN_WIDTH, SCREEN_HEIGHT), Vector2<float>(0, 0));

		Player player(TextureManager::LoadTexture("../files/images/player.png", window.GetRenderer()), 
		Vector2<float>(0.0f, 0.0f), playerScale);


		std::shared_ptr<PhysicsWorld> physicsWorld = std::make_shared<PhysicsWorld>(player, camera);
		std::unique_ptr<World> world = std::make_unique<World>(map, camera, physicsWorld);


		std::unordered_map<char, TileImage> images;
		images[1] = TileImage(TextureManager::LoadTexture("../files/images/grass.png", window.GetRenderer()), 
		tileScale);
		images[2] = TileImage(TextureManager::LoadTexture("../files/images/ground.png", window.GetRenderer()), 
		tileScale);
	

		std::shared_ptr<GameObject> box = std::make_shared<GameObject>(TextureManager::LoadTexture("../files/images/box.png", window.GetRenderer()),
		Vector2<float>(0.0f, 0.0f), Vector2<int>(32 * 2, 32 * 2), "box");

		//Loads map from file
		world->LoadMap("../files/levels/earth.txt");

		//Adds tile images to world (takes a unordered map as parameter)
		world->AddTileImages(images);

		//Loads tiles and positions into variable to be used for rendering
		world->LoadTiles();


		physicsWorld->AddObject(box);

		camera.SetTarget(player);
	
		SDL_Event e;

		//std::cout << refreshRate << std::endl;
		const float timeStep = 1.0f / refreshRate;
		std::cout << "timestep" << timeStep << std::endl;

		float accumulator = 0.0f;

		float currentTime = tools::TimeInSeconds();
		std::cout << "currenttime" << currentTime << std::endl;

		GameStates::state = GameStates::States::GAME_ACTIVE;

		//Mainloop
		while(GameStates::state == GameStates::States::GAME_ACTIVE)
		{
			Uint32 startTicks = SDL_GetTicks();

			float newTime = tools::TimeInSeconds();

			float frameTime = newTime - currentTime;	

			currentTime = newTime;

			accumulator += frameTime;

			while(accumulator >= timeStep)
			{
				//std::cout << "acc" << accumulator<< std::endl;
				//Events
				while(SDL_PollEvent(&e))
				{
					switch(e.type)
					{
						case SDL_QUIT:
							window.running = false;
					}

					
				}

				const Uint8* state = SDL_GetKeyboardState(NULL);

				player.HandleInput(state, timeStep);
				//Physics
				physicsWorld->Step(timeStep);

				camera.FollowTarget(timeStep);		

				accumulator -= timeStep;
			}
			
			const float alpha = accumulator / timeStep; //50%?
			
			//Rendering
			world->Render(window.GetRenderer());

			Uint32 frameTicks = SDL_GetTicks() - startTicks;

			//std::cout << frameTicks << std::endl;
			//std::cout << 1000 / refreshRate - frameTicks << std::endl;

			if(frameTicks < 1000 / refreshRate)
				SDL_Delay(1000 / refreshRate - frameTicks);

		}	
	}

}


