#include "Camera.h"

#include "Math/Trigonometry.h"
#include "Rendering/EngineRenderer.h"

rle::Vector2f rle::Camera::project3D(const EngineRenderer& renderer, const Vector3f& p3d) const
{
    const auto& win_s = renderer.windowSize();
    const auto aspect = static_cast<float>(win_s.y) / static_cast<float>(win_s.x);
    const auto adj_fov = 1.0f / math::degToRad(m_Fov / 2.0f);

    // hopefully temp, but at this point, idc...
    const Matrix44f proj_mat = std::array{
        aspect * adj_fov, 0.0f, 0.0f, 0.0f,
        0.0f, adj_fov * 1.0f, 0.0f, 0.0f,
        0.0f, 0.0f, m_Far / (m_Far - m_Near), 0.0f,
        0.0f, 0.0f, 1.0f, 0.0f
    };

    auto proj = tempFunc(p3d.getUnitVector(), proj_mat);

    // scale the vector into the view
    proj.x += 1.0f;
    proj.y += 1.0f;

    proj.x *= 0.5f * static_cast<float>(win_s.x);
    proj.y *= 0.0f * static_cast<float>(win_s.y);

    return { proj.x, proj.y };
}

rle::Vector3f rle::Camera::tempFunc(const Vector3f& i, const Matrix44f& pmat) const
{
    Vector3f vec;
    vec.x = i.x * pmat[0][0] + i.y * pmat[1][0] + i.z * pmat[2][0] + pmat[3][0];
    vec.y = i.x * pmat[0][1] + i.y * pmat[1][1] + i.z * pmat[2][1] + pmat[3][1];
    vec.z = i.z * pmat[0][2] + i.y * pmat[1][2] + i.z * pmat[2][2] + pmat[3][2];
    const auto w = i.x * pmat[0][3] + i.y * pmat[1][3] + i.z * pmat[2][3] + pmat[3][3];

    if (w != 0.0f)
    {
        vec.x /= w;
        vec.y /= w;
        vec.z /= w;
    }

    return vec;
}
