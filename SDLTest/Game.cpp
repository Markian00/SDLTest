#include "Game.hpp"
#include <iostream>

Game::Game(): count(0), running(true), window(), renderer(){}

Game::~Game() {
}

void Game::init(const char* title, int x, int y, int width, int height) {
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
		std::cout << "Subsystem Initialization Failed" << std::endl;
		running = false;

	}
	else {
		window = SDL_CreateWindow(title, x, y, width, height, SDL_WINDOW_FULLSCREEN);
		if (!window) {
			std::cout << "Window Failed" << std::endl;
		}
		
		renderer = SDL_CreateRenderer(window, -1, 0);
		if (!renderer) {
			std::cout << "Renderer Failed" << std::endl;
		}
		else {
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		}
	}
}

void Game::handle() {
	SDL_Event event;
	SDL_PollEvent(&event);
	if (event.type == SDL_QUIT) {
		running = false;
	}
}

void Game::update() {
	count++;
	std::cout << count << std::endl;
}

void Game::render(){
	SDL_RenderClear(renderer);
	//Rendering things
	SDL_RenderPresent(renderer);
}

void Game::clean() {
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	std::cout << "Closed Game" << std::endl;
}