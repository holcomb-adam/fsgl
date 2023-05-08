#pragma once

// --- Standard ---
#include <functional>

// --- fsgl ---
#include "Core.hpp"
#include "Factory.hpp"
#include "fsgl/Events/Signal.hpp"
#include "fsgl/Rendering/GraphicsAPI.hpp"



namespace fsgl
{
    // This class represents an abstract "Window"
    // - Interface for implementing an OS specific window (i.e. Windows, MacOS, Linux, etc.)
    class Window
    {
    public:
        ////////////////////////////////////////////////////////////////////////////////
        // - STATIC MEMBERS ------------------------------------------------------------

        /// @brief 
        using KeyEventSignal_t = Signal<Window, int, int, int, int>;

        /// @brief 
        using MouseMoveEventSignal_t = Signal<Window, double, double>;

        /// @brief 
        using MouseButtonEventSignal_t = Signal<Window, int, int, int>;

        /// @brief 
        using MouseWheelEvent_t = Signal<Window, double, double>;

        /// @brief 
        using TextInputSignal_t = Signal<Window, std::uint32_t>;
        
        /// @brief 
        using WindowClosedSignal_t = Signal<Window>;

        /// @brief 
        using WindowSizedSignal_t = Signal<Window, int, int>;



        /// @brief Simple POD structure to define the properties of the window. This
        ///        used for 
        struct Properties final
        {
            std::string title = ""; // Title displayed at the window
            std::uint32_t w = 800; // Width of window in pixels
            std::uint32_t h = 600; // Height of window in pixels

            GraphicsAPI::API api = GraphicsAPI::API::OpenGL; // GraphicsAPI

            bool vsync = false; // Enable vsync: true = on, false = off
        };



        ////////////////////////////////////////////////////////////////////////////////
        // - PUBLIC DATA ---------------------------------------------------------------

        /// @brief 
        KeyEventSignal_t SIGNAL_KeyEvent;
        MouseMoveEventSignal_t SIGNAL_MouseMoveEvent;
        MouseButtonEventSignal_t SIGNAL_MouseButtonEvent;
        MouseWheelEvent_t SIGNAL_MouseWheelEvent;
        TextInputSignal_t SIGNAL_TextInput;
        WindowClosedSignal_t SIGNAL_WindowClosed;
        WindowSizedSignal_t SIGNAL_WindowSized;



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

        // Set VSync flag
        virtual void setVSync(const bool enabled) = 0;

        // Get VSync flag
        virtual bool isVSync() const = 0;

        // Get the native handle to the window
        virtual void* nativeHandle() const = 0;
    };





    ////////////////////////////////////////////////////////////////////////////////
    // - FACTORY METHODS -----------------------------------------------------------

    template<>
    struct factory<Window>
    {
        // Create a window instance for the compiled platform
        // - 'props': A struct of properties to customize the window
        static std::unique_ptr<Window> create(const Window::Properties& props = Window::Properties{});
    };
}
