#pragma once



// - Forward Declarations -
struct GLFWwindow;



namespace rle
{
    namespace impl
    {
        // - Forward Declarations -
        class GLFW_Window;



        class GLFW_Callback final
        {
        public:
			////////////////////////////////////////////////////////////////////////////////
			// - CONSTRUCTORS / DESTRUCTORS ------------------------------------------------

            // [private]
            // Constructors
            GLFW_Callback() = delete;
            GLFW_Callback(const GLFW_Callback&) = delete;
            GLFW_Callback(GLFW_Callback&&) = delete;

            // [Default]
            // Destructor
            ~GLFW_Callback() = default;



			////////////////////////////////////////////////////////////////////////////////
			// - HELPER FUNCTIONS ----------------------------------------------------------
            
            // Window is closed through the window close button
            static void onWindowClose(GLFWwindow* win);

            // Keyboard key state is changed
            static void onKeyStateChange(
                GLFWwindow* win,
                const int key,
                const int scancode,
                const int action,
                const int mods);

            // Keyboard key presses when text input is enabled
            static void onTextInput(GLFWwindow* win, const std::uint32_t code);

            // Mouse cursor move over window
            static void onMouseMove(
                GLFWwindow* win,
                const double x,
                const double y);
            
            // Mouse button state change
            static void onMouseButtonStateChange(
                GLFWwindow* win,
                const int button,
                const int action,
                const int mods);

            // Scroll wheel update
            static void onScrollWheelUpdate(
                GLFWwindow* win,
                const double x_off,
                const double y_off);

            // Window size update
            static void onWindowSizeUpdate(GLFWwindow* win, const int x, const int y);



        private:
			////////////////////////////////////////////////////////////////////////////////
			// - HELPER FUNCTIONS ----------------------------------------------------------

            // Retrieve the user data for the window
            static GLFW_Window* getGLFWWindow(GLFWwindow* win);
        };
    }
}
