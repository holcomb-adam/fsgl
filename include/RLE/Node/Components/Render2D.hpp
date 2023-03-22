#pragma once

// --- RLE ---
#include "RLE/Node/Component.hpp"
#include "RLE/Rendering/Shader.hpp"



namespace rle
{
    // - Forward Declarations -
    class Renderer2D;



    /// @brief Component for rendering other 2D Node components.
    /// @note This will not render any 3D components.
    /// @note Requires a Shape2D component for rendering.
    class Render2D : public Component
    {
    public:
        ////////////////////////////////////////////////////////////////////////////////
        // - CONSTRUCTORS / DESTRUCTORS ------------------------------------------------

        /// @brief Default constructor
        Render2D();



        /// @brief Pass shader sources to the render component to compile when creating.
        /// @param vertex_src 
        /// @param frag_src 
        /// @note Passing any empty string will not initialize the shader
        Render2D(const std::string& vertex_src, const std::string& frag_src);

        /// @brief Default destructor
        ~Render2D() = default;



        /// @brief 
        /// @param flag 
        void setIgnoreComponents(const bool flag);



        /// @brief Draw components and children recursively
        /// @param renderer Renderer performing the drawing.
        void draw(Renderer2D& renderer) const;

        void drawComponents(Renderer2D& renderer) const;

        void drawChildren(Renderer2D& renderer) const;



    private:
        bool m_IgnoreComponents = false;
        bool m_IgnoreChildren = false;

        std::shared_ptr<Shader> m_Shader;
        glm::vec4 m_Color = { 0.0f, 0.0f, 0.0f, 0.0f };
    };
}
