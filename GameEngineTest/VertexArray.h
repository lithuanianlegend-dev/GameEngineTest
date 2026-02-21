#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <vector>

class VertexArray
{
public:

	struct VertexAttribute {
		GLuint location;
		GLint numComponents;
		GLenum type;
		GLenum normalized;
		GLint vertexStride;
		size_t offset;
	};

	VertexArray(const float* vertices,
		size_t vertexSize,
		std::vector<VertexAttribute>& layout,
		const unsigned int* indices = nullptr, 
		size_t indexCount = 0, 
		GLenum drawType = GL_STATIC_DRAW);

	~VertexArray();

	void Bind() const;
	void Unbind() const;


private:
	GLuint VBO, VAO, EBO;
	bool hasEBO;
};