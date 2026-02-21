#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

class Cleanup
{
public:
	static void CleanupAll(); // when everything ends, we call this function to prevent memory leaks
};