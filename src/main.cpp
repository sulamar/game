#include "Game.h"

int main(int argc, char* args[])
{
	if(engine::Game::Init())
		engine::Game::Run();

	return 0;
}