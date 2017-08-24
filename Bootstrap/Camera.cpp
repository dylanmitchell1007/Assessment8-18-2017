#include "Camera.h"
#include <ext.hpp>

Camera::Camera() {};
Camera::~Camera() {};
void Camera::update(float deltatime)
{
}

//FOV = Field of View || AR = Apsect Ratio || near = near ||
void Camera::setPerspective(float FOV, float AR, float m_near, float m_far)
{
	auto x = 1.f / (FOV * tan(FOV / 2.f));
	auto y = 1.f / (FOV * tan(FOV / 2.f));
	auto z = -1.f * ((2.f * m_far * m_near) / (m_far - m_near));
	auto w = -1.f * ((2.f * m_far * m_near) / (m_far - m_near));

	this->projectionTransform = glm::mat4(
		glm::vec4(x, 0, 0, 0),
		glm::vec4(0, y, 0, 0),
		glm::vec4(0, 0, z, -1.f),
		glm::vec4(0, 0, w, 0));
	auto copy = glm::perspective(FOV, 16 / 9.f, 0.1f, 10.f);
	assert(this->projectionTransform == copy);
	
}
void Camera::setLookAt(glm::vec3 eye, glm::vec3 center, glm::vec3 up)
{
	
	

}
void Camera::setPosition(glm::vec3 position)
{
	
}
glm::mat4 Camera::getWorldTransform()
{
	return this->worldTransform;
}
glm::mat4 Camera::getView()
{
	return this->viewTransform;
}
glm::mat4 Camera::getProjection()
{
	return this->projectionTransform;
}
glm::mat4 Camera::getProjectionView()
{
	return this->projectionViewTransform;
}

void Camera::updateProjectionViewTransform()
{

}