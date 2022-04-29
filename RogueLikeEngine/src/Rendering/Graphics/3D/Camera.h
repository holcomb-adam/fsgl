#pragma once

#include "Math/Matrix.h"
#include "Math/Vector2.h"
#include "Math/Vector3.h"



namespace rle
{
	// rle forward declaration
	class EngineRenderer;
	class Transform;



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

		// multiply a 3D vector with a 4x4 Matrix
		static float multiplyVecMat(const Vector3f& in, Vector3f& out, const Matrix44f& m);

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

		// project a 3D point to a 2D plane defined by the camera
		void project3D(
			const EngineRenderer& renderer,
			const Vector3f& in,
			Vector2f& out,
			const Transform& transform) const;

	private:

	private:
		// Camera will default to facing North
		Vector3f m_Directional = { 0.0f, 0.0f, 1.0f };

		float m_Near = 0.1f;
		float m_Far = 1000.0f;
		float m_Fov = 90.0f;
	};
}
