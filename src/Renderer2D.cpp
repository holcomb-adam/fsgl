#include "RLE/Rendering/Renderer2D.hpp"

// --- RLE ---
#include "RLE/Node/Node.hpp"
#include "RLE/Node/Components/Render2D.hpp"
#include "RLE/Rendering/RenderCommands.hpp"
#include "RLE/Rendering/VertexArray.hpp"



void rle::Renderer2D::beginScene()
{

}

void rle::Renderer2D::endScene()
{
    
}

void rle::Renderer2D::draw(const Node& node)
{
    if (node.hasComponent<Render2D>())
        node.getComponent<Render2D>().draw(*this);
}

void rle::Renderer2D::draw(
    const std::shared_ptr<Shader> shader,
    const std::shared_ptr<VertexArray> vao,
    const glm::mat3& transform)
{
    // Prepare shaders
    shader->bind();
    shader->uploadUniform("u_ProjectionMatrix", m_ViewProjection);

    // Bind and draw vertex array
    vao->bind();
    RenderCommands::draw(vao);
}
