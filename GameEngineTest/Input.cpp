#include "Input.h"

void InputHandler::ProcessInput()
{

	if (glfwGetKey(Window::handle, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(Window::handle, true);
	
	if (glfwGetKey(Window::handle, GLFW_KEY_F) == GLFW_PRESS)
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	else
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
}