#include "ShaderLoader.h"

#include <filesystem>

Shader::Shader(const char* vertexShaderPath, const char* fragmentShaderPath, const char* geometryShaderPath)
{
	std::string vertexCode;
	std::string fragmentCode;
	std::string geometryCode;
	std::ifstream vShaderFile;
	std::ifstream fShaderFile;
	std::ifstream gShaderFile;

	vShaderFile.exceptions(std::ifstream::badbit | std::ifstream::failbit);
	fShaderFile.exceptions(std::ifstream::badbit | std::ifstream::failbit);
	gShaderFile.exceptions(std::ifstream::badbit | std::ifstream::failbit);
	
	if (!std::filesystem::exists(vertexShaderPath))
		std::cout << "Vertex shader file not found: " << vertexShaderPath << std::endl;

	if (!std::filesystem::exists(fragmentShaderPath))
		std::cout << "Fragment shader file not found: " << fragmentShaderPath << std::endl;

	if (geometryShaderPath != nullptr && !std::filesystem::exists(geometryShaderPath))
		std::cout << "Geometry shader file not found: " << geometryShaderPath << std::endl;

	try 
	{
		vShaderFile.open(vertexShaderPath);
		fShaderFile.open(fragmentShaderPath);

		std::stringstream vShaderStream, fShaderStream, gShaderStream;

		if (geometryShaderPath != nullptr) {
			gShaderFile.open(geometryShaderPath);
			gShaderStream << gShaderFile.rdbuf();
			geometryCode = gShaderStream.str();
			gShaderFile.close();
		}

		vShaderStream << vShaderFile.rdbuf();
		fShaderStream << fShaderFile.rdbuf();

		vShaderFile.close();
		fShaderFile.close();

		vertexCode = vShaderStream.str();
		fragmentCode = fShaderStream.str();
	}
	catch (std::ifstream::failure e)
	{
		std::cout << "ERROR::SHADER::NOT::SUCCESSFULLY::READ" << std::endl;
	}

	const char* vShaderCode = vertexCode.c_str();
	const char* fShaderCode = fragmentCode.c_str();
	const char* gShaderCode = geometryCode.c_str();

	GLuint vertex, fragment, geometry;
	
	vertex = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertex, 1, &vShaderCode, NULL);
	glCompileShader(vertex);

	int success;
	char infoLog[512];
	glGetShaderiv(vertex, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(vertex, 512, NULL, infoLog);
		printf("ERROR::SHADER::VERTEX::COMPILATION_FAILED\n%s\n", infoLog);
	}


	fragment = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragment, 1, &fShaderCode, NULL);
	glCompileShader(fragment);
	
	glGetShaderiv(fragment, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(fragment, 512, NULL, infoLog);
		printf("ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n%s\n", infoLog);
	}


	if (geometryShaderPath != nullptr)
	{
		geometry = glCreateShader(GL_GEOMETRY_SHADER);
		glShaderSource(geometry, 1, &gShaderCode, NULL);
		glCompileShader(geometry);

		glGetShaderiv(geometry, GL_COMPILE_STATUS, &success);
		if (!success)
		{
			glGetShaderInfoLog(geometry, 512, NULL, infoLog);
			printf("ERROR::SHADER::GEOMETRY::COMPILATION_FAILED\n%s\n", infoLog);
		}
	}

	ID = glCreateProgram();
	glAttachShader(ID, vertex);
	glAttachShader(ID, fragment);
	if (geometryShaderPath != nullptr) glAttachShader(ID, geometry);
	glLinkProgram(ID);

	glDeleteShader(vertex);
	glDeleteShader(fragment);
	if (geometryShaderPath != nullptr) glDeleteShader(geometry);
}
