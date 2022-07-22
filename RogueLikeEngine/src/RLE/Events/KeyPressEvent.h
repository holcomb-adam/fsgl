#pragma once

// RLE Library includes
#include "Event.h"



namespace rle
{
	class KeyPressEvent final : public Event
	{
	public:
		// Implement the Event super class
		RLE_EVENT_IMPL(Type::KeyPress)

	public:
		////////////////////////////////////////////////////////////////////////////////
		// - CONSTRUCTORS / DESTRUCTORS ------------------------------------------------

		// Contructor
		// - 'code': The scancode of the key that was pressed
		// - 'repeat': Whether or not the key is being repeated
		KeyPressEvent(const int code, const bool repeat) : 
			m_Scancode(code),
			m_Repeat(repeat)
		{ }

		// Default destructor
		~KeyPressEvent() = default;



		////////////////////////////////////////////////////////////////////////////////
		// - GETTERS -------------------------------------------------------------------

		// Get the scancode
		inline int scancode() const { return m_Scancode; }

		// Get whether or not the key is repeating
		inline bool repeating() const { return m_Repeat; }



	private:
		int m_Scancode = 0;
		bool m_Repeat = false;
	};
}