#include "RLEpch.h"
#include "Win64_Window.hpp"

// External Library includes
#include <GLFW/glfw3.h>

// Standard Library includes
#include <cassert> // TODO: create custom assertion

// RLE Library includes
#include "RLE/Core/KeyCodes.h"
#include "RLE/Debug/Log.h"
#include "RLE/Events/Events.h"





namespace rle
{
    namespace impl
    {
        namespace
        {
            // TODO: This value should be global across all windows
            // Number of windows currently open via GLFW
            static std::uint8_t GLFW_WindowCount = 0;



            // GLFW Error Callback
            // - Performs logging for glfw errors that might comeback
            void GLFW_errCallback(const int err, const char* msg)
            {
                RLE_CORE_ERROR("GLFW error ({0}): {1}", err, msg);
            }



            // Retrieve the 'rle::Win64_Window' instance from glfw
            Win64_Window* getWin64GLFW(GLFWwindow* win)
            {
                return static_cast<Win64_Window*>(glfwGetWindowUserPointer(win));
            }
        }





        // TODO: These callbacks should be added to a struct and made static for easy 
        // friend access

        ////////////////////////////////////////////////////////////////////////////////
        // - CALLBACKS -----------------------------------------------------------------

        void closeCallback(GLFWwindow* win)
        {
            const auto win64 = getWin64GLFW(win);
            rle::WindowCloseEvent event;
            win64->m_EventCallback(event);
        }
    
        void keyCallback(GLFWwindow* win, const int key, const int scancode, const int action, const int mods)
        {
            const auto win64 = getWin64GLFW(win);
            const auto code = to_key(key);

            switch (action)
            {
            case GLFW_PRESS: // Keyboard key is pressed
                {
                    rle::KeyPressEvent event(code, false);
                    win64->m_EventCallback(event);
                    break;
                }

            case GLFW_RELEASE: // Keyboard key is released                  
                {
                    rle::KeyReleaseEvent event(code);
                    win64->m_EventCallback(event);
                    break;
                }

            case GLFW_REPEAT: // Keyboard key is being repeated
                {
                    rle::KeyPressEvent event(code, true);
                    win64->m_EventCallback(event);
                    break;
                }
            }
        }

        void textCallback(GLFWwindow* win, const unsigned int code)
        {
            const auto win64 = getWin64GLFW(win);
            rle::TextInputEvent event(code);
            win64->m_EventCallback(event);
        }

        void mouseMoveCallback(GLFWwindow* win, const double x, const double y)
        {
            const auto win64 = getWin64GLFW(win);
            rle::MouseMoveEvent event(x, y);
            win64->m_EventCallback(event);
        }

        void mouseButtonCallback(GLFWwindow* win, const int button, const int action, const int mods)
        {
            const auto win64 = getWin64GLFW(win);

            switch (action)
            {
            case GLFW_PRESS:
                {
                    rle::MousePressEvent event(button, mods);
                    win64->m_EventCallback(event);
                    break;
                }

            case GLFW_RELEASE:
                {
                    rle::MouseReleaseEvent event(button, mods);
                    win64->m_EventCallback(event);
                    break;
                }
            }
        }

        void scrollCallback(GLFWwindow* win, const double xoff, const double yoff)
        {
            const auto win64 = getWin64GLFW(win);
            rle::MouseScrollEvent event(xoff, yoff);
            win64->m_EventCallback(event);
        }

        void sizeCallback(GLFWwindow* win, const int x, const int y)
        {
            auto win64 = getWin64GLFW(win);
            rle::WindowSizeEvent event(x, y);
            win64->m_EventCallback(event);

            // adjust window sizes
            win64->m_Width = x;
            win64->m_Height = y;
        }
    }
}





rle::impl::Win64_Window::Win64_Window(const Properties& props) :
    m_Title(props.title),
    m_Width(props.w),
    m_Height(props.h),
    m_VSync(props.vsync)
{
    init(props);
}

rle::impl::Win64_Window::~Win64_Window()
{
    glfwDestroyWindow(m_Window);
}

void rle::impl::Win64_Window::update()
{
    glfwSwapBuffers(m_Window);
    glfwPollEvents();
}

std::uint32_t rle::impl::Win64_Window::width() const
{
    return m_Width;
}

std::uint32_t rle::impl::Win64_Window::height() const
{
    return m_Height;
}

void rle::impl::Win64_Window::setEventCallback(const EventCallback& callback)
{
    m_EventCallback = callback;
}

void rle::impl::Win64_Window::setVSync(const bool enabled)
{
    // Enable vsync in the rendering context
    if (enabled)
        glfwSwapInterval(1);
    else
        glfwSwapInterval(0);

    // Update the window properties
    m_VSync = enabled;
}

bool rle::impl::Win64_Window::isVSync() const
{
    return m_VSync;
}

void* rle::impl::Win64_Window::nativeHandle() const
{
    return m_Window;
}

void rle::impl::Win64_Window::init(const Properties& props)
{
    // Initialize GLFW
    if (GLFW_WindowCount == 0)
    {
        const auto glfw_success = glfwInit();
        assert(glfw_success == GLFW_TRUE);
        glfwSetErrorCallback(&GLFW_errCallback);
    }
    RLE_CORE_INFO("Created window");

    // Create a GLFW window
    m_Window = glfwCreateWindow(
        m_Width,
        m_Height,
        m_Title.c_str(),
        nullptr,
        nullptr);

    // Make the context current
    glfwMakeContextCurrent(m_Window);

    // Allow glfw to see our data
    glfwSetWindowUserPointer(m_Window, this);

    // Set the window callbacks
    glfwSetKeyCallback(m_Window, &keyCallback);
    glfwSetCursorPosCallback(m_Window, &mouseMoveCallback);
    glfwSetMouseButtonCallback(m_Window, &mouseButtonCallback);
    glfwSetScrollCallback(m_Window, &scrollCallback);
    glfwSetCharCallback(m_Window, &textCallback);
    glfwSetWindowCloseCallback(m_Window, &closeCallback);
    glfwSetWindowSizeCallback(m_Window, &sizeCallback);
}
