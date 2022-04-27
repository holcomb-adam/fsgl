#include "Transform.h"

rle::Transform::Transform(const Vector3f& pos)
{
	setPosition(pos);
}

rle::Vector3f rle::Transform::position() const
{
	return { m_ModelMat.at(3, 0), m_ModelMat.at(3, 1), m_ModelMat.at(3, 2) };
}

void rle::Transform::setPosition(const Vector3f& pos)
{
	setPosition(pos.x, pos.y, pos.z);
}

void rle::Transform::setPosition(const float x, const float y, const float z)
{
	m_ModelMat.at(3, 0) = x;
	m_ModelMat.at(3, 1) = y;
	m_ModelMat.at(3, 2) = z;
}
