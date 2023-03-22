#include "RLEpch.hpp" 
#include "RLE/Core/Engine.hpp"

// --- Standard ---
#include <cassert>

// --- RLE ---
#include "RLE/Debug/Log.hpp"
#include "RLE/Events/EventDispatcher.hpp"
#include "RLE/Rendering/RenderCommands.hpp"



namespace
{
	static rle::Engine* s_EngineInstance = nullptr;
}



rle::Engine* rle::Engine::get()
{
	return s_EngineInstance;
}



rle::Engine::Engine(const Window::Properties& props) :
	m_Window(factory<Window>::create(props))
{
	// TODO: This should be converted to a better singleton design
	// Ensure we only construct 1 instance rather than just an assert check
	assert(!s_EngineInstance);

	// Set the singleton instance
	s_EngineInstance = this;


	
	// Give the window our event callback functions
	m_Window->setEventCallback(RLE_BIND_THIS_FN(Engine::onEvent, std::placeholders::_1));

	// Initialize the rendering systems
	RenderCommands::init(props.api);
}

std::unique_ptr<rle::Window>& rle::Engine::getWindow()
{
	return m_Window;
}

const std::unique_ptr<rle::Window>& rle::Engine::getWindow() const
{
	return m_Window;
}

void rle::Engine::pushState(EngineState* state)
{
    m_StateStack.emplace(state)->enter();
}

void rle::Engine::onProcessInit(int argc, char* argv[])
{
	onEngineInit(argc, argv);
}

void rle::Engine::onProcessUpdate(const time::step_ms delta)
{
	// Update the window and handle event polling
	m_Window->update();

	// Update the any user engine components
	onEngineUpdate(delta);

	m_StateStack.top()->update(delta);
}

void rle::Engine::onProcessExit()
{
	// Destroy the window
	m_Window.reset();
}

bool rle::Engine::windowCloseEvent(const WindowCloseEvent& event)
{
	exit();
	return false;
}

void rle::Engine::onEvent(const Event& event)
{
	// Dispatch events to the proper callers
	EventDispatcher dispatcher(event);
	dispatcher.dispatch<WindowCloseEvent>(RLE_BIND_THIS_FN(Engine::windowCloseEvent, std::placeholders::_1));


	// Propagate the events down the layers
	// for (auto it = m_LayerStack.rbegin(); it != m_LayerStack.rend(); it++)
	// {
	// 	// Check if the event has been handled
	// 	if (event.handled())
	// 		break;

	// 	// Try handling the event
	// 	(*it)->onEvent(event);
	// }
}
