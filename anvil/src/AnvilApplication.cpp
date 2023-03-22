#include "AnvilApplication.hpp"



anvil::AnvilApplication::AnvilApplication() :
	rle::Engine(
		rle::Window::Properties
		{
			.title = "RLE Anvil v0.0.0",
			.w = 1280,
			.h = 960
		})
{

}

void anvil::AnvilApplication::onEngineUpdate(const rle::time::step_ms delta)
{

}

void anvil::AnvilApplication::onEngineInit(int argc, char* argv[])
{

}
