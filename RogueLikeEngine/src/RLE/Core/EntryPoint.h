#pragma once



namespace rle
{
	// RLE Forward Declarations
	class Engine;



	// 'entry' namespace
	//  - This namespace is used for communication between the client
	//    and the engine
	namespace entry
	{
		// This gets the engine instance from the client
		extern ::rle::Engine* instance();
	}
}



// This lets the engine know what instance to create
// - T: The client subclass type of EngineBase
#define RLE_INSTANCE(T) /**************/ \
::rle::Engine* ::rle::entry::instance(){ \
	return new T(); }
