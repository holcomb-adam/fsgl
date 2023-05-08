#pragma once

// --- fsgl ---
#include "fsgl/Core/Window.hpp"



// GLFW Forward Declarations
struct GLFWwindow;



namespace fsgl
{
    namespace impl
    {
        /// @brief Interface for creating an OS specific window class
        class GLFW_Window : public Window
        {
            // --- Friend Classes ---
            friend class GLFW_Callback;



        public:
            ////////////////////////////////////////////////////////////////////////////////
            // - CONSTRUCTORS / DESTRUCTORS ------------------------------------------------

            // Constructor
            // - Initializes GLFW 3
            // - 'props': Window properties defining the window
            //   (i.e. Title, Width, Height, etc.)
            GLFW_Window(const Properties& props);

            // [virtual]
            // Destructor
            // - Uninitializes GLFW 3 if no windows remain
            virtual ~GLFW_Window();



            ////////////////////////////////////////////////////////////////////////////////
            // - OVERRIDES -----------------------------------------------------------------

            // Inherited via Window
            virtual void update() override;
            virtual std::uint32_t width() const override;
            virtual std::uint32_t height() const override;
            virtual void setVSync(const bool enabled) override;
            virtual bool isVSync() const override;
            virtual void* nativeHandle() const override;



        private:
            ////////////////////////////////////////////////////////////////////////////////
            // - HELPER FUNCTIONS ----------------------------------------------------------
            
            // Initialize data
            void init(const Properties& props);



        private:
            GLFWwindow* m_Window = nullptr;

            std::string m_Title;
            std::uint32_t m_Width = 0;
            std::uint32_t m_Height = 0;

            bool m_VSync = false;
        };
    }



    template<>
    struct factory<impl::GLFW_Window>
    {
        static std::unique_ptr<impl::GLFW_Window> create(const Window::Properties& props);
    };
}

