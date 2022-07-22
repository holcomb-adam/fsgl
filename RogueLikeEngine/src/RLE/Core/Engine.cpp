#include "RLEpch.h" 
#include "Engine.h"

// Standard Library includes
#include <chrono>

// RLE Library includes
#include "RLE/Debug/Log.h"
#include "RLE/Events/EventDispatcher.h"
#include "RLE/UI/Layer.h"





rle::Engine* rle::Engine::get()
{
	return s_EngineInstance;
}

rle::Engine::Engine(const Window::Properties& props) :
	m_Window(Window::create(props))
{
	// Ensure we only construct 1 instance
	assert(!s_EngineInstance);

	// Set the singleton instance
	s_EngineInstance = this;



	m_Window->setEventCallback(RLE_BIND_EVENT_FN(Engine::onEvent));
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
	auto last_elapsed = std::chrono::steady_clock::now();

	// being the application loop
	while (m_Running)
	{
		// Calculate the time elapsed
		const auto recent_time = std::chrono::steady_clock::now();
		const auto elapsed_delta = static_cast<float>((recent_time - last_elapsed).count() * 1e-6f);
		last_elapsed = recent_time;

		// update the engine
		update(elapsed_delta);
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

void rle::Engine::update(const float delta)
{
	// update our window
	// this will handle event polling for us
	m_Window->update();

	// Iterate through and update the layers
	for (auto* layer : m_LayerStack)
		layer->onUpdate(delta);
}

bool rle::Engine::windowCloseEvent(const WindowCloseEvent& event)
{
	exit();
	return false;
}
