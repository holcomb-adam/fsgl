#include "RLE/Node/Aspects/Transform2D.hpp"



rle::Transform2D::Transform2D() :
    m_Matrix(glm::mat3())
{
    
}

const glm::mat3& rle::Transform2D::getTransform() const
{
    return m_Matrix;
}