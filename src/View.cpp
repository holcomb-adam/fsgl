#include "RLE/Rendering/2D/View.hpp"

// --- GLM ---
#include <glm/gtc/matrix_transform.hpp>



rle::View::View(const float w,
                const float h,
                const glm::vec2& position,
                const float rotation) : 
    m_Width(w),
    m_Height(h),
    m_Position(position),
    m_Rotation(rotation)
{

}

glm::mat4 rle::View::getProjectionMatrix() const
{
    return glm::ortho(-1.0f, 1.0f, -1.0f, 1.0f, NEAR_CLIP, FAR_CLIP);
}

glm::mat4 rle::View::getViewMatrix() const
{
    return glm::translate(glm::mat4(1.0f), glm::vec3(m_Position, -2.0f));
}

void rle::View::setPosition(const glm::vec2& position)
{
    m_Position = position;
}

void rle::View::setRotation(const float rotation_deg)
{
    m_Rotation = rotation_deg;
}

void rle::View::setSize(const float w, const float h)
{
    m_Width = w;
    m_Height = h;
}

void rle::View::move(const glm::vec2& offset)
{
    m_Position += offset;
}

