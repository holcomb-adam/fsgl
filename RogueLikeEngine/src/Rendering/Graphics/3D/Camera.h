#pragma once

#include "Math/Matrix.h"
#include "Math/Vector2.h"
#include "Math/Vector3.h"
#include "Rendering/Graphics/3D/Transform.h"



namespace rle
{
	// rle forward declaration
	class EngineRenderer;



	class Camera final
	{
	public:
		// get a 3D Persepctive Projection Matrix
		static Matrix44f getPrespeciveProjMat
		(
			const float aspect,
			const float fov,
			const float far,
			const float near
		);

	public:
		////////////////////////////////////////////////////////////////////////////////
		// - CONSTRUCTORS / DESTRUCTORS ------------------------------------------------

		// default ctor
		Camera() = default;

		// default dtor
		~Camera() = default;



		////////////////////////////////////////////////////////////////////////////////
		// - SETTERS / GETTERS ---------------------------------------------------------

		// get the distance to the near clipping plane
		float nearClipping() const;

		// set the distance to the near clipping plane
		void setNearClipping(const float near);

		// get the distance to the far clipping plane
		float farClipping() const;

		// set the distance to the far clipping plane
		void setFarClipping(const float far);

		// get the fov
		float fov() const;

		// set the fov
		void setFov(const float fov);



		////////////////////////////////////////////////////////////////////////////////
		// - 3D PROJECTION CALULCATIONS ------------------------------------------------

		// project a 3D point and transform to space to the 2D plane defined by
		Vector2f project3D(const EngineRenderer& renderer, const Vector3f& p3d, const Transform& transform) const;

	private:
		// Camera will default to facing North
		Vector3f m_Directional = { 0.0f, 0.0f, 1.0f };

		float m_Near = 0.1f;
		float m_Far = 1000.0f;
		float m_Fov = 90.0f;
	};
}
