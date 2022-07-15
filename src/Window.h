#pragma once 
#include <SDL2/SDL_image.h>
#include <SDL2/SDL.h>
#include <vector>
#include <iostream>

class Window
{
public:
	Window(const char* name, unsigned int width, unsigned int height);
	SDL_Renderer* renderer;

	void Clear();
	void Display();

	bool running;

	void CleanUp();
	~Window();
	
private:
	SDL_Window* window;
};

namespace TextureManager
{
	SDL_Texture* LoadTexture(const char* path, SDL_Renderer* renderer);
}
