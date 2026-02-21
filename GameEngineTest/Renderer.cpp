#include "Renderer.h"

void Renderer::BeginFrame()
{
	glClearColor(0.0f, 0.0f, 0.3, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
}

void Renderer::EndFrame()
{
	glfwSwapBuffers(Window::handle);
	glfwPollEvents();
}

void Renderer::StartOfFunc()
{
	glEnable(GL_MULTISAMPLE);
}