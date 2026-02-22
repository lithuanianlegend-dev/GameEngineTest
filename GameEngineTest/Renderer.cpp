#include "Renderer.h"

void Renderer::BeginFrame()
{
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Renderer::EndFrame()
{
	glfwSwapBuffers(Window::handle);
	glfwPollEvents();
}

void Renderer::Init()
{
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_MULTISAMPLE);
}