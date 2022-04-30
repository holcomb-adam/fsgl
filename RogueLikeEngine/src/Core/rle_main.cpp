#include "EntryPoint.h"

#include "EngineBase.h"
#include "Log/Log.h"

int main(int argc, char* argv[])
{
	// initialize logging systems
	if (!RLE_LOG_INIT(rle::log::GENERAL_PATH))
		return -1; // logging failed, eventually need to have a bypass

	// initialize sdl systems
	if (SDL_Init(SDL_INIT_EVERYTHING))
	{
		RLE_LOG_OUT(rle::log::ERR, "Failed to initialize sdl");
		return -2;
	}

	// create the SDL_Window
	auto* sdl_win = SDL_CreateWindow(
		"",
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		800,
		600,
		SDL_WINDOW_ALLOW_HIGHDPI | SDL_WINDOW_OPENGL);
	if (!sdl_win)
	{
		RLE_LOG_OUT(rle::log::ERR, "Failed to create SDL_Window");
		return -3;
	}

	// create the SDL_Renderer
	auto* sdl_ren = SDL_CreateRenderer(sdl_win, -1, SDL_RENDERER_ACCELERATED);
	if (!sdl_ren)
	{
		RLE_LOG_OUT(rle::log::ERR, "Failed to create SDL_Renderer");
		return -4;
	}

	// create the engine application
	auto* client = rle::client::instance(sdl_ren, sdl_win);
	if (!client)
	{
		RLE_LOG_OUT(rle::log::ERR, "Failed to create SDL_Window!");
		return -5;
	}

	// begin the application
	client->exec();

	// clean up sdl
	SDL_DestroyRenderer(sdl_ren);
	SDL_DestroyWindow(sdl_win);
	SDL_Quit();

	return 0;
}