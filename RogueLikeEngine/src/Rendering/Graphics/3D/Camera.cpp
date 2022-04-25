#include "Camera.h"

#include "Math/Trigonometry.h"
#include "Rendering/EngineRenderer.h"

rle::Matrix44f rle::Camera::getPrespeciveProjMat(const float aspect, const float fov, const float far, const float near)
{
    return Matrix44f
    (
        {
            1.0f / (tan(fov * 0.5f) * aspect), 0.0f, 0.0f, 0.0f,
            0.0f, 0.0f, -1.0f / tan(fov * 0.5f), 0.0f,
            0.0f, far / (far - near), 0.0f, (near * far) / (near - far),
            0.0f, 1.0f, 0.0f, 0.0f
        }
    );
}

float rle::Camera::nearClipping() const
{
    return m_Near;
}

void rle::Camera::setNearClipping(const float near)
{
    m_Near = near;
}

float rle::Camera::farClipping() const
{
    return m_Far;
}

void rle::Camera::setFarClipping(const float far)
{
    m_Far = far;
}

float rle::Camera::fov() const
{
    return m_Fov;
}

void rle::Camera::setFov(const float fov)
{
    m_Fov = fov;
}

rle::Vector2f rle::Camera::project3D(const EngineRenderer& renderer, const Vector3f& p3d, const Transform& transform) const
{
    const auto& win_s = renderer.windowSize();
    const auto aspect = static_cast<float>(win_s.y) / static_cast<float>(win_s.x);
    const auto adj_fov = 1.0f / math::degToRad(m_Fov * 0.5f);

    const auto proj_mat = getPrespeciveProjMat(aspect, adj_fov, m_Far, m_Near);

    const auto proj = transform.project(proj_mat);

    return { proj.x, proj.y };
}
