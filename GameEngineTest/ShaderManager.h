#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "ShaderLoader.h"

#include <string>
#include <unordered_map>

class ShaderManager {
public:
	// we make a name for the shader, and then all of its code goes in the three parameters after the name
	static void loadShader(const std::string& name,
		const std::string& vertex,
		const std::string& fragment,
		const std::string& geometry);

	// we get a shader!
	static Shader* GetShader(const std::string& name);

	// clean up everything!
	static void cleanUp();



protected:
	// this is a hashmap. it holds our data and stuff
	std::unordered_map<std::string, Shader*> shaders;
};

