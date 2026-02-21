#include "Window.h"

void Window::FramebufferSizeCallback(GLFWwindow* window, int width, int height)
{
	s_width = width;
	s_height = height;
	glViewport(0, 0, width, height); // we call this so we can resize the OpenGL rendering viewport (our window)
}

bool Window::InitWindow(int SCR_WIDTH, int SCR_HEIGHT, const char* title)
{
	s_width = SCR_WIDTH;
	s_height = SCR_HEIGHT;

	glfwInit(); // use glfw
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4); // OpenGL 4.?
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6); // OpenGL 4.6
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); // use the core profile

	Window::handle = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, title, NULL, NULL); // create window

	glfwSetFramebufferSizeCallback(handle, FramebufferSizeCallback); // when window resizes, reset rendering viewport to match

	if (handle == NULL) // if window failed to exist... sadly... it does this
	{
		std::cout << "WINDOW CREATION FAILED: WINDOW IS NULL" << std::endl;
		glfwTerminate();
		return false;
	}

	glfwMakeContextCurrent(handle); // make our window the current context

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) // checks if glad has a procAdress (if it exists)
	{
		std::cout << "GLAD INITIATION FAILED FOR UNKNOWN REASON!" << std::endl;
		return false;
	}

	return true; // everything is fine! dont fail the program
}

void Window::WindowEndFrame() // this just handles all the event polling, swappingbuffers, but does it so it looks nice in my Main.cpp file!
{
	glfwSwapBuffers(Window::handle);
	glfwPollEvents();
}