#pragma once

// RLE Library includes
#include "Events.h"


namespace rle
{
	class Eventable
	{
	public:
		////////////////////////////////////////////////////////////////////////////////
		// - CONSTRUCTORS / DESTRUCTORS ------------------------------------------------

		// Default constructor
		Eventable() = default;

		// Virtual default destructor
		virtual ~Eventable() = default;



		////////////////////////////////////////////////////////////////////////////////
		// - OPERATIONS ----------------------------------------------------------------

		// Distributes the events to their respective handle
		void onEvent(const Event& event);



	protected:
		////////////////////////////////////////////////////////////////////////////////
		// - EVENT HANDLES -------------------------------------------------------------

		// Called when a key is pressed or being repeated
		virtual bool onKeyPressEvent(const KeyPressEvent& event);

		// Called when a key is released
		virtual bool onKeyReleaseEvent(const KeyReleaseEvent& event);

		// Called when the mouse is moved
		virtual bool onMouseMoveEvent(const MouseMoveEvent& event);

		// Called when a mouse button is pressed
		virtual bool onMousePressEvent(const MousePressEvent& event);

		// Called when a mouse button is released
		virtual bool onMouseReleaseEvent(const MouseReleaseEvent& event);

		// Called when a mouse button is released
		virtual bool onMouseScrollEvent(const MouseScrollEvent& event);

		// Called when text is being input to the screen
		virtual bool onTextInputEvent(const TextInputEvent& event);

		// Called when the window is closed
		virtual bool onWindowCloseEvent(const WindowCloseEvent& event);

		// Called when the window is resized
		virtual bool onWindowSizeEvent(const WindowSizeEvent& event);
	};
}
