#include "RLEpch.hpp"
#include "impl/API/GLFW/GLFW_Window.hpp"

// --- RLE ---
#include "RLE/Core/KeyCodes.hpp"
#include "RLE/Debug/Log.hpp"

// --- RLE impl ---
#include "impl/API/GLFW/GLFW_Callbacks.hpp"
#include "impl/Platform/Windows/Win64_Window.hpp"
#include "impl/Platform/Linux/Linux_Window.hpp"



namespace
{
    // --- GLFW House Keeping ----

    // Number of windows currently open via GLFW
    static std::uint8_t GLFW_WindowCount = 0;

    // GLFW Error Callback
    // - Performs logging for glfw errors that might comeback
    void GLFW_errCallback(const int err, const char* msg)
    {
        RLE_CORE_ERROR("GLFW error ({0}): {1}", err, msg);
    }
}



rle::impl::GLFW_Window::GLFW_Window(const Properties &props) : 
    m_Title(props.title),
    m_Width(props.w),
    m_Height(props.h),
    m_VSync(props.vsync)
{
    init(props);
}

rle::impl::GLFW_Window::~GLFW_Window()
{
    glfwDestroyWindow(m_Window);
}

void rle::impl::GLFW_Window::update()
{
    glfwSwapBuffers(m_Window);
    glfwPollEvents();
}

std::uint32_t rle::impl::GLFW_Window::width() const
{
    return m_Width;
}

std::uint32_t rle::impl::GLFW_Window::height() const
{
    return m_Height;
}

void rle::impl::GLFW_Window::setVSync(const bool enabled)
{
    // Enable vsync in the rendering context
    if (enabled)
        glfwSwapInterval(1);
    else
        glfwSwapInterval(0);

    // Update the window properties
    m_VSync = enabled;
}

bool rle::impl::GLFW_Window::isVSync() const
{
    return m_VSync;
}

void* rle::impl::GLFW_Window::nativeHandle() const
{
    return m_Window;
}

void rle::impl::GLFW_Window::init(const Properties &props)
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
    glfwSetKeyCallback(m_Window, ::rle::impl::glfw_key_callback);
    glfwSetCursorPosCallback(m_Window, ::rle::impl::glfw_mouseMove_callback);
    glfwSetMouseButtonCallback(m_Window, ::rle::impl::glfw_mouseButton_event);
    glfwSetScrollCallback(m_Window, ::rle::impl::glfw_mouseWheel_callback);
    glfwSetCharCallback(m_Window, ::rle::impl::glfw_textInput_callback);
    glfwSetWindowCloseCallback(m_Window, ::rle::impl::glfw_windowClose_callback);
    glfwSetWindowSizeCallback(m_Window, ::rle::impl::glfw_windowSized_callback);
}



// Preprocessor checks to create os specific window instances
#   if defined(RLE_OS_WIN64)
#       define RLE_IMPL_OS_WINDOW_T ::rle::impl::Win64_Window
#   elif defined(RLE_OS_LINUX)
#       define RLE_IMPL_OS_WINDOW_T ::rle::impl::Linux_Window
#   else
#       error Our GLFW window implentations currently only support Windows and Linux!
#   endif



std::unique_ptr<rle::impl::GLFW_Window> rle::factory<rle::impl::GLFW_Window>::create(const Window::Properties& props)
{
    return std::unique_ptr<impl::GLFW_Window>(new RLE_IMPL_OS_WINDOW_T(props));
}
