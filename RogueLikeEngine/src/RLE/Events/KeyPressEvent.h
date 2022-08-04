#pragma once

// --- RLE ---
#include "Event.h"
#include "RLE/Core/KeyCodes.h"



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
		// - 'code': The code of the key that was pressed
		// - 'repeat': Whether or not the key is being repeated
		KeyPressEvent(const KeyCode code, const bool repeat) :
			m_Code(code),
			m_Repeat(repeat)
		{ }

		// Default destructor
		~KeyPressEvent() = default;



		////////////////////////////////////////////////////////////////////////////////
		// - GETTERS -------------------------------------------------------------------

		// Get the scancode
		inline KeyCode code() const { return m_Code; }

		// Get whether or not the key is repeating
		inline bool repeating() const { return m_Repeat; }



	private:
		KeyCode m_Code = KeyCode::Unknown;
		bool m_Repeat = false;
	};
}