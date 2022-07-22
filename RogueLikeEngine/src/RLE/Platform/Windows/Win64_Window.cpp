#include "RLEpch.h"
#include "Win64_Window.h"

// External Library includes
#include <glad/glad.h>
#include <GLFW/glfw3.h>

// Standard Library includes
#include <cassert> // TODO: create custom assertion

// RLE Library includes
#include "RLE/Debug/Log.h"
#include "RLE/Events/Events.h"





namespace rle
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
        rle::Win64_Window* getWin64GLFW(GLFWwindow* win)
        {
            return static_cast<rle::Win64_Window*>(glfwGetWindowUserPointer(win));
        }
    }





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

        switch (action)
        {
        case GLFW_PRESS: // Keyboard key is pressed
            {
                rle::KeyPressEvent event(key, false);
                win64->m_EventCallback(event);
                break;
            }

        case GLFW_RELEASE: // Keyboard key is released
            {
                rle::KeyReleaseEvent event(key);
                win64->m_EventCallback(event);
                break;
            }

        case GLFW_REPEAT: // Keyboard key is being repeated
            {
                rle::KeyPressEvent event(key, true);
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
        const auto win64 = getWin64GLFW(win);
        rle::WindowSizeEvent event(x, y);
        win64->m_EventCallback(event);
    }
}





rle::Win64_Window::Win64_Window(const Properties& props) :
    m_Title(props.title),
    m_Width(props.w),
    m_Height(props.h),
    m_VSync(props.vsync)
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
    glfwMakeContextCurrent(m_Window);

    // Enable GLAD
    const int glad_success = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
    assert(glad_success);

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

rle::Win64_Window::~Win64_Window()
{
    glfwDestroyWindow(m_Window);
}

void rle::Win64_Window::update()
{
    glfwPollEvents();
    glfwSwapBuffers(m_Window);
}

std::uint32_t rle::Win64_Window::width() const
{
    return m_Width;
}

std::uint32_t rle::Win64_Window::height() const
{
    return m_Height;
}

void rle::Win64_Window::setEventCallback(const EventCallback& callback)
{
    m_EventCallback = callback;
}

void rle::Win64_Window::setVSync(const bool enabled)
{
    // enable vsync in openGL
    if (enabled)
        glfwSwapInterval(1);
    else
        glfwSwapInterval(0);

    // update the window properties
    m_VSync = enabled;
}

bool rle::Win64_Window::isVSync() const
{
    return m_VSync;
}

void* rle::Win64_Window::nativeHandle() const
{
    return m_Window;
}
