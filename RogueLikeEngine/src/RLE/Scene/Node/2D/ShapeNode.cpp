#include "RLEpch.hpp"
#include "ShapeNode.hpp"

// --- RLE ---
#include "RLE/Core/Core.hpp"
#include "RLE/Rendering/IndexBuffer.hpp"
#include "RLE/Rendering/Renderer.hpp"
#include "RLE/Rendering/VertexBuffer.hpp"



// Temporary basic shaders for RLE
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



rle::ShapeNode::ShapeNode() :
    Node(nullptr)
{

}

void rle::ShapeNode::setShape(const std::shared_ptr<Shape>& shape)
{
    // Set the shape resource
    m_Shape = shape;
    
    // Setup Vertex Array
    m_VertexArray = factory<VertexArray>::create();
    m_VertexArray->bind();

    // Update Rendering data
    m_VertexBuffer = factory<VertexBuffer>::create(shape->data(), 2 * sizeof(float) * shape->count());
    m_VertexBuffer->bind();
    m_VertexArray->addVertexBuffer(m_VertexBuffer);

    // Update Index Buffer
    const auto& indices = shape->indices();
    m_IndexBuffer = factory<IndexBuffer>::create(indices.data(), indices.size());
    m_IndexBuffer->bind();
    m_VertexArray->setIndexBuffer(m_IndexBuffer);

    // Setup Shader
    m_Shader = factory<Shader>::create(vtx, frg);
    m_Shader->bind();
}

void rle::ShapeNode::onRender(Renderer& target) const
{
    target.submit(m_Shader, m_VertexArray);
}
