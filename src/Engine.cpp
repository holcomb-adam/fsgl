#include "RLEpch.hpp" 
#include "RLE/Core/Engine.hpp"

// --- Standard ---
#include <cassert>

// --- RLE ---
#include "RLE/Debug/Log.hpp"
#include "RLE/Events/EventDispatcher.hpp"
#include "RLE/Rendering/RenderCommands.hpp"
#include "RLE/UI/Layer.hpp"



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
	m_Window->setEventCallback(RLE_BIND_EVENT_FN(Engine::onEvent));

	// Initialize the rendering systems
	RenderCommands::init(props.api);
}

void rle::Engine::push(Layer* layer)
{
	m_LayerStack.push(layer);
}

void rle::Engine::pushOverlay(Layer* layer)
{
	m_LayerStack.pushOverlay(layer);
}

int rle::Engine::exec()
{
	// Set the running flag
	m_Running = true;

	// get a starting point to
	auto last_elapsed = time::now();

	// being the application loop
	while (m_Running)
	{
		// Calculate the time elapsed
		const auto recent_time = time::now();
		const auto elapsed_delta = recent_time - last_elapsed;
		last_elapsed = recent_time;

		// update the engine
		impl_update(elapsed_delta);

		// Perform the rendering processes rendering
		impl_render();
	}

	// Destroy the window
	m_Window.reset();

	return 0;
}

void rle::Engine::exit()
{
	m_Running = false;
}

void rle::Engine::onEvent(const Event& event)
{
	// Dispatch events to the proper callers
	EventDispatcher dispatcher(event);
	dispatcher.dispatch<WindowCloseEvent>(RLE_BIND_EVENT_FN(Engine::windowCloseEvent));

	// Propagate the events down the layers
	for (auto it = m_LayerStack.rbegin(); it != m_LayerStack.rend(); it++)
	{
		// Check if the event has been handled
		if (event.handled())
			break;

		// Try handling the event
		(*it)->onEvent(event);
	}
}

std::unique_ptr<rle::Window>& rle::Engine::window()
{
	return m_Window;
}

const std::unique_ptr<rle::Window>& rle::Engine::window() const
{
	return m_Window;
}

void rle::Engine::impl_update(const time::step_ms delta)
{
	// update our window
	// this will handle event polling for us
	m_Window->update();

	// Update the client engine
	onUpdate(delta);

	// Iterate through and update the layers
	for (auto* layer : m_LayerStack)
		layer->onUpdate(delta);
}

void rle::Engine::impl_render()
{
	// Clear any current rendering
	RenderCommands::setClearColor({ 1.00f, 0.00f, 1.0f, 1.0f });
	RenderCommands::clear();

	// Call client pre-rendering
	onPreRender();

	// Call client rendering
	onRender(m_Renderer);

	// Draw all the layers
	for (const auto* layer : m_LayerStack)
		layer->onRender(m_Renderer);

	// End the rendering
	m_Renderer.endScene();

	// Call client post-rendering
	onPostRender();
}

bool rle::Engine::windowCloseEvent(const WindowCloseEvent& event)
{
	exit();
	return false;
}
