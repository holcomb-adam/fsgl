#pragma once

#include "Math/Matrix.h"
#include "Math/Vector3.h"



namespace rle
{
	class Transform
	{
	public:
		////////////////////////////////////////////////////////////////////////////////
		// - CONSTRUCTORS / DESTRUCTORS ------------------------------------------------

		// default ctor
		Transform() = default;

		// ctor
		// sets the position
		Transform(const Vector3f& pos);

		// virtual default dtor
		virtual ~Transform() = default;



		////////////////////////////////////////////////////////////////////////////////
		// - SETTERS / GETTERS ---------------------------------------------------------

		// get position of the transform
		Vector3f position() const;

		// set position of the transform
		void setPosition(const Vector3f& pos);

		// set position of the transform
		void setPosition(const float x, const float y, const float z);




		Vector3f project(const Matrix44f& view_mat) const;




	private:
		Matrix44f m_ModelMat;
	};
}
