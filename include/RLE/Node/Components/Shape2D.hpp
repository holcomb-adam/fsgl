#pragma once

// --- RLE ---
#include "RLE/Node/Component.hpp"
#include "RLE/Rendering/VertexArray.hpp"
#include "RLE/Resources/Geometry.hpp"



namespace rle
{
    class Shape2D : public Component
    {
    public:
        Shape2D() = default;

        ~Shape2D() = default;



        const std::shared_ptr<VertexArray> getVertexArray() const;

        void setGeometry(std::shared_ptr<Geometry> geometry);



    private:
        // --- Helpers ---

        void impl_updateVertexArray();

    private:
        std::shared_ptr<Geometry> m_Geometry;

        std::shared_ptr<VertexArray> m_VAO;
        std::shared_ptr<VertexBuffer> m_VBO;
        std::shared_ptr<IndexBuffer> m_IBO;
    };
}
