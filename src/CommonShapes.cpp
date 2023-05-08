#include "fsgl_pch.hpp"
#include "fsgl/Resources/CommonShapes.hpp"



std::shared_ptr<fsgl::Geometry> fsgl::res::makeRect(const float w, const float h)
{
    const static std::vector<glm::vec2> rectangle_poly_info =
    {
        // Triangle A
        { -0.5f,  0.5f }, // TL
        {  0.5f,  0.5f }, // TR
        { -0.5f, -0.5f }, // BL

        // Triangle B
        {  0.5f,  0.5f }, // TR
        {  0.5f, -0.5f }, // BR
        { -0.5f, -0.5f }  // BL
    };

    Geometry* shape = new Geometry(rectangle_poly_info);
    return std::shared_ptr<Geometry>(shape);
}
