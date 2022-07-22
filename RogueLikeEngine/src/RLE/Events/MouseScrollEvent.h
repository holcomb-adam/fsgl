#pragma once

// RLE Library include
#include "Event.h"



namespace rle
{
	class MouseScrollEvent final : public Event
	{
	public:
		// Implement the Event super class
		RLE_EVENT_IMPL(Type::MouseScroll)

	public:
		////////////////////////////////////////////////////////////////////////////////
		// - CONSTRUCTORS / DESTRUCTORS ------------------------------------------------

		// Constructor
		// - 'xoff': X-offset from mouse wheel or scroll gesture
		// - 'yoff': Y-offset from mouse wheel or scroll gesture
		MouseScrollEvent(const double xoff, const double yoff) :
			m_XOffset(xoff),
			m_YOffset(yoff)
		{ }

		// Default destructor
		~MouseScrollEvent() = default;



		////////////////////////////////////////////////////////////////////////////////
		// - GETTERS -------------------------------------------------------------------

		// Get the x offset
		inline double xoff() const { return m_XOffset; }

		// Get the y offset
		inline double yoff() const { return m_YOffset; }



	private:
		double m_XOffset = 0.0;
		double m_YOffset = 0.0;
	};
}
