#pragma once

#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "Window.h"
#include "glm.hpp"
#include "Time.h"
#include "Camera.h"
#include "Scene.h"

class InputHandler {
public:

	static void ProcessInput(Camera& camera);
};