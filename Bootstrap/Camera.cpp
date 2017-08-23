#include "Camera.h"

Camera::Camera() {};
Camera::~Camera() {};
void Camera::update(float deltatime)
{
}

//FOV = Field of View || AR = Apsect Ratio || near = near ||
void Camera::setPerspective(float FOV, float AR, float near, float far)
{
	auto x = 1.f / (FOV * tan(FOV / 2.f));
	auto y = 1.f / (FOV * tan(FOV / 2.f));
	auto z = -1.f * ((2.f * far * near) / (far - near));
	auto w = -1.f * ((2.f * far * near) / (far - near));

	this->projectionTransform = glm::mat4(
		glm::vec4(x, 0, 0, 0),
		glm::vec4(0, y, 0, 0),
		glm::vec4(0, 0, z, -1.f),
		glm::vec4(0, 0, w, 0));
	)
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