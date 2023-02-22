#include "RLEpch.hpp"
#include "impl/API/GLFW/GLFW_Callback.hpp"

// --- GLFW ---
#include <GLFW/glfw3.h>

// --- RLE ---
#include "RLE/Core/KeyCodes.hpp"
#include "RLE/Events/Events.hpp"

// --- RLE impl ---
#include "impl/API/GLFW/GLFW_Window.hpp"



void rle::impl::GLFW_Callback::onWindowClose(GLFWwindow* win)
{
    const auto context = getGLFWWindow(win);
    rle::WindowCloseEvent event;
    context->m_EventCallback(event);
}

void rle::impl::GLFW_Callback::onKeyStateChange(
    GLFWwindow* win,
    const int key,
    const int scancode,
    const int action,
    const int mods)
{
    const auto context = getGLFWWindow(win);
    const auto code = to_key(key);

    switch (action)
    {
    case GLFW_PRESS: // Keyboard key is pressed
        {
            rle::KeyPressEvent event(code, false);
            context->m_EventCallback(event);
            break;
        }

    case GLFW_RELEASE: // Keyboard key is released                  
        {
            rle::KeyReleaseEvent event(code);
            context->m_EventCallback(event);
            break;
        }

    case GLFW_REPEAT: // Keyboard key is being repeated
        {
            rle::KeyPressEvent event(code, true);
            context->m_EventCallback(event);
            break;
        }
    }
}

void rle::impl::GLFW_Callback::onTextInput(GLFWwindow* win, const std::uint32_t code)
{
    const auto context = getGLFWWindow(win);
    rle::TextInputEvent event(code);
    context->m_EventCallback(event);
}

void rle::impl::GLFW_Callback::onMouseMove(
    GLFWwindow* win,
    const double x,
    const double y)
{
    const auto context = getGLFWWindow(win);
    rle::MouseMoveEvent event(x, y);
    context->m_EventCallback(event);
}

void rle::impl::GLFW_Callback::onMouseButtonStateChange(
    GLFWwindow* win,
    const int button,
    const int action,
    const int mods)
{
    const auto context = getGLFWWindow(win);

    switch (action)
    {
    case GLFW_PRESS:
        {
            rle::MousePressEvent event(button, mods);
            context->m_EventCallback(event);
            break;
        }

    case GLFW_RELEASE:
        {
            rle::MouseReleaseEvent event(button, mods);
            context->m_EventCallback(event);
            break;
        }
    }
}

void rle::impl::GLFW_Callback::onScrollWheelUpdate(
    GLFWwindow* win,
    const double x_off,
    const double y_off)
{
    const auto context = getGLFWWindow(win);
    rle::MouseScrollEvent event(x_off, y_off);
    context->m_EventCallback(event);
}

void rle::impl::GLFW_Callback::onWindowSizeUpdate(GLFWwindow* win, const int x, const int y)
{
    auto context = getGLFWWindow(win);
    rle::WindowSizeEvent event(x, y);
    context->m_EventCallback(event);

    // adjust window sizes
    context->m_Width = x;
    context->m_Height = y;
}

rle::impl::GLFW_Window* rle::impl::GLFW_Callback::getGLFWWindow(GLFWwindow* win)
{
    return static_cast<GLFW_Window*>(glfwGetWindowUserPointer(win));
}
