#pragma once

// --- GLM ---
#include <glm/gtx/matrix_transform_2d.hpp>

// --- RLE ---
#include "RLE/Node/Component.hpp"



namespace rle
{
    class Transform2D : public Component
    {
    public:
        ////////////////////////////////////////////////////////////////////////////////
        // - CONSTRUCTORS / DESTRUCTORS ------------------------------------------------

        /// @brief 
        Transform2D();

        ~Transform2D() = default;



        const glm::mat3& getTransform() const;


    private:
        glm::mat3 m_Matrix;
    };
}
