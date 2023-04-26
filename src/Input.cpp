// THIS IS ALL TEMP AS THIS USES NON API AGNOSTIC CODE

#include "RLEpch.hpp"
#include "RLE/Core/Input.hpp"

// --- GLFW --- 
#include <GLFW/glfw3.h> // non-agnostic

// --- RLE ---
#include "RLE/Core/Engine.hpp"



bool rle::input::isKeyPressed(const KeyCode code)
{
    auto* win = static_cast<GLFWwindow*>(Engine::get()->getWindow()->nativeHandle());
    auto codei = to_code(code);
    return glfwGetKey(win, codei) == GLFW_PRESS;
}
