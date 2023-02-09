#pragma once

// --- RLE ---
#include "Event.h"



namespace rle
{
	class MouseMoveEvent final : public Event
	{
	public:
		// Implement the Event super class
		RLE_EVENT_IMPL(Type::MouseMove)

	public:
		////////////////////////////////////////////////////////////////////////////////
		// - CONSTRUCTORS / DESTRUCTORS ------------------------------------------------

		// Constructor
		// - 'x': The x position in screen coordinates of the cursor
		// - 'y': The y position in screen coordinates of the cursor
		MouseMoveEvent(const double x, const double y) :
			m_X(x),
			m_Y(y)
		{ }

		// Default destructor
		~MouseMoveEvent() = default;



		////////////////////////////////////////////////////////////////////////////////
		// - GETTERS -------------------------------------------------------------------

		// Get the x position in screen coordinates of the cursor
		inline double x() const { return m_X; }

		// Get the y position in screen coordinates of the cursor
		inline double y() const { return m_Y; }



	private:
		double m_X = 0.0;
		double m_Y = 0.0;
	};
}
