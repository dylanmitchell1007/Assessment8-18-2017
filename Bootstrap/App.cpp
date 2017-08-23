#include "gl_core_4_4.h"
#include <glfw3.h>
#include <assert.h>
#include "App.h"
#include "Gizmos.h"
#include "Camera.h"



App::App() {};

void App::startup()
{
	Camera* camera = new Camera;
	Gizmos::create();

}
void App::shutdown()
{

}
void App::update(float deltatime)
{

}
glm::mat4 s1 = glm::mat4(1);
glm::vec4 center = glm::vec4(0, 0, 0, 1);
glm::vec4 color = glm::vec4(0, 0, 0, 0);
void App::draw()
{
	Gizmos::clear();
	Gizmos::addSphere(s1[3], 1, 20, 20, color);
	Gizmos::addTransform(s1, 4);
	glm::vec4 white(1);
	glm::vec4 black(0, 0, 0, 1);
	for (int i = 0; i < 21; ++i)
	{
		Gizmos::addLine(glm::vec3(-10 + i, 0, 10),
			glm::vec3(-10 + i, 0, -10),
			i == 10 ? white : black);

	}
	Gizmos::draw(glm::mat4(1));

}
void App::run(const char* title, unsigned int width, unsigned int height, bool fullscreen)
{


	if (glfwInit() == GL_FALSE)
		return;
	double prevTime = glfwGetTime();
	double currTime = 0;
	double deltaTime = 0;

	glfwInit();
	//GL Creates a window with these specifications
	this->_window= glfwCreateWindow(width, height, "Passed", nullptr, nullptr);
	glfwMakeContextCurrent(this->_window);
	if (this->_window == nullptr)
	{
		char a = -2;
		glfwTerminate();

	}
	ogl_LoadFunctions();

	this->startup();

	while (glfwWindowShouldClose(this->_window) == false)
	{

		if (glfwGetKey(this->_window, GLFW_KEY_ESCAPE))
		{
			glfwSetWindowShouldClose(this->_window, GL_TRUE);
		}
		glClear(GL_COLOR_BUFFER_BIT);
		this->draw();
		glfwSwapBuffers(this->_window);

		glfwPollEvents();
	}
	glfwTerminate();



}

