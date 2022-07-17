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

	//Clears renderer
	void Clear();

	//Presents(displays) the renderer
	void Display();

	//Running state of the game
	bool running;

	//Cleanup and destructor
	void CleanUp();
	~Window();
	
private:
	SDL_Window* window;
};


//Used to load all textures
namespace TextureManager
{
	SDL_Texture* LoadTexture(const char* path, SDL_Renderer* renderer);
}
