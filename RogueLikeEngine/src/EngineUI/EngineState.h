#pragma once

// rle library includes
#include "Rendering/Graphics/2D/Drawable2D.h"
#include "Utils/UniqueID.h"



// SDL2 forward declarations
struct SDL_KeyboardEvent;


namespace rle
{
	// rle forward declarations
	class EngineBase;



	class EngineState : public Drawable2D
	{
		friend class EngineBase;
	public:
		UniqueID<EngineState> m_UID;

	public:
		////////////////////////////////////////////////////////////////////////////////
		// - CONSTRUCTORS / DESTRUCTORS ------------------------------------------------
		
		// default ctor
		EngineState() = default;

		// virtual default dtor
		virtual ~EngineState() = default;



		////////////////////////////////////////////////////////////////////////////////
		// - PUBLIC PURE VIRTUALS ------------------------------------------------------

		// called when the state is made active
		virtual void onEnter() = 0;

		// called when the state is popped
		virtual void onExit() = 0;

		// called when the state needs to be updated
		// takes a float parameter that specifies the time elapsed since last update cycle
		virtual void update(const float delta) = 0;

	protected:

		////////////////////////////////////////////////////////////////////////////////
		// - EVENT HANDLES -------------------------------------------------------------

		// keyboard press events
		virtual void keyPressEvent(const SDL_KeyboardEvent& event) {}
	};
}
