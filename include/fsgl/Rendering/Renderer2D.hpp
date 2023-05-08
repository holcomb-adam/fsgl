#pragma once

// --- Standard ---
#include <memory>

// --- fsgl ---
#include "fsgl/Rendering/2D/View.hpp"



namespace fsgl
{
    // - Forward Declarations -
    class GraphicsHandle;
    class Node;
    class ShaderHandle;
    class VertexArray;



    /// @brief Dedicated 2D renderer for 2D nodes.
    class Renderer2D
    {
    public:
        ////////////////////////////////////////////////////////////////////////////////
        // - CONSTRUCTORS / DESTRUCTORS ------------------------------------------------

        /// @brief Default constructor
        Renderer2D() = default;

        /// @brief Default destructor
        ~Renderer2D() = default;



        /// @brief Begin a scene for rendering
        void beginScene(const std::shared_ptr<GraphicsHandle> handle,
                        const View& view,
                        const glm::ivec2& viewport_size,
                        const glm::ivec2& viewport_pos = { 0, 0 });

        /// @brief End the scene rendering
        void endScene();

        /// @brief 
        /// @param node 
        void draw(const Node& node);

        /// @brief 
        /// @param shader 
        /// @param vao 
        /// @param transform 
        void draw(const std::shared_ptr<ShaderHandle> shader,
                  const std::shared_ptr<VertexArray> vao,
                  const glm::mat3& transform);



    private:
        std::shared_ptr<GraphicsHandle> m_GraphicsHandler;

        glm::mat4 m_Projection;
        glm::mat4 m_View;
    };
}
