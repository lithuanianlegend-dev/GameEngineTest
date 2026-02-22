#include "Input.h"


void InputHandler::ProcessInput(Camera& camera)
{
	// debug. REMOVE THIS IF YOU EVER LAUNCH THIS STUPID ENGINE!!!
	if (glfwGetKey(Window::handle, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(Window::handle, true);
	
	if (glfwGetKey(Window::handle, GLFW_KEY_F) == GLFW_PRESS)
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	else
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

	// unity like mouse movement and stuff...
	if (glfwGetMouseButton(Window::handle, GLFW_MOUSE_BUTTON_2) == GLFW_PRESS)
	{
		camera.canMove = true;
		glfwSetInputMode(Window::handle, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
	}
	else
	{
		camera.canMove = false;
		glfwSetInputMode(Window::handle, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
	}

	// camera movement
	if (glfwGetKey(Window::handle, GLFW_KEY_W) == GLFW_PRESS)
		camera.ProcessKeyboard(FORWARD, Time::getDeltaTime());
	if (glfwGetKey(Window::handle, GLFW_KEY_S) == GLFW_PRESS)
		camera.ProcessKeyboard(BACKWARD, Time::getDeltaTime());
	if (glfwGetKey(Window::handle, GLFW_KEY_A) == GLFW_PRESS)
		camera.ProcessKeyboard(LEFT, Time::getDeltaTime());
	if (glfwGetKey(Window::handle, GLFW_KEY_D) == GLFW_PRESS)
		camera.ProcessKeyboard(RIGHT, Time::getDeltaTime());
	if (glfwGetKey(Window::handle, GLFW_KEY_E) == GLFW_PRESS)
		camera.ProcessKeyboard(UP, Time::getDeltaTime());
	if (glfwGetKey(Window::handle, GLFW_KEY_Q) == GLFW_PRESS)
		camera.ProcessKeyboard(DOWN, Time::getDeltaTime());

}
