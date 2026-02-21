#include "ShaderManager.h"
#include <iostream>

ShaderManager sm;

void ShaderManager::loadShader(const std::string& name, 
	const std::string& vertex, 
	const std::string& fragment, 
	const std::string& geometry)
{

	// okay now this is pretty self explanatory. if its not past the end (shaders.end()) its already there!
	if (sm.shaders.find(name) != sm.shaders.end()) 
	{
		std::cout << "Shader " << name << " already loaded in!" << std::endl;
		return;
	}

	// now we create our new shader. how shadery!

	Shader* shader;
	if (geometry.empty())
		shader = new Shader(vertex.c_str(), fragment.c_str(), nullptr);
	else
		shader = new Shader(vertex.c_str(), fragment.c_str(), geometry.c_str());

	// and now we store it here
	sm.shaders[name] = shader;
}

Shader* ShaderManager::GetShader(const std::string& name)
{
	// now we are going backwards! basically, we grab the shaders name and if it is not past the end, we know its there
	// also markas, second is the second part of the thingy. so: key : value. the value is second
	auto it = sm.shaders.find(name);
	if (it != sm.shaders.end())
		return it->second;

	// well its not found. return.
	std::cout << "SHADER NOT FOUND!" << std::endl;
	return nullptr;
}

// we clean up once we are done with the shaders. typically at the end of something.
void ShaderManager::cleanUp()
{
	// now the & after auto just means that we are accessing the actual hashmap data. NOT a variable in of its self with its own data. 
	// actaully thats wrong BUT you get what i mean.
	for (auto& pair : sm.shaders)
		delete pair.second; // self explanatory

	// anddddd we clear all of the shaders of data! done!
	sm.shaders.clear();
}