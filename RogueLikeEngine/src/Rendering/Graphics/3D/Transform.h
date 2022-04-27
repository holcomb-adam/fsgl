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
		// - TRANSLATION OPERATIONS ----------------------------------------------------

		// get position of the transform
		Vector3f position() const;

		// set position of the transform
		void setPosition(const Vector3f& pos);

		// set position of the transform
		void setPosition(const float x, const float y, const float z);



		////////////////////////////////////////////////////////////////////////////////
		// - ARITHMETIC OPERATIONS ----------------------------------------------------

		// calculate the point to transform


	private:
		Matrix44f m_ModelMat;
	};
}
