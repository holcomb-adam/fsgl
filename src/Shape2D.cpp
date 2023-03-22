#include "RLEpch.hpp"
#include "RLE/Node/Components/Shape2D.hpp"

// --- RLE ---
#include "RLE/Rendering/VertexBuffer.hpp"
#include "RLE/Rendering/IndexBuffer.hpp"



const std::shared_ptr<rle::VertexArray> rle::Shape2D::getVertexArray() const
{
    return m_VAO;
}

void rle::Shape2D::setGeometry(std::shared_ptr<Geometry> geometry)
{
    m_Geometry = geometry;
    
    // Setup Vertex Array
    m_VAO = factory<VertexArray>::create();
    m_VAO->bind();

    // Update vertex contents (this is not optimal rn)
    m_VBO = factory<VertexBuffer>::create(
        geometry->data(),
        2 * sizeof(float) * geometry->count());
    m_VBO->bind();
    m_VAO->addVertexBuffer(m_VBO);

    // Update index buffer
    const auto& indices = geometry->indices();
    m_IBO = factory<IndexBuffer>::create(indices.data(), indices.size());
    m_IBO->bind();
    m_VAO->setIndexBuffer(m_IBO);
}
