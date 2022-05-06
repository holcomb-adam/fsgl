#include "Camera.h"

#include "Transform.h"
#include "Math/Trigonometry.h"
#include "Rendering/EngineRenderer.h"

rle::Matrix44f rle::Camera::getPrespeciveProjMat(const float aspect, const float fov, const float far, const float near)
{
    const auto q = far / (far - near);
    return Matrix44f
    (
        {
            aspect * fov, 0.0f,     0.0f,      0.0f,
            0.0f,         fov,      0.0f,      0.0f,
            0.0f,         0.0f,     q,         1.0f,
            0.0f,         0.0f,     q * -near, 0.0f
        }
    );
}

float rle::Camera::multiplyVecMat(const Vector3f& in, Vector3f& out, const Matrix44f& m)
{
    const auto& u = m.underlying();

    out.x = in.x * u[0] + in.y * u[4] + in.z * u[8] + u[12];
    out.y = in.x * u[1] + in.y * u[5] + in.z * u[9] + u[13];
    out.z = in.x * u[2] + in.y * u[6] + in.z * u[10] + u[14];
    return in.x * u[3] + in.y * u[7] + in.z * u[11] + u[15];
}

bool rle::Camera::isWireFrame() const
{
    return m_WireFrame;
}

void rle::Camera::setWireFrame(const bool b)
{
    m_WireFrame = b;
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

bool rle::Camera::project3D(const EngineRenderer& renderer, const Triangle3f& in, Triangle2f& out, const Transform& transform) const
{
    // starting values needed to get the projection matrix
    const auto& win_s = renderer.windowSize();
    const auto aspect = static_cast<float>(win_s.y) / static_cast<float>(win_s.x);
    const auto adj_fov = 1.0f / tanf(math::degToRad(m_Fov) * 0.5f);

    // get the projection matrix
    const auto& m = getPrespeciveProjMat(aspect, adj_fov, m_Far, m_Near);

    // transformation buffers
    Vector3f vrz, vry, vrx, vt, vp;

    for (std::size_t i = 0; i < in.size(); i++)
    {
        // apply the rotations to the vector
        multiplyVecMat(in[i], vrz, transform.zRotMatrix());
        multiplyVecMat(vrz, vry, transform.yRotMatrix());
        multiplyVecMat(vry, vrx, transform.xRotMatrix());

        // apply the translation to the vector
        multiplyVecMat(vrx, vt, transform.modelMatrix());

        // apply the camera transformations
        vt -= position();

        // temp placeholder for our vector that needs to be projected
        const auto w = multiplyVecMat(vt, vp, m);

        // normalize the projection vector
        if (w != 0.0f)
        {
            vp.x /= w;
            vp.y /= w;
            vp.z /= w;
        }

        // scale the new point into the view
        vp.x += 1.0f;
        vp.x *= 0.5f * static_cast<float>(win_s.x);
        vp.y += 1.0f;
        vp.y *= 0.5f * static_cast<float>(win_s.y);

        // set the output vector
        out[i].x = vp.x;
        out[i].y = vp.y;
    }

    return true;
}
