// SDLTest.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Game.hpp"

int main(int argc, char* argv[])
{
	Game* game = new Game();
	game->init("game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600);
	while (game->isRunning()) {
		game->handle();
		game->update();
		game->render();
	}
	game->clean();
	return 0;
}
