#pragma once

// RLE Library includes
#include "Event.h"



namespace rle
{
	class WindowSizeEvent final : public Event
	{
	public:
		// Implement the Event super class
		RLE_EVENT_IMPL(Type::WindowSize)

	public:
		////////////////////////////////////////////////////////////////////////////////
		// - CONSTRUCTORS / DESTRUCTORS ------------------------------------------------

		// Constructor
		// - 'x': The width of the window in pixels
		// - 'y': The height of the window in pixels
		WindowSizeEvent(const int x, const int y) :
			m_X(x),
			m_Y()
		{ }

		// Default destructor
		~WindowSizeEvent() = default;



		////////////////////////////////////////////////////////////////////////////////
		// - GETTERS -------------------------------------------------------------------

		// Get the x value
		inline int x() const { return m_X; }

		// Get the y value
		inline int y() const { return m_Y; }

	private:
		int m_X = 0;
		int m_Y = 0;
	};
}
