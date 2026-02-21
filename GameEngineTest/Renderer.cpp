#include "Renderer.h"

void Renderer::BeginFrame()
{
	InputHandler::ProcessInput();

	Time::Update();
	Time::MeasureFramesPerSecond();
	
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
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