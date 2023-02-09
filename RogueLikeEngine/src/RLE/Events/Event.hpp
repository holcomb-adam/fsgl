#pragma once

// --- Standard ---
#include <string>

// --- RLE ---
#include "RLE/Core/Core.h"



namespace rle
{
	class Event
	{
		// Allow the EventDispatcher to access private members
		// in the Event class
		friend class EventDispatcher;

	public:
		enum class Type
		{
			None,
			KeyPress,
			KeyRelease,
			MouseMove,
			MousePress,
			MouseRelease,
			MouseScroll,
			TextInput,
			WindowClose,
			WindowSize
		};



	public:
		////////////////////////////////////////////////////////////////////////////////
		// - CONSTRUCTORS / DESTRUCTORS ------------------------------------------------

		// Default constructor
		Event() = default;

		// Virtual default constructor
		virtual ~Event() = default;



		////////////////////////////////////////////////////////////////////////////////
		// - PURE VIRTUALS -------------------------------------------------------------

		// Get the event type
		virtual Type type() const = 0;

		// Get the name of the event (debug purposes)
		virtual std::string name() const = 0;



		////////////////////////////////////////////////////////////////////////////////
		// - GETTERS -------------------------------------------------------------------

		// Check if the event has been handled
		inline bool handled() const { return m_Handled; }
		


	private:
		mutable bool m_Handled = false;
	};





	////////////////////////////////////////////////////////////////////////////////
	// - MACROS --------------------------------------------------------------------

	// The static type member identifier
#	define RLE_EVENT_STATIC_TYPE_MEMBER s_Type

	// The static type declaration
#	define RLE_EVENT_STATIC_TYPE(etype) static constexpr ::rle::Event::Type RLE_EVENT_STATIC_TYPE_MEMBER = etype

	// The Event impl
	// - Should be placed in any 'rle::Event' subclass and made public
	// - Defines the static type and overrides for the event subclass
#	define RLE_EVENT_IMPL(etype) /********************************************************/ \
		RLE_EVENT_STATIC_TYPE(etype);													   \
		inline virtual Type type() const override { return RLE_EVENT_STATIC_TYPE_MEMBER; } \
		inline virtual std::string name() const override { return RLE_STRINGIZE(etype); }
}