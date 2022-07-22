#pragma once

// RLE Library includes
#include "Event.h"



namespace rle
{
	class KeyReleaseEvent final : public Event
	{
	public:
		// Implement the Event super class
		RLE_EVENT_IMPL(Type::KeyRelease)

	public:
		////////////////////////////////////////////////////////////////////////////////
		// - CONSTRUCTORS / DESTRUCTORS ------------------------------------------------

		// Constructor
		// - 'code': The scancode of the key that was pressed
		KeyReleaseEvent(const int code) :
			m_Scancode(code)
		{ }

		~KeyReleaseEvent() = default;



		////////////////////////////////////////////////////////////////////////////////
		// - GETTERS -------------------------------------------------------------------

		// Get the scancode
		inline int scancode() const { return m_Scancode; }



	private:
		int m_Scancode = 0;
	};
}
