#include "EngineBase.h"


int main()
{
	Window::InitWindow(800, 600, "Window person");

	while (!glfwWindowShouldClose(Window::handle))
	{
		Renderer::BeginFrame();

		Window::WindowEndFrame();
	}

	Cleanup::CleanupAll();

	return 0;
}