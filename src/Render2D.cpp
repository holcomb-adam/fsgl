#include "fsgl/Node/Aspects/Render2D.hpp"

// --- fsgl ---
#include "fsgl/Debug/Log.hpp"
#include "fsgl/Node/Node.hpp"
#include "fsgl/Node/Aspects/Shape2D.hpp"
#include "fsgl/Node/Aspects/Transform2D.hpp"
#include "fsgl/Rendering/Renderer2D.hpp"



namespace
{
    // - 2D Rendering Defaults -
    const std::string vtx = 
R"(

#version 330 core

layout (location = 0) in vec2 pos_i;
layout (location = 1) in vec4 color_i;

uniform mat4 u_FSGL_cameraProjection;
uniform mat4 u_FSGL_cameraView;

out vec4 color_v;

void main()
{
    gl_Position = u_FSGL_cameraProjection * u_FSGL_cameraView * vec4(pos_i, 1.0, 1.0);
    color_v = color_i;
}

)";

    const std::string frg =
R"(

#version 330 core

in vec4 color_v;

out vec4 f_color;

void main()
{
    f_color = color_v;
}

)";

    static const glm::mat3 DEFAULT_TRANSFORM = glm::mat3();
}



fsgl::Render2D::Render2D() :
    m_Shader(ShaderHandle::make(vtx, frg))
{

}

fsgl::Render2D::Render2D(const std::string& vertex_src, const std::string& frag_src)
{
    if (!vertex_src.empty() && !frag_src.empty())
        m_Shader = ShaderHandle::make(vtx, frg);
}

void fsgl::Render2D::setIgnoreComponents(const bool flag)
{
    m_IgnoreComponents = flag;
}

void fsgl::Render2D::draw(Renderer2D& renderer) const
{
    if (!m_IgnoreComponents)
        drawComponents(renderer);
    if (!m_IgnoreChildren)
        drawChildren(renderer);
}

void fsgl::Render2D::drawComponents(Renderer2D& renderer) const
{
    // Retrieve rendering data from components
    const auto& node = getNode();

    // Dont bother rendering with no shape to render
    if (!node.hasComponent<Shape2D>())
    {
        FSGL_CORE_WARN("Ignoring rendering for node {0}:{1}."
                      "A Shape2D component is needed to renderer components.", 
                       node.UID.raw(), node.getName());
        return;
    }

    const auto vao = node.getComponent<Shape2D>().getVertexArray();
    const glm::mat3& transform = node.hasComponent<Transform2D>() ? 
        node.getComponent<Transform2D>().getTransform() : DEFAULT_TRANSFORM;
    renderer.draw(m_Shader, vao, transform);
}

void fsgl::Render2D::drawChildren(Renderer2D& renderer) const
{
    for (const auto& child : getNode().getChildren())
        if (child)
            renderer.draw(*child);
}
