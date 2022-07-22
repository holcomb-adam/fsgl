#pragma once

// RLE Library includes
#include "RLE/Events/Eventable.h"



namespace rle
{
	class Layer : public Eventable
	{
	public:
		////////////////////////////////////////////////////////////////////////////////
		// - CONSTRUCTORS / DESTRUCTORS ------------------------------------------------

		// Default constructor
		Layer() = default;

		// Virtual default destructor
		virtual ~Layer() = default;



		////////////////////////////////////////////////////////////////////////////////
		// - PURE VIRTUALS -------------------------------------------------------------

		// Called when the layer is added to the state machine
		virtual void onEnter() = 0;

		// Called when the layer leaves the state machine
		virtual void onExit() = 0;

		// Called once every frame to update the layer
		virtual void onUpdate(const float delta) = 0;
	};
}
