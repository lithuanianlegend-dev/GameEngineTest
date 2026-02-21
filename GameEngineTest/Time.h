#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "window.h"
#include <string>


class Time
{
private:
	// variabling variables!
	float lastFrame = 0.0f;
	float deltaTime = 0.0f;


	double prevTime = 0.0f;
	double curTime = 0.0f;
	double timeDiff;

	unsigned int counter = 0;

public:


	static float getDeltaTime();

	//methods that are liteerally in the name
	static void Update();

	static void MeasureFramesPerSecond();
};