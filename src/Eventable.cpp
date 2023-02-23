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
	dispatcher.dispatch<KeyPressEvent>(RLE_BIND_THIS_FN(Eventable::onKeyPressEvent, std::placeholders::_1));
	dispatcher.dispatch<KeyReleaseEvent>(RLE_BIND_THIS_FN(Eventable::onKeyReleaseEvent, std::placeholders::_1));
	dispatcher.dispatch<MouseMoveEvent>(RLE_BIND_THIS_FN(Eventable::onMouseMoveEvent, std::placeholders::_1));
	dispatcher.dispatch<MousePressEvent>(RLE_BIND_THIS_FN(Eventable::onMousePressEvent, std::placeholders::_1));
	dispatcher.dispatch<MouseReleaseEvent>(RLE_BIND_THIS_FN(Eventable::onMouseReleaseEvent, std::placeholders::_1));
	dispatcher.dispatch<MouseScrollEvent>(RLE_BIND_THIS_FN(Eventable::onMouseScrollEvent, std::placeholders::_1));
	dispatcher.dispatch<TextInputEvent>(RLE_BIND_THIS_FN(Eventable::onTextInputEvent, std::placeholders::_1));
	dispatcher.dispatch<WindowCloseEvent>(RLE_BIND_THIS_FN(Eventable::onWindowCloseEvent, std::placeholders::_1));
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
