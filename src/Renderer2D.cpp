#include "RLE/Rendering/Renderer2D.hpp"

// --- RLE ---
#include "RLE/Node/Node.hpp"
#include "RLE/Node/Aspects/Render2D.hpp"
#include "RLE/Rendering/GraphicsHandle.hpp"
#include "RLE/Rendering/VertexArray.hpp"



void rle::Renderer2D::beginScene(std::shared_ptr<GraphicsHandle> handle,
                                 const View& view,
                                 const glm::ivec2& viewport_size,
                                 const glm::ivec2& viewport_pos)
{
    m_GraphicsHandler = handle;
    m_Projection = view.getProjectionMatrix();
    m_View = view.getViewMatrix();

    // Setup view for scene
    m_GraphicsHandler->bind();
    m_GraphicsHandler->clear();
    m_GraphicsHandler->viewport(viewport_pos.x, viewport_pos.y, viewport_size.x, viewport_size.y);
}

void rle::Renderer2D::endScene()
{
    m_GraphicsHandler->unbind();
}

void rle::Renderer2D::draw(const Node& node)
{
    if (node.hasComponent<Render2D>())
        node.getComponent<Render2D>().draw(*this);
}

void rle::Renderer2D::draw(const std::shared_ptr<ShaderHandle> shader,
                           const std::shared_ptr<VertexArray> vao,
                           const glm::mat3& transform)
{
    // Prepare shaders
    shader->bind();
    shader->uploadUniform("u_RLE_cameraProjection", m_Projection);
    shader->uploadUniform("u_RLE_cameraView", m_View);

    // Bind and draw vertex array
    vao->bind();
    m_GraphicsHandler->draw(vao);
}
