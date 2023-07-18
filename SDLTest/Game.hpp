#ifndef Game_hpp
#define Game_hpp

#include "SDL.h"

class Game {
public:
	Game();
	~Game();

	void init(const char* title, int x, int y, int width, int height);

	void update();
	void render();
	void clean();
	void handle();

	bool isRunning() {
		return running;
	}

private:
	int count;
	bool running;
	SDL_Window* window;
	SDL_Renderer* renderer;
};
#endif /* Game_hpp */