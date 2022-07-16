#include "Game.h"

int level[20][20] =
{
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},	
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},	
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},	
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
};


void Game::Init()
{
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
	 	std::cout << "SDL could not be initialized!" << SDL_GetError() << std::endl;
	}

	if(!(IMG_Init(IMG_INIT_PNG)))
	{
		std::cout << "SDL_image could not be initialized!" << SDL_GetError() << std::endl;
	}

	
}

void Game::Run()
{
	std::shared_ptr<Camera> camera = std::make_shared<Camera>();

	std::unique_ptr<Window> window = std::make_unique<Window>("game", 1080, 720);

	std::shared_ptr<Map> map = std::make_shared<Map>(); 
	
	std::shared_ptr<Player> player = std::make_shared<Player>(TextureManager::LoadTexture("../files/images/player.png", window->renderer), 
	Vector2<float>(0.0f, 0.0f), Vector2<int>(32, 32));
	
	std::unique_ptr<World> world = std::make_unique<World>(map, player, camera);
	
	std::shared_ptr<GameObject> ground = std::make_shared<GameObject>(TextureManager::LoadTexture("../files/images/ground.png", window->renderer),
	Vector2<float>(0.0f, 0.0f), Vector2<int>(32, 32));

	world->AddObject(ground);

	SDL_Event e;

	while(window->running)
	{
		camera->transform.position.x = player->transform.position.x;
		camera->transform.position.y = player->transform.position.y;

		while(SDL_PollEvent(&e))
		{
			switch(e.type)
			{
				case SDL_QUIT:
                    window->running = false;
			}

			player->HandleInput(e);
		}

		window->Clear();

		world->Render(window->renderer);

		window->Display();

		SDL_Delay(10);

	}	
}




