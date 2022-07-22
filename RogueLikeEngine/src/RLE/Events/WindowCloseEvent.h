#pragma once

// RLE Library includes
#include "Event.h"



namespace rle
{
	class WindowCloseEvent final : public Event
	{
	public:
		// Implement the Event super class
		RLE_EVENT_IMPL(Type::WindowClose)

	public:
		////////////////////////////////////////////////////////////////////////////////
		// - CONSTRUCTORS / DESTRUCTORS ------------------------------------------------

		// Default constructor
		WindowCloseEvent() = default;

		// Default destructor
		~WindowCloseEvent() = default;
	};
}