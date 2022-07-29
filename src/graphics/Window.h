#pragma once 
#include <SDL2/SDL_image.h>
#include <SDL2/SDL.h>
#include <vector>
#include <iostream>

namespace engine 
{ 	
	class Window
	{
	public:
		Window(const char* name, unsigned int width, unsigned int height);
		
		//Gets renderer
		SDL_Renderer* GetRenderer() const;

		//Gets window
		SDL_Window* GetWindow() const;
		
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
		SDL_Renderer* renderer;
		
	};

	//Used to load all textures
	namespace TextureManager
	{
		SDL_Texture* LoadTexture(const char* path, SDL_Renderer* renderer);
	}
}



