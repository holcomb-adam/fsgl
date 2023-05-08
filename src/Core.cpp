#include "fsgl_pch.hpp"
#include "fsgl/Core/Core.hpp"

// --- fsgl ---
#include "fsgl/Core/Window.hpp"
#include "fsgl/Debug/Log.hpp"
#include "fsgl/Node/Node.hpp"



namespace
{
    static bool s_CoreInitialized = false;
}



bool fsgl::core::isCoreInitialized()
{
    return s_CoreInitialized;
}

bool fsgl::core::initialize()
{
    log::init();
    Node::initializeRootNode();

    s_CoreInitialized = true;
    return s_CoreInitialized;
}
