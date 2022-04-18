#pragma once

#include "Rendering/Graphics/2D/Drawable2D.h"
#include "Utils/UniqueID.h"



namespace rle
{
	class EngineState : public Drawable2D
	{
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
	};
}
