#pragma once

#include <glad/glad.h>
#include <glfw/glfw3.h>
#include "VertexArray.h"
#include <memory>

#include <glm.hpp>
#include <gtc/matrix_transform.hpp>

class GameObject
{

public:
	std::shared_ptr<VertexArray> mesh;
	glm::vec3 position;
	glm::vec3 rotation;
	glm::vec3 scale;

	GameObject(std::shared_ptr<VertexArray> m) : mesh(m), position(0.0f), rotation(0.0f), scale(1.0f) {}

	void SetPosition(glm::vec3 pos) { position = pos; isDirty = true; };
	void SetScale(glm::vec3 size) { scale = size; isDirty = true; };
	void SetRotation(glm::vec3 rot) { rotation = rot; isDirty = true; };

	void Draw(Shader* shader)
	{
		if (isDirty)
		{
			cachedModel = glm::mat4(1.0f);
			cachedModel = glm::translate(cachedModel, position);
			cachedModel = glm::rotate(cachedModel, glm::radians(rotation.x), glm::vec3(1, 0, 0));
			cachedModel = glm::rotate(cachedModel, glm::radians(rotation.y), glm::vec3(0, 1, 0));
			cachedModel = glm::rotate(cachedModel, glm::radians(rotation.z), glm::vec3(0, 0, 1));
			cachedModel = glm::scale(cachedModel, scale);

			shader->Activate();

			shader->setInt("texture1", 0);

			isDirty = false;
		}

		shader->setMat4("model", cachedModel);

		// Draw the mesh
		if (mesh)
			mesh->Draw();
	}

private:
	glm::mat4 cachedModel = glm::mat4(1.0f);
	bool isDirty = true;
};