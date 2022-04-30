#pragma once

#include <SDL.h>



namespace rle
{
	// RLE forward declarations
	class EngineBase;



	// client namespace this is for sending and recieving client side
	// information to and from the engine
	namespace client
	{
		// this gets the engine instance from the client
		extern EngineBase* instance(SDL_Renderer*, SDL_Window*);
	}
}



// must be placed in the constructor arsg of the client side
// EngineBase Subclass
#define RLE_CTOR_ARGS SDL_Renderer* r, SDL_Window* w

// this constructs the engine super class
// placed in list initializer
// i.e. 
// rle::client::Subclass::Subclass(RLE_CTOR_ARGS) : RLE_ENGINE_CONSTRUCT
#define RLE_ENGINE_CONSTRUCT rle::EngineBase(r, w)



// this lets the engine know what instance to create
// T - the client subclass type of EngineBase
#define RLE_INSTANCE(T) /****************************/ \
rle::EngineBase* rle::client::instance(RLE_CTOR_ARGS){ \
return new T(r, w); }                                  \
