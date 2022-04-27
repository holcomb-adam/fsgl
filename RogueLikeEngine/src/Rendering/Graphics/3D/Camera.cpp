#include "Camera.h"

#include "Transform.h"
#include "Math/Trigonometry.h"
#include "Rendering/EngineRenderer.h"

//rle::Matrix44f rle::Camera::getPrespeciveProjMat(const float aspect, const float fov, const float far, const float near)
//{
//    const auto q = far / (far - near);
//    return Matrix44f
//    (
//        {
//            aspect * fov, 0.0f, 0.0f,      0.0f,
//            0.0f,         fov,  0.0f,      0.0f,
//            0.0f,         0.0f, q,         1.0f,
//            0.0f,         0.0f, q * -near, 0.0f
//        }
//    );
//}

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

void rle::Camera::project3D(const EngineRenderer& renderer, const Vector3f& in, Vector2f& out, const Transform& transform) const
{
    // starting values needed to get the projection matrix
    const auto& win_s = renderer.windowSize();
    const auto aspect = static_cast<float>(win_s.y) / static_cast<float>(win_s.x);
    const auto adj_fov = 1.0f / tan(math::degToRad(m_Fov) * 0.5f);

    // get the projection matrix
    //const auto& m = getPrespeciveProjMat(aspect, adj_fov, m_Far, m_Near);const auto q = far / (far - near);
    const auto q = m_Far / (m_Far - m_Near);
    const float m[4][4] =
    {
        aspect * adj_fov, 0.0f,    0.0f,        0.0f,
        0.0f,             adj_fov, 0.0f,        0.0f,
        0.0f,             0.0f,    q,           1.0f,
        0.0f,             0.0f,    q * -m_Near, 0.0f
    };

    // translate our vector
    // TEMPORARY - this acts as placeholder code for translation of 3d objects
    Vector3f vt = in;
    vt += transform.position();

    // temp placeholder for our vector that needs to be projected
    Vector3f v;
    v.x = vt.x * m[0][0] + vt.y * m[1][0] + vt.z * m[2][0] + m[3][0];
    v.y = vt.x * m[0][1] + vt.y * m[1][1] + vt.z * m[2][1] + m[3][1];
    v.z = vt.x * m[0][2] + vt.y * m[1][2] + vt.z * m[2][2] + m[3][2];
    const float w = vt.x * m[0][3] + vt.y * m[1][3] + vt.z * m[2][3] + m[3][3];

    if (w != 0.0f)
    {
        v.x /= w;
        v.y /= w;
        v.z /= w;
    }

    // scale the new point into the view
    v.x += 1.0f; v.x *= 0.5f * static_cast<float>(win_s.x);
    v.y += 1.0f; v.y *= 0.5f * static_cast<float>(win_s.y);

    // set the out vector
    out.x = v.x;
    out.y = v.y;
}
