#pragma once

#include "glad/glad.h"
#include "GLFW/glfw3.h"

#include <iostream>
#include <string>
#include <vector>
#include <memory>

#include "ShaderLoader.h"

#include "GameObject.h"

class Scene
{
protected:
	std::vector<std::shared_ptr<GameObject>> gameObjects;
public:
	std::string name;
	int buildIndex;

	Scene(std::string name, int buildIndex) : name(name), buildIndex(buildIndex) {}
	
	virtual void OnLoad() {}
	virtual void OnUnload() {}

	virtual void DrawScene(Shader* shader)
	{
		for (auto& obj : gameObjects)
		{
			obj->Draw(shader);
		}
	}

	// we add our objects to the scene!
	void AddObjects(std::vector<std::shared_ptr<GameObject>> objects)
	{
		for (auto obj : objects)
		{
			gameObjects.push_back(obj);
		}
	}

	void RemoveObject(std::shared_ptr<GameObject> obj)
	{
		gameObjects.erase(
			std::remove_if(gameObjects.begin(), gameObjects.end(),
				[&obj](const std::shared_ptr<GameObject>& o) {
					return o == obj;
				}),
			gameObjects.end()
		);
	}

	// If you want to remove multiple at once:
	void RemoveObjects(std::vector<std::shared_ptr<GameObject>> objects)
	{
		for (auto& obj : objects)
			RemoveObject(obj);
	}

	std::vector<std::shared_ptr<GameObject>>& GetObjects()
	{
		return gameObjects;
	}

};