#pragma once

// --- RLE ---
#include "Event.h"



namespace rle
{
	class MousePressEvent final : public Event
	{
	public:
		// Implement the Event super class
		RLE_EVENT_IMPL(Type::MousePress)

	public:
		////////////////////////////////////////////////////////////////////////////////
		// - CONSTRUCTORS / DESTRUCTORS ------------------------------------------------

		// Constructor
		// - 'button': The mouse button code
		// - 'mods': Modifier bits
		MousePressEvent(const int button, const int mods) : 
			m_Button(button),
			m_Mods(mods)
		{ }

		// Default destructor
		~MousePressEvent() = default;



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
