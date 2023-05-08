#pragma once

// --- GLFW ---
#include <GLFW/glfw3.h>

// --- Standard ---
#include <cassert>

// --- fsgl ---
#include "fsgl/Core/Window.hpp"



namespace fsgl
{
    namespace impl
    {
        void glfw_key_callback(GLFWwindow* glfw_win, int key, int scancode, int action, int mods)
        {
            auto* win = static_cast<fsgl::Window*>(glfwGetWindowUserPointer(glfw_win));
            assert(win);
            win->SIGNAL_KeyEvent.emit(*win, key, scancode, action, mods);
        }

        void glfw_mouseMove_callback(GLFWwindow* glfw_win, double x, double y)
        {
            auto* win = static_cast<fsgl::Window*>(glfwGetWindowUserPointer(glfw_win));
            assert(win);
            win->SIGNAL_MouseMoveEvent.emit(*win, x, y);
        }

        void glfw_mouseButton_event(GLFWwindow* glfw_win, int button, int action, int mods)
        {
            auto* win = static_cast<fsgl::Window*>(glfwGetWindowUserPointer(glfw_win));
            assert(win);
            win->SIGNAL_MouseButtonEvent.emit(*win, button, action, mods);
        }

        void glfw_mouseWheel_callback(GLFWwindow* glfw_win, double x_off, double y_off)
        {
            auto* win = static_cast<fsgl::Window*>(glfwGetWindowUserPointer(glfw_win));
            assert(win);
            win->SIGNAL_MouseWheelEvent.emit(*win, x_off, y_off);
        }

        void glfw_textInput_callback(GLFWwindow* glfw_win, unsigned int key)
        {
            auto* win = static_cast<fsgl::Window*>(glfwGetWindowUserPointer(glfw_win));
            assert(win);
            win->SIGNAL_TextInput.emit(*win, key);
        }

        void glfw_windowClose_callback(GLFWwindow* glfw_win)
        {
            auto* win = static_cast<fsgl::Window*>(glfwGetWindowUserPointer(glfw_win));
            assert(win);
            win->SIGNAL_WindowClosed.emit(*win);
        }

        void glfw_windowSized_callback(GLFWwindow* glfw_win, int width, int height)
        {
            auto* win = static_cast<fsgl::Window*>(glfwGetWindowUserPointer(glfw_win));
            assert(win);
            win->SIGNAL_WindowSized.emit(*win, width, height);
        }
    }
}
