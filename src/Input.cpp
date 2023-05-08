// THIS IS ALL TEMP AS THIS USES NON API AGNOSTIC CODE

#include "fsgl_pch.hpp"
#include "fsgl/Core/Input.hpp"

// --- GLFW --- 
#include <GLFW/glfw3.h> // non-agnostic

// --- fsgl ---
#include "fsgl/Core/Engine.hpp"



bool fsgl::input::isKeyPressed(const KeyCode code)
{
    auto* win = static_cast<GLFWwindow*>(Engine::get()->getWindow()->nativeHandle());
    auto codei = to_code(code);
    return glfwGetKey(win, codei) == GLFW_PRESS;
}
