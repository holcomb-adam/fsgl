#pragma once

// RLE Library includes
#include "RLE/Core/Window.h"



// GLFW Forward Declarations
struct GLFWwindow;



namespace rle
{
	class Win64_Window final : public Window
	{
		// Friend functions
		friend void closeCallback(GLFWwindow*);
		friend void keyCallback(GLFWwindow*, const int, const int, const int, const int);
		friend void textCallback(GLFWwindow*, const unsigned int);
		friend void mouseMoveCallback(GLFWwindow*, const double, const double);
		friend void mouseButtonCallback(GLFWwindow*, const int, const int, const int);
		friend void scrollCallback(GLFWwindow*, const double, const double);
		friend void sizeCallback(GLFWwindow*, const int, const int);



	public:
		////////////////////////////////////////////////////////////////////////////////
		// - CONSTRUCTORS / DESTRUCTORS ------------------------------------------------

		// Constructor
		// - Initializes GLFW 3
		// - 'props': Window properties defining the window
		//   (i.e. Title, Width, Height, etc.)
		Win64_Window(const Properties& props);

		// Destructor
		// - Uninitializes GLFW 3 if no windows remain
		~Win64_Window();



		////////////////////////////////////////////////////////////////////////////////
		// - OVERRIDES -----------------------------------------------------------------
	
		// Inherited via Window
		virtual void update() override;
		virtual std::uint32_t width() const override;
		virtual std::uint32_t height() const override;
		virtual void setEventCallback(const EventCallback& callback) override;
		virtual void setVSync(const bool enabled) override;
		virtual bool isVSync() const override;
		virtual void* nativeHandle() const override;



	private:
		GLFWwindow* m_Window = nullptr;

		std::string m_Title = "";
		std::uint32_t m_Width = 0;
		std::uint32_t m_Height = 0;

		bool m_VSync = false;

		// TODO: This could eventually be moved to 'rle::Window' and the
		//       callback functions in the .cpp file could be moved to their own
		//       file and use 'rle::Window' instead of 'rle::Win64_Window'
		EventCallback m_EventCallback;
	};
}
