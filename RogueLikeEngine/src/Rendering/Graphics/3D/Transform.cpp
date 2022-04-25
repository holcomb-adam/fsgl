#include "Transform.h"

rle::Transform::Transform(const Vector3f& pos)
{
	setPosition(pos);
}

rle::Vector3f rle::Transform::position() const
{
	return { m_ModelMat[3][0], m_ModelMat[3][1], m_ModelMat[3][2] };
}

void rle::Transform::setPosition(const Vector3f& pos)
{
	setPosition(pos.x, pos.y, pos.z);
}

void rle::Transform::setPosition(const float x, const float y, const float z)
{
	m_ModelMat[3][0] = x;
	m_ModelMat[3][1] = y;
	m_ModelMat[3][2] = z;
}

rle::Vector3f rle::Transform::project(const Matrix44f& view_mat) const
{
	Matrix44f mat;
	mat = m_ModelMat * view_mat;
	return { mat[3][0], mat[3][1], mat[3][2] };
}
