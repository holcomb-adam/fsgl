#include <SDL.h>

#include "core/EngineBase.h"
#include "EngineUI/EngineStates/GameScene.h"



constexpr auto WIN_TITLE = "Rouge-like Engine";



int main(int argc, char* argv[])
{
	// initialize sdl systems
	if (SDL_Init(SDL_INIT_EVERYTHING))
		return -1;

	// create the SDL_Window
	SDL_Window* sdl_win = SDL_CreateWindow(
		WIN_TITLE,
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		800,
		600,
		SDL_WINDOW_ALLOW_HIGHDPI | SDL_WINDOW_OPENGL);
	if (!sdl_win)
		return -2;

	// create the SDL_Renderer
	SDL_Renderer* sdl_ren = SDL_CreateRenderer(sdl_win, -1, SDL_RENDERER_ACCELERATED);
	if (!sdl_ren)
		return -3;

	// create the engine application
	rle::EngineBase rle_engine(sdl_ren, sdl_win);

	// add the game scene to the engine application
	rle_engine.pushState<rle::GameScene>();

	// run the engine
	const auto rt_code = rle_engine.exec();

	// quit SDL
	SDL_Quit();

	return rt_code;
}