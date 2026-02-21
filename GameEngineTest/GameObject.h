#pragma once

#include <glad/glad.h>
#include <glfw/glfw3.h>
#include "mesh.h"

#include <glm.hpp>
#include <gtc/matrix_transform.hpp>

class GameObject
{
public:
	VertexArray* mesh;
	glm::vec3 position;
	glm::vec3 rotation;
	glm::vec3 scale;

	GameObject(VertexArray* m) : mesh(m), position(0.0f), rotation(0.0f), scale(1.0f) {}

	std::vector<VertexArray::VertexAttribute> layout = {
	{0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float)},
	{1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float)}
	};

	void Draw(Shader* shader)
	{
		glm::mat4 model = glm::mat4(1.0f);
		model = glm::translate(model, position);
		model = glm::rotate(model, glm::radians(rotation.x), glm::vec3(1, 0, 0));
		model = glm::rotate(model, glm::radians(rotation.y), glm::vec3(0, 1, 0));
		model = glm::rotate(model, glm::radians(rotation.z), glm::vec3(0, 0, 1));
		model = glm::scale(model, scale);

		shader->Activate();
		shader->setMat4("model", model);
		shader->setInt("texture1", 0);

		// Draw the mesh
		if (mesh)
			mesh->Draw(layout);
	}
};