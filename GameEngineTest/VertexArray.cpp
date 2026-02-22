#include "VertexArray.h"



VertexArray::VertexArray(const float* vertices,
	size_t vertexSize,
	const std::vector<VertexAttribute>& layout,
	size_t vertexCount,
	const unsigned int* indices,
	size_t indexCount,
	GLenum drawType)
{
	hasEBO = indices != nullptr; // it will equal indices if indices isnt 0.

	glGenBuffers(1, &VBO);
	glGenVertexArrays(1, &VAO);

	glBindVertexArray(VAO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, vertexSize, vertices, drawType);

	if (hasEBO) {
		glGenBuffers(1, &EBO);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, indexCount, indices, drawType);
	}

	for (auto& attr : layout) // : is basically in so attribute in layout
	{
		glEnableVertexAttribArray(attr.location);
		glVertexAttribPointer(
			attr.location,
			attr.numComponents,
			attr.type,
			attr.normalized,
			attr.vertexStride,
			(void*)attr.offset
		);
	}

	this->vertexCount = vertexCount;
	this->indicesCount = static_cast<GLsizei>(indexCount);

	glBindVertexArray(0);
}

VertexArray::~VertexArray()
{
	glDeleteBuffers(1, &VBO);
	glDeleteVertexArrays(1, &VAO);
	if (hasEBO)
		glDeleteBuffers(1, &EBO);
}

void VertexArray::Bind() const
{
	glBindVertexArray(VAO);
}

void VertexArray::Unbind() const
{
	glBindVertexArray(0);
}

void VertexArray::Draw()
{
	Bind();
	if (hasEBO)
		glDrawElements(GL_TRIANGLES, indicesCount, GL_UNSIGNED_INT, 0);
	else
		glDrawArrays(GL_TRIANGLES, 0, vertexCount);
}

