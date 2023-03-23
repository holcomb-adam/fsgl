#pragma once

// --- Standard ---
#include <stack>

// --- RLE ---
#include "Core.hpp"
#include "EngineState.hpp"
#include "Process.hpp"
#include "Window.hpp"
#include "RLE/Events/WindowCloseEvent.hpp"



namespace rle
{
	// Cool color: (0.57, 0.34, 0.78, 1.0)
	// - Possible RLE secondary theme color



	/// @brief This class represents the base application of the engine
	class Engine : public Process
	{
	public:
		////////////////////////////////////////////////////////////////////////////////
		// - PUBLIC STATIC MEMBERS -----------------------------------------------------

		// Get the engine instance
		static Engine* get();



	public:
		////////////////////////////////////////////////////////////////////////////////
		// - CONSTRUCTORS / DESTRUCTORS ------------------------------------------------
		
		// Constructor
		// - 'props': The properties of the window (see: 'rle::Window::Properties')
		Engine(const Window::Properties& props = Window::Properties{});

		// Virtual default destructor
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
		virtual void onEngineUpdate(const time::step_ms delta) = 0;

		/// @brief 
		/// @param argc 
		/// @param argv 
		virtual void onEngineInit(int argc, char* argv[]) = 0;



		virtual void onProcessInit(int argc, char* argv[]) override;
		virtual void onProcessUpdate(const time::step_ms delta) override;
		virtual void onProcessExit() override;



		// Called when the window recieves any events
		void onEvent(const Event& event);

		// Called when the window close event is recieved
		bool windowCloseEvent(const WindowCloseEvent& event);



	private:
		std::unique_ptr<Window> m_Window;
		std::stack<std::unique_ptr<EngineState>> m_StateStack;
	};
}
