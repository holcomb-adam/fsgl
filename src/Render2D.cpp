#include "RLE/Node/Components/Render2D.hpp"

// --- RLE ---
#include "RLE/Debug/Log.hpp"
#include "RLE/Node/Node.hpp"
#include "RLE/Node/Components/Shape2D.hpp"
#include "RLE/Node/Components/Transform2D.hpp"
#include "RLE/Rendering/Renderer2D.hpp"



namespace
{
    // - 2D Rendering Defaults -
    const std::string vtx = 
R"(

#version 330 core

layout (location = 0) in vec2 i_pos;

uniform mat4 u_ProjectionMatrix;

out vec4 v_color;

void main()
{
    gl_Position = vec4(i_pos, 0.0, 1.0);
    v_color = vec4(abs(i_pos.x), abs(i_pos.y), 1.0, 1.0);
}

)";

    const std::string frg =
R"(

#version 330 core

in vec4 v_color;

out vec4 f_color;

void main()
{
    //f_color = vec4(1.0, 1.0, 1.0, 1.0);
    //f_color = vec4(0.95, 0.10, 0.76, 1.0);
    f_color = v_color;
}

)";

    static const glm::mat3 DEFAULT_TRANSFORM = glm::mat3();
}



rle::Render2D::Render2D() :
    m_Shader(factory<Shader>::create(vtx, frg))
{

}

rle::Render2D::Render2D(const std::string& vertex_src, const std::string& frag_src)
{
    if (!vertex_src.empty() && !frag_src.empty())
        m_Shader = factory<Shader>::create(vtx, frg);
}

void rle::Render2D::setIgnoreComponents(const bool flag)
{
    m_IgnoreComponents = flag;
}

void rle::Render2D::draw(Renderer2D& renderer) const
{
    if (!m_IgnoreComponents)
        drawComponents(renderer);
    if (!m_IgnoreChildren)
        drawChildren(renderer);
}

void rle::Render2D::drawComponents(Renderer2D& renderer) const
{
    // Retrieve rendering data from components
    const auto& node = getNode();

    // Dont bother rendering with no shape to render
    if (!node.hasComponent<Shape2D>())
    {
        RLE_CORE_WARN("Ignoring rendering for node {0}:{1}."
                      "A Shape2D component is needed to renderer components.", 
                       node.UID.UID(), node.getName());
        return;
    }

    const auto vao = node.getComponent<Shape2D>().getVertexArray();
    const glm::mat3& transform = node.hasComponent<Transform2D>() ? 
        node.getComponent<Transform2D>().getTransform() : DEFAULT_TRANSFORM;
    renderer.draw(m_Shader, vao, transform);
}

void rle::Render2D::drawChildren(Renderer2D& renderer) const
{
    for (const auto* child : getNode().getChildren())
        if (child)
            renderer.draw(*child);
}
