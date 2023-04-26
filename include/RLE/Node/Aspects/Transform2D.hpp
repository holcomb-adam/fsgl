#pragma once

// --- GLM ---
#include <glm/gtx/matrix_transform_2d.hpp>

// --- RLE ---
#include "RLE/Node/Aspect.hpp"



namespace rle
{
    class Transform2D : public Aspect
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
