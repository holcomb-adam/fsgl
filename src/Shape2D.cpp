#include "fsgl_pch.hpp"
#include "fsgl/Node/Aspects/Shape2D.hpp"

// --- fsgl ---
#include "fsgl/Core/Core.hpp"
#include "fsgl/Rendering/IndexBuffer.hpp"
#include "fsgl/Rendering/VertexBuffer.hpp"
#include "fsgl/Rendering/2D/Vertex2D.hpp"



const std::shared_ptr<fsgl::VertexArray> fsgl::Shape2D::getVertexArray() const
{
    return m_VAO;
}

void fsgl::Shape2D::setGeometry(std::shared_ptr<Geometry> geometry)
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
        vertex_data.push_back(Vertex2D{geometry_data[i], glm::vec4(FSGL_BLUE, 1.0f)});
    m_VBO = factory<VertexBuffer>::create(vertex_data.data(), vertex_data.size());
    m_VBO->bind();
    m_VAO->addVertexBuffer(m_VBO);

    // Update index buffer
    const auto& indices = geometry->indices();
    m_IBO = factory<IndexBuffer>::create(indices.data(), indices.size());
    m_IBO->bind();
    m_VAO->setIndexBuffer(m_IBO);
}
