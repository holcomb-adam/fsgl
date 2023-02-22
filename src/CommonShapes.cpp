#include "RLEpch.hpp"
#include "RLE/Resources/CommonShapes.hpp"



std::shared_ptr<rle::Shape> rle::res::makeRect(const float w, const float h)
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

    Shape* shape = new Shape(rectangle_poly_info);
    return std::shared_ptr<Shape>(shape);
}
