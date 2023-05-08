#include "fsgl/Rendering/2D/View.hpp"

// --- GLM ---
#include <glm/gtc/matrix_transform.hpp>



fsgl::View::View(const float w,
                const float h,
                const glm::vec2& position,
                const float rotation) : 
    m_Width(w),
    m_Height(h),
    m_Position(position),
    m_Rotation(rotation)
{

}

glm::mat4 fsgl::View::getProjectionMatrix() const
{
    return glm::ortho(-1.0f, 1.0f, -1.0f, 1.0f, NEAR_CLIP, FAR_CLIP);
}

glm::mat4 fsgl::View::getViewMatrix() const
{
    return glm::translate(glm::mat4(1.0f), glm::vec3(m_Position, -2.0f));
}

void fsgl::View::setPosition(const glm::vec2& position)
{
    m_Position = position;
}

void fsgl::View::setRotation(const float rotation_deg)
{
    m_Rotation = rotation_deg;
}

void fsgl::View::setSize(const float w, const float h)
{
    m_Width = w;
    m_Height = h;
}

void fsgl::View::move(const glm::vec2& offset)
{
    m_Position += offset;
}

