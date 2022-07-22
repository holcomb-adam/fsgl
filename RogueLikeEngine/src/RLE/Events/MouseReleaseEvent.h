#pragma once

// RLE Library includes
#include "Event.h"



namespace rle
{
	class MouseReleaseEvent final : public Event
	{
	public:
		// Implement the Event super class
		RLE_EVENT_IMPL(Type::MouseRelease)

	public:
		////////////////////////////////////////////////////////////////////////////////
		// - CONSTRUCTORS / DESTRUCTORS ------------------------------------------------

		// Constructor
		// - 'button': The mouse button code
		// - 'mods': Modifier bits
		MouseReleaseEvent(const int button, const int mods) : 
			m_Button(button),
			m_Mods(mods)
		{ }

		// Default destructor
		~MouseReleaseEvent() = default;



		////////////////////////////////////////////////////////////////////////////////
		// - GETTERS -------------------------------------------------------------------

		// Get the button code
		inline int button() const { return m_Button; }

		// Get the modifier bits
		inline int mods() const { return m_Mods; }



	private:
		int m_Button = 0;
		int m_Mods = 0;
	};
}
