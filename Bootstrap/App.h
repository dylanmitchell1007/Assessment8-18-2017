#pragma once
#include "App.h"
struct Camera;
struct GLFWwindow;
class App
{
public:
	App();
	virtual void startup();
	virtual void shutdown();
	virtual void update(float deltatime);
	virtual void draw();
	virtual void run(const char* title, unsigned int width, unsigned int height, bool fullscreen);
	
protected:
	Camera* m_camera;
	GLFWwindow* _window;
	GLFWmonitor* _monitor;

	
};

