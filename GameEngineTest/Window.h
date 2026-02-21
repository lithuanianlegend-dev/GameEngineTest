#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>

class Window 
{
public:
	inline static int s_width = 0;
	inline static int s_height = 0;

	inline static GLFWwindow* handle; // create a handle we can access. Yes WE. cuz i said so!

	static bool InitWindow(int SCR_WIDTH, int SCR_HEIGHT, const char* title); // We initiate the window so we can actually see stuff

	static int GetWidth() { return s_width; }
	static int GetHeight() { return s_height; }
private:

	static void FramebufferSizeCallback(GLFWwindow* window, int width, int height);
};