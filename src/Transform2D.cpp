#include "fsgl/Node/Aspects/Transform2D.hpp"



fsgl::Transform2D::Transform2D() :
    m_Matrix(glm::mat3())
{
    
}

const glm::mat3& fsgl::Transform2D::getTransform() const
{
    return m_Matrix;
}