#pragma once

// Standard Library includes
#include <functional>
#include <vector>

// RLE Library includes
#include "Event.h"



namespace rle
{
	class EventDispatcher final
	{
		////////////////////////////////////////////////////////////////////////////////
		// - MEMBER TYPES --------------------------------------------------------------

		// Event callback function
		template<class T>
		using EventFn = std::function<bool(const T&)>;



	public:
		////////////////////////////////////////////////////////////////////////////////
		// - CONSTRUCTORS / DESTRUCTORS ------------------------------------------------

		// Constructor
		// - 'event': The event reference that is stored in the dispatcher
		EventDispatcher(const Event& event);



		////////////////////////////////////////////////////////////////////////////////
		// - OPERATIONS ----------------------------------------------------------------

		// Send the event to the callback if the event types match
		// - Template 'T': The event type that checks against the stored event
		template<class T>
		bool dispatch(const EventFn<T>& callback);



	private:
		const Event& m_Event;
	};



	inline EventDispatcher::EventDispatcher(const Event& event) :
		m_Event(event)
	{

	}



	template<class T>
	inline bool EventDispatcher::dispatch(const EventFn<T>& callback)
	{
		if (m_Event.type() == T:: RLE_EVENT_STATIC_TYPE_MEMBER)
		{
			m_Event.m_Handled = callback(static_cast<const T&>(m_Event));
			return true;
		}
		return false;
	}
}