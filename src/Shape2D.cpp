#include "RLEpch.hpp"
#include "RLE/Node/Aspects/Shape2D.hpp"

// --- RLE ---
#include "RLE/Core/Core.hpp"
#include "RLE/Rendering/IndexBuffer.hpp"
#include "RLE/Rendering/VertexBuffer.hpp"
#include "RLE/Rendering/2D/Vertex2D.hpp"



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
    const auto* geometry_data = geometry->data();
    const auto geometry_count = geometry->count();
    std::vector<Vertex2D> vertex_data;
    for (std::size_t i = 0; i < geometry_count; i++)
        vertex_data.push_back(Vertex2D{geometry_data[i], glm::vec4(RLE_BLUE, 1.0f)});
    m_VBO = factory<VertexBuffer>::create(vertex_data.data(), vertex_data.size());
    m_VBO->bind();
    m_VAO->addVertexBuffer(m_VBO);

    // Update index buffer
    const auto& indices = geometry->indices();
    m_IBO = factory<IndexBuffer>::create(indices.data(), indices.size());
    m_IBO->bind();
    m_VAO->setIndexBuffer(m_IBO);
}
