#pragma once

#include "glad/glad.h"
#include "GLFW/glfw3.h"

#include "stb_image.h"
#include <iostream>

class TextureLoader
{
public:
	static GLuint loadTexture(const char* path);
protected:
	GLuint ID;
};