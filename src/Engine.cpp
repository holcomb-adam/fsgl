#include "RLEpch.hpp" 
#include "RLE/Core/Engine.hpp"

// --- Standard ---
#include <cassert>

// --- RLE ---
#include "RLE/Debug/Log.hpp"



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

    // Subscribe to window signals
    m_Window->SIGNAL_WindowClosed.subscribe(std::bind(
        &Engine::onSignal_WindowClosed,
        this,
        std::placeholders::_1));

    // Initialize the rendering systems
    GraphicsAPI::init(props.api);
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
    auto& uptr = m_StateStack.emplace(state);
    uptr->onStateEnter();
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

    m_StateStack.top()->onStateUpdate(delta);
}

void rle::Engine::onProcessExit()
{
    // Destroy the window
    m_Window.reset();
}

void rle::Engine::onSignal_WindowClosed(Window& window)
{
    RLE_CORE_TRACE("Window Closed Signal Recieved!");
    Process::exit();
}
