#pragma once

#include "Transform.h"
#include "Math/Matrix.h"
#include "Math/Vector.h"
#include "Math/Shapes/Triangle.h"



namespace rle
{
	// rle forward declaration
	class EngineRenderer;



	class Camera final : public Transform
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

		// get whether or not the camera is in wireframe mode
		bool isWireFrame() const;

		// set whether or not the camera is in wireframe mode
		void setWireFrame(const bool b);

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
		bool project3D(
			const EngineRenderer& renderer,
			const Triangle3f& in,
			Triangle2f& out,
			const Transform& transform) const;

	private:
		bool m_WireFrame = false;
		bool m_Lights = false;

		float m_Near = 0.1f;
		float m_Far = 1000.0f;
		float m_Fov = 90.0f;
	};
}
