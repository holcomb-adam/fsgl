#include "fsgl_pch.hpp" 
#include "fsgl/Core/Engine.hpp"

// --- Standard ---
#include <cassert>

// --- fsgl ---
#include "fsgl/Debug/Log.hpp"



namespace
{
    static fsgl::Engine* s_EngineInstance = nullptr;
}



fsgl::Engine* fsgl::Engine::get()
{
    return s_EngineInstance;
}



fsgl::Engine::Engine(const Window::Properties& props) :
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

std::unique_ptr<fsgl::Window>& fsgl::Engine::getWindow()
{
    return m_Window;
}

const std::unique_ptr<fsgl::Window>& fsgl::Engine::getWindow() const
{
    return m_Window;
}

void fsgl::Engine::pushState(EngineState* state)
{
    auto& uptr = m_StateStack.emplace(state);
    uptr->onStateEnter();
}

void fsgl::Engine::onProcessInit(int argc, char* argv[])
{
    onEngineInit(argc, argv);
}

void fsgl::Engine::onProcessUpdate(const time::step_ms delta)
{
    // Update the window and handle event polling
    m_Window->update();

    // Update the any user engine components
    onEngineUpdate(delta);

    m_StateStack.top()->onStateUpdate(delta);
}

void fsgl::Engine::onProcessExit()
{
    // Destroy the window
    m_Window.reset();
}

void fsgl::Engine::onSignal_WindowClosed(Window& window)
{
    FSGL_CORE_TRACE("Window Closed Signal Recieved!");
    Process::exit();
}
