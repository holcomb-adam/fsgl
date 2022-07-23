#pragma once

// RLE Library includes
#include "Event.h"
#include "RLE/Core/KeyCodes.h"



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
		KeyReleaseEvent(const KeyCode code) :
			m_Code(code)
		{ }

		~KeyReleaseEvent() = default;



		////////////////////////////////////////////////////////////////////////////////
		// - GETTERS -------------------------------------------------------------------

		// Get the scancode
		inline KeyCode scancode() const { return m_Code; }



	private:
		KeyCode m_Code = KeyCode::Unknown;
	};
}
