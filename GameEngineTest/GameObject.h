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

	void SetPosition(glm::vec3 pos) { position = pos; isDirty = true; };
	void SetScale(glm::vec3 size) { scale = size; isDirty = true; };
	void SetRotation(glm::vec3 rot) { rotation = rot; isDirty = true; };

	void Draw(Shader* shader)
	{
		if (isDirty)
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

			isDirty = false;
		}

		// Draw the mesh
		if (mesh)
			mesh->Draw();
	}

private:
	bool isDirty = true;
};