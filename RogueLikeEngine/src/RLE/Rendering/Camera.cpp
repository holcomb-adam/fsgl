#include "RLEpch.h"
#include "Camera.hpp"

// --- External ---
#include <glm/gtc/matrix_transform.hpp>



rle::Camera::Camera(const glm::mat4& proj, const glm::vec3& position) :
	m_Projection(proj),
	m_Position(position)
{
	
}

const glm::vec3& rle::Camera::position() const
{
	return m_Position;
}

void rle::Camera::setPosition(const glm::vec3& position)
{
	m_Position = position;
}

float rle::Camera::rotation() const
{
	return m_Rotation;
}

void rle::Camera::setRotation(const float degrees)
{
	m_Rotation = degrees;
}

const glm::mat4& rle::Camera::projectionMatrix() const
{
	return m_Projection;
}

glm::mat4 rle::Camera::calcViewProjectionMatrix() const
{
	const auto transform = glm::translate(glm::mat4(1.0f), m_Position) * 
		glm::rotate(glm::mat4(1.0f), glm::radians(m_Rotation), glm::vec3(0.0f, 0.0f, 1.0f));

	return m_Projection * glm::inverse(transform);
}





////////////////////////////////////////////////////////////////////////////////
// - FACTORY IMPL --------------------------------------------------------------

std::unique_ptr<rle::Camera> rle::factory<rle::Camera>::make_orthographic(
	const float x_min,
	const float x_max,
	const float y_min,
	const float y_max,
	const float z_near,
	const float z_far)
{
	return std::unique_ptr<Camera>(
		new Camera(
			glm::ortho(x_min, x_max, y_min, y_max, z_near, z_far)));
}
