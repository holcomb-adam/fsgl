#pragma once

// --- Standard ---
#include <stack>

// --- fsgl ---
#include "Core.hpp"
#include "EngineState.hpp"
#include "Process.hpp"
#include "Window.hpp"
#include "fsgl/Events/Signal.hpp"



namespace fsgl
{
    // Cool color: (0.57, 0.34, 0.78, 1.0)
    // - Possible fsgl secondary theme color



    /// @brief This class represents the base application of the engine
    class Engine : public Process
    {
    public:
        ////////////////////////////////////////////////////////////////////////////////
        // - STATIC MEMBERS ------------------------------------------------------------

        // Get the engine instance
        static Engine* get();



    public:
        ////////////////////////////////////////////////////////////////////////////////
        // - CONSTRUCTORS / DESTRUCTORS ------------------------------------------------

        /// @brief Constructor
        /// @param props The properties of the window (see: 'fsgl::Window::Properties')
        Engine(const Window::Properties& props = Window::Properties{});

        /// @brief 
        virtual ~Engine() = default;



        ////////////////////////////////////////////////////////////////////////////////
        // - GETTERS -------------------------------------------------------------------

        /// @brief Window getter
        /// @returns Get a reference to a unique_ptr of the engines window
        std::unique_ptr<Window>& getWindow();
        const std::unique_ptr<Window>& getWindow() const;



        ////////////////////////////////////////////////////////////////////////////////
        // - OPERATIONS ----------------------------------------------------------------

        /// @brief Add a state to the top of the engines state stack
        /// @param state The state pointer being pushed
        /// @note Assumes ownership of the pointer taken
        void pushState(EngineState* state);



    private:
        ////////////////////////////////////////////////////////////////////////////////
        // - VIRTUALS ------------------------------------------------------------------

        /// @brief Called once every frame to update the client engine
        /// @param delta 
        virtual void onEngineUpdate(const time::step_ms delta) = 0;

        /// @brief 
        /// @param argc 
        /// @param argv 
        virtual void onEngineInit(int argc, char* argv[]) = 0;



        virtual void onProcessInit(int argc, char* argv[]) override;
        virtual void onProcessUpdate(const time::step_ms delta) override;
        virtual void onProcessExit() override;




        /// @brief 
        /// @param window 
        void onSignal_WindowClosed(Window& window);



    private:
        std::unique_ptr<Window> m_Window;
        std::stack<std::unique_ptr<EngineState>> m_StateStack;
    };
}
