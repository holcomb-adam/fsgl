#pragma once

#include "Math/Matrix.h"
#include "Math/Vector2.h"
#include "Math/Vector3.h"



namespace rle
{
	// rle forward declaration
	class EngineRenderer;



	class Camera final
	{
	public:
		Camera() = default;

		~Camera() = default;

		Vector2f project3D(const EngineRenderer& renderer, const Vector3f& p3d) const;

	private:
		Vector3f tempFunc(const Vector3f& i, const Matrix44f& pmat) const;

	private:
		float m_Near = 0.1f;
		float m_Far = 1000.0f;
		float m_Fov = 90.0f;
	};
}
