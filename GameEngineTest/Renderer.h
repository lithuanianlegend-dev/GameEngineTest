#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "Window.h"
#include "Time.h"
#include "Input.h"

// peepeepoopoo

class Renderer
{
public:
	// when renderloop starts, do this.
	static void BeginFrame(); 

	// when renderloop ends, do this.
	static void EndFrame();

	static void StartOfFunc();

	static void Draw();
};