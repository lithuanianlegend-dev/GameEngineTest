#pragma once

#include "glad/glad.h"
#include "GLFW/glfw3.h"

#include <iostream>
#include <sstream>
#include <fstream>
#include <string>

class Shader
{
protected:
	unsigned int ID;

public:
	// we make a shader with all these!
	Shader(const char* vertexShaderPath, const char* fragmentShaderPath, const char* geometryShaderPath = nullptr);
	
	// we activate the well... shader.
	void Activate()
	{
		glUseProgram(ID);
	}


};