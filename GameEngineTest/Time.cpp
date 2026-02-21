#include "Time.h"

Time timeH;

void Time::Update()
{
	float currentFrame = glfwGetTime(); // we get the current time
	timeH.deltaTime = currentFrame - timeH.lastFrame; // now we get delta time
	timeH.lastFrame = currentFrame; // tbh you can see whats going on!
}

void Time::MeasureFramesPerSecond()
{
	timeH.curTime = glfwGetTime(); // get cur time
	timeH.timeDiff = timeH.curTime - timeH.prevTime;
	timeH.counter++;
	if (timeH.timeDiff >= 0.25f) // we check if more than x amount of seconds has passed
	{
		// simple math from here!
		int FPS = (1.0f / timeH.timeDiff) * timeH.counter;
		int ms = (timeH.timeDiff / timeH.counter) * 1000;
		std::string newTitle = "LearnOpenGL - " + std::to_string(FPS) + "FPS / " + std::to_string(ms) + "ms";
		glfwSetWindowTitle(Window::handle, newTitle.c_str());
		timeH.prevTime = timeH.curTime;
		timeH.counter = 0;
	}
}

float Time::getDeltaTime()
{
	return timeH.deltaTime;
}