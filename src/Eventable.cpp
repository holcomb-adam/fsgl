#include "RLEpch.hpp"
#include "RLE/Events/Eventable.hpp"

// --- RLE ---
#include "RLE/Core/Core.hpp"
#include "RLE/Events/EventDispatcher.hpp"



void rle::Eventable::onEvent(const Event& event)
{
	// Create our event dispatcher
	EventDispatcher dispatcher(event);

	// Dispatch the event to the respective handle
	dispatcher.dispatch<KeyPressEvent>(RLE_BIND_EVENT_FN(Eventable::onKeyPressEvent));
	dispatcher.dispatch<KeyReleaseEvent>(RLE_BIND_EVENT_FN(Eventable::onKeyReleaseEvent));
	dispatcher.dispatch<MouseMoveEvent>(RLE_BIND_EVENT_FN(Eventable::onMouseMoveEvent));
	dispatcher.dispatch<MousePressEvent>(RLE_BIND_EVENT_FN(Eventable::onMousePressEvent));
	dispatcher.dispatch<MouseReleaseEvent>(RLE_BIND_EVENT_FN(Eventable::onMouseReleaseEvent));
	dispatcher.dispatch<MouseScrollEvent>(RLE_BIND_EVENT_FN(Eventable::onMouseScrollEvent));
	dispatcher.dispatch<TextInputEvent>(RLE_BIND_EVENT_FN(Eventable::onTextInputEvent));
	dispatcher.dispatch<WindowCloseEvent>(RLE_BIND_EVENT_FN(Eventable::onWindowCloseEvent));
}

bool rle::Eventable::onKeyPressEvent(const KeyPressEvent& event)
{
	return false;
}

bool rle::Eventable::onKeyReleaseEvent(const KeyReleaseEvent& event)
{
	return false;
}

bool rle::Eventable::onMouseMoveEvent(const MouseMoveEvent& event)
{
	return false;
}

bool rle::Eventable::onMousePressEvent(const MousePressEvent& event)
{
	return false;
}

bool rle::Eventable::onMouseReleaseEvent(const MouseReleaseEvent& event)
{
	return false;
}

bool rle::Eventable::onMouseScrollEvent(const MouseScrollEvent& event)
{
	return false;
}

bool rle::Eventable::onTextInputEvent(const TextInputEvent& event)
{
	return false;
}

bool rle::Eventable::onWindowCloseEvent(const WindowCloseEvent& event)
{
	return false;
}

bool rle::Eventable::onWindowSizeEvent(const WindowSizeEvent& event)
{
	return false;
}
