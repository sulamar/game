#include "Window.h"

Window::Window(const char* name, unsigned int width, unsigned int height)
	: window(nullptr), renderer(nullptr), running(false)
{
	window = SDL_CreateWindow(name, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);
	if(window == nullptr)
	{
		std::cout << "Window could not initialize! " << SDL_GetError() << std::endl;
		return;
	}

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED && SDL_RENDERER_PRESENTVSYNC);
	if(renderer == nullptr)
	{
		std::cout << "Renderer could not initialize! " << SDL_GetError() << std::endl;
		return;
	}
	running = true;
}

SDL_Texture* TextureManager::LoadTexture(const char* path, SDL_Renderer* renderer)
{
	SDL_Texture* tex = nullptr;

	tex = IMG_LoadTexture(renderer, path);
	if(tex == nullptr)
	{
		std::cout << "Couldnt load texture. Error: " << SDL_GetError() << std::endl;
		return nullptr;
	}

	return tex;
}

void Window::Clear()
{
	SDL_RenderClear(renderer);
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
}

void Window::Display()
{
	SDL_RenderPresent(renderer);
}

Window::~Window()
{
	CleanUp();
}

void Window::CleanUp()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
}
