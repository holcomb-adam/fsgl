#pragma once

#include "Math/Matrix.h"
#include "Math/Vector.h"



namespace rle
{
	// The model matrix
	// ---                       ---
	// | scal_x  0       0       0 |
	// | 0       scal_y  0       0 |
	// | 0       0       scal_z  0 |
	// | x_trans y_trans z_trans 1 |
	// ---                       ---

	class Transform
	{
	public:
		////////////////////////////////////////////////////////////////////////////////
		// - CONSTRUCTORS / DESTRUCTORS ------------------------------------------------

		// default ctor
		Transform();

		// ctor
		// sets the position
		Transform(const Vector3f& pos);

		// virtual default dtor
		virtual ~Transform() = default;



		////////////////////////////////////////////////////////////////////////////////
		// - TRANSLATION OPERATIONS ----------------------------------------------------

		// get position of the transform
		Vector3f position() const;

		// set position of the transform
		void setPosition(const Vector3f& pos);

		// set position of the transform
		void setPosition(const float x, const float y, const float z);

		// move the camera by unit
		void move(const float x, const float y, const float z);

		// get the rotation of the transform
		// this returns a 3D vector of angles in radians
		Vector3f rotation() const;

		// set the rotation of the transform
		void setRotation(const Vector3f& rot);

		// get the scaling of the transform
		Vector3f scale() const;

		// set the scal of the trasnform
		void setScale(const Vector3f& scale);

		

		////////////////////////////////////////////////////////////////////////////////
		// - OBSERVER FUNCTIONS --------------------------------------------------------

		// get the model matrix
		const Matrix44f& modelMatrix() const;

		// get the x rotation matrix
		const Matrix44f& xRotMatrix() const;

		// get the y rotation matrix
		const Matrix44f& yRotMatrix() const;

		// get the z rotatio matrix
		const Matrix44f& zRotMatrix() const;

	private:
		Matrix44f m_ModelMat;
		Matrix44f m_XRotation;
		Matrix44f m_YRotation;
		Matrix44f m_ZRotation;
	};
}
