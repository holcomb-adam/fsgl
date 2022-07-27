#pragma once

// RLE Library includes
#include "Core.h"
#include "Time.h"
#include "Window.h"
#include "RLE/Events/WindowCloseEvent.h"
#include "RLE/UI/LayerStack.h"



namespace rle
{
	// This class represents the base application of the engine
	class Engine
	{
		// Singleton Engine Instance
		inline static Engine* s_EngineInstance = nullptr;



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
		// - PURE VIRTUALS -------------------------------------------------------------

		// For post-instantiation initialization
		// returns code (0 is considered a safe return)
		virtual std::size_t init() = 0;

		// Called once every frame to update the client engine
		virtual void onUpdate(const time::step_ms delta) = 0;

		// Called before rendering begins
		virtual void onPreRender() = 0;

		// Called when the rendering process begins
		virtual void onRender() const = 0;

		// Called after rendering has ended
		virtual void onPostRender() = 0;




		////////////////////////////////////////////////////////////////////////////////
		// - WRAPPERS ------------------------------------------------------------------

		// see: rle::LayerStack::push
		void push(Layer* layer);

		// see: rle::LayerStack::pushOverlay
		void pushOverlay(Layer* layer);



		////////////////////////////////////////////////////////////////////////////////
		// - OPERATIONS ----------------------------------------------------------------

		// Begins the engine's application loop
		int exec();

		// Ends the engine's application loop
		void exit();

		// Called when the window recieves any events
		void onEvent(const Event& event);



		////////////////////////////////////////////////////////////////////////////////
		// - GETTERS -------------------------------------------------------------------

		// Get a ref to a unique_ptr to a window
		std::unique_ptr<Window>& window();

		// Get a const ref to a unique_ptr to a window
		const std::unique_ptr<Window>& window() const;



	private:
		// Updates the engine and it's layers
		// - Called once every frame
		void impl_update(const time::step_ms delta);

		// Performs the rendering to the client engine and all the layers that are
		// in the layer stack
		// - Called once every frame
		void impl_render();

		// Called when the window close event is recieved
		bool windowCloseEvent(const WindowCloseEvent& event);
		


	private:
		bool m_Running = false;

		std::unique_ptr<Window> m_Window;
		LayerStack m_LayerStack;
	};
}
