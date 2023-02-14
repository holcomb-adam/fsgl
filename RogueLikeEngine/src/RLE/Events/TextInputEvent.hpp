#pragma once

// --- RLE ---
#include "Event.hpp"



namespace rle
{
	class TextInputEvent final : public Event
	{
	public:
		// Implement the Event super class
		RLE_EVENT_IMPL(Type::TextInput)

	public:
		////////////////////////////////////////////////////////////////////////////////
		// - CONSTRUCTORS / DESTRUCTORS ------------------------------------------------

		// Constructor
		// - 'code': UTF-32 character input from keyboard
		TextInputEvent(const std::uint32_t code) : 
			m_Code(code)
		{ }

		// Default destructor
		~TextInputEvent() = default;



		////////////////////////////////////////////////////////////////////////////////
		// - GETTERS -------------------------------------------------------------------

		// Get the character code
		inline std::uint32_t code() const { return m_Code; }
		

	private:
		std::uint32_t m_Code = 0;
	};
}
