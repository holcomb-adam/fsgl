#pragma once

// Standard Library includes
#include <functional>

// RLE Library includes
#include "Core.h"
#include "RLE/Events/Event.h"



namespace rle
{
	// This class represents an abstract "Window"
	// - Interface for designing a window for a platform
	//   (i.e. Windows, MacOS, Linux, etc.)
	class Window
	{
	public:
		////////////////////////////////////////////////////////////////////////////////
		// - MEMBER TYPES --------------------------------------------------------------

		// Type alias for event call back function
		using EventCallback = std::function<void(Event&)>;

		// Simple POD structure to define the properties of the window
		// - 'title': The title diplayed at the top of the window
		// - 'w': The width of the window in pixels
		// - 'h': The height of the window in pixels
		struct Properties final
		{
			std::string title = "";
			std::uint32_t w = 800;
			std::uint32_t h = 600;

			bool vsync = false;
		};



		////////////////////////////////////////////////////////////////////////////////
		// - STATIC MEMBERS ------------------------------------------------------------

		// Used for creating an instance of the window
		static std::unique_ptr<Window> create(const Properties& props = Properties{});
		

	public:
		////////////////////////////////////////////////////////////////////////////////
		// - CONSTRUCTORS / DESTRUCTORS ------------------------------------------------

		// Default constructor
		Window() = default;

		// Virtual default destructor
		virtual ~Window() = default;



		////////////////////////////////////////////////////////////////////////////////
		// - PURE VIRTUALS -------------------------------------------------------------

		// Called every frame when the window needs to update
		virtual void update() = 0;

		// Get the width of the window in pixels
		virtual std::uint32_t width() const = 0;

		// Get the height of the window in pixels
		virtual std::uint32_t height() const = 0;

		// Set the window Event function callback
		virtual void setEventCallback(const EventCallback& callback) = 0;

		// Set VSync flag
		virtual void setVSync(const bool enabled) = 0;

		// Get VSync flag
		virtual bool isVSync() const = 0;

		// Get the native handle to the window
		virtual void* nativeHandle() const = 0;
	};
}
