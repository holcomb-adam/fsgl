#pragma once

// --- GLM ---
#include <glm/vec4.hpp>

// --- Standard ---
#include <memory>




namespace fsgl
{
    // FSGL Forward Declarations
    class FrameBuffer;
    class GraphicsAPI;
    class VertexArray;



    /// @brief 
    class GraphicsHandle
    {
    public:
        /// @brief 
        /// @return 
        static std::shared_ptr<GraphicsHandle> make();



    public:
        ////////////////////////////////////////////////////////////////////////////////
        // - CONSTRUCTORS / DESTRUCTORS ------------------------------------------------

        /// @brief Constructor
        GraphicsHandle();

        /// @brief Destructor
        ~GraphicsHandle() = default;



        ////////////////////////////////////////////////////////////////////////////////
        // - SETTERS -------------------------------------------------------------------

        /// @brief Set the color to clear the frame to
        /// @param color
        void setClearColor(const glm::vec4& color);

        /// @brief Set the frame buffer. GraphicsHandle will default to the currently
        ///        active graphics API's frame buffer when drawing.
        /// @param fbo_ptr
        void setFrameBuffer(std::weak_ptr<fsgl::FrameBuffer> fbo_ptr);



        ////////////////////////////////////////////////////////////////////////////////
        // - OPERATIONS ----------------------------------------------------------------

        // Bind buffers
        void bind() const;

        // Unbind buffers
        void unbind() const;

        // Clear all drawing present on the frame buffer
        void clear();

        // Specify the rendering viewport
        void viewport(std::int32_t x, std::int32_t y, std::int32_t w, std::int32_t h) const;

        // Draw a vertex array object
        void draw(const std::shared_ptr<VertexArray>& vao) const;



    private:
        std::weak_ptr<FrameBuffer> m_FBO;
        glm::vec4 m_ClearColor;
    };
}
