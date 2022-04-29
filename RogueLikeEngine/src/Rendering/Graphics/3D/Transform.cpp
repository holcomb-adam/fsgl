#include "Transform.h"

rle::Transform::Transform()
{
	m_ModelMat.at(0, 0) = 1;
	m_ModelMat.at(1, 1) = 1;
	m_ModelMat.at(2, 2) = 1;
	m_ModelMat.at(3, 3) = 1;
}

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
	m_ModelMat.at(0, 3) = x;
	m_ModelMat.at(1, 3) = y;
	m_ModelMat.at(2, 3) = z;
}

rle::Vector3f rle::Transform::rotation() const
{
	return { 1.0f, 1.0f, 1.0f };
}

void rle::Transform::setRotation(const Vector3f& rot)
{
	// x axis rotation
	m_XRotation.at(0, 0) = 1.0f;
	m_XRotation.at(1, 1) = cos(rot.x);
	m_XRotation.at(2, 1) = -sin(rot.x);
	m_XRotation.at(1, 2) = sin(rot.x);
	m_XRotation.at(2, 2) = cos(rot.x);
	m_XRotation.at(3, 3) = 1.0f;

	// y axis rotation
	m_YRotation.at(0, 0) = cos(rot.y);
	m_YRotation.at(2, 0) = sin(rot.y);
	m_YRotation.at(1, 1) = 1;
	m_YRotation.at(0, 2) = -sin(rot.y);
	m_YRotation.at(2, 2) = cos(rot.y);

	// z axis rotation
	m_ZRotation.at(0, 0) = cos(rot.z);
	m_ZRotation.at(1, 0) = -sin(rot.z);
	m_ZRotation.at(0, 1) = sin(rot.z);
	m_ZRotation.at(1, 1) = cos(rot.z);
	m_ZRotation.at(2, 2) = 1.0f;
	m_ZRotation.at(3, 3) = 1.0f;
}

rle::Vector3f rle::Transform::scale() const
{
	return { m_ModelMat.at(0, 0), m_ModelMat.at(1, 1), m_ModelMat.at(2, 2) };
}

void rle::Transform::setScale(const Vector3f& scale)
{
	m_ModelMat.at(0, 0) = scale.x;
	m_ModelMat.at(1, 1) = scale.y;
	m_ModelMat.at(2, 2) = scale.z;
}

const rle::Matrix44f& rle::Transform::modelMatrix() const
{
	return m_ModelMat;
}

const rle::Matrix44f& rle::Transform::xRotMatrix() const
{
	return m_XRotation;
}

const rle::Matrix44f & rle::Transform::yRotMatrix() const
{
	return m_YRotation;
}

const rle::Matrix44f& rle::Transform::zRotMatrix() const
{
	return m_ZRotation;
}
