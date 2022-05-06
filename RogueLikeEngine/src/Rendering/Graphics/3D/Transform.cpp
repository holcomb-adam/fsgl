#include "Transform.h"

rle::Transform::Transform()
{
	// apply default transformations
	setRotation({ 0.0f, 0.0f, 0.0f });
	setScale({ 1.0f, 1.0f, 1.0f });
	setPosition(0.0f, 0.0f, 0.0f);
}

rle::Transform::Transform(const Vector3f& pos)
{
	setPosition(pos);
}

rle::Vector3f rle::Transform::position() const
{
	return { m_ModelMat.at(0, 3), m_ModelMat.at(1, 3), m_ModelMat.at(2, 3) };
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

void rle::Transform::move(const float x, const float y, const float z)
{
	const auto& pos = position();
	setPosition(pos + Vector3f(x, y, z));
}

rle::Vector3f rle::Transform::rotation() const
{
	return { 1.0f, 1.0f, 1.0f };
}

void rle::Transform::setRotation(const Vector3f& rot)
{
	// x axis rotation
	m_XRotation.at(0, 0) = 1.0f;
	m_XRotation.at(1, 1) = cosf(rot.x);
	m_XRotation.at(2, 1) = -sinf(rot.x);
	m_XRotation.at(1, 2) = sinf(rot.x);
	m_XRotation.at(2, 2) = cosf(rot.x);
	m_XRotation.at(3, 3) = 1.0f;

	// y axis rotation
	m_YRotation.at(0, 0) = cosf(rot.y);
	m_YRotation.at(2, 0) = sinf(rot.y);
	m_YRotation.at(1, 1) = 1;
	m_YRotation.at(0, 2) = -sinf(rot.y);
	m_YRotation.at(2, 2) = cosf(rot.y);

	// z axis rotation
	m_ZRotation.at(0, 0) = cosf(rot.z);
	m_ZRotation.at(1, 0) = -sinf(rot.z);
	m_ZRotation.at(0, 1) = sinf(rot.z);
	m_ZRotation.at(1, 1) = cosf(rot.z);
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
