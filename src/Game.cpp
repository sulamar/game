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
	SDL_Rect camera = {0,0,1080,720};

	std::unique_ptr<Window> window = std::make_unique<Window>("game", 1080, 720);

	std::unique_ptr<Map<20,20>> map = std::make_unique<Map<20,20>>(window->renderer);

	std::unique_ptr<Player> player = std::make_unique<Player>(TextureManager::LoadTexture("../files/images/player.png", window->renderer), Vector2<float>(0.0f, 0.0f), Vector2<int>(32, 32));

	map->LoadMap(level);

	SDL_Event e;

	while(window->running)
	{
		camera.x = player->transform.position.x;
		camera.y = player->transform.position.y;

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

		map->RenderMap(camera);
		player->Render(window->renderer);

		window->Display();

		SDL_Delay(10);

	}	
}




