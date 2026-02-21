#include "EngineBase.h"

int main()
{
	Window::InitWindow(800, 600, "OpenGL Engine");

	Renderer::StartOfFunc();

	std::vector<VertexArray::VertexAttribute> layout = {
		{0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float)},
		{1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float)}
	};

	ShaderManager::loadShader("shader", "defaultShader.vs", "defaultShader.fs", "");
	Shader* shader = ShaderManager::GetShader("shader");


	float vertices[] = {
		// Position			 // Tex coords
		 0.5f, -0.5f,  0.0f, 1.0f, 0.0f,
		-0.5f, -0.5f,  0.0f, 0.0f, 0.0f,
		 0.0f,  0.5f,  0.0f, 0.5f, 1.0f
	};

	VertexArray mesh(vertices, sizeof(vertices), layout, 3, nullptr, 0, GL_STATIC_DRAW);
	GLuint textureTest = TextureLoader::loadTexture("res/textures/cat.png");

	shader->Activate();
	shader->setInt("texture1", 0);


	GameObject triangle(&mesh);


	while (!glfwWindowShouldClose(Window::handle))
	{

		InputHandler::ProcessInput();

		Time::Update();
		Time::MeasureFramesPerSecond();

		Renderer::BeginFrame();

		// -----------------------------------------
		//			 TEST WILL REMOVE.
		// -----------------------------------------

		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, textureTest);

		float t_value = glfwGetTime();
		float value = sin(t_value / 2) + 0.5f;

		triangle.position = glm::vec3(value, 0.0f, 0.0f);
		triangle.scale = glm::vec3(value, value, value);

		triangle.Draw(shader);

		//-----------------------------------------------

		// Renderer::DrawScene(scene) make something like this

		Renderer::EndFrame();
	}

	Cleanup::CleanupAll();

	return 0;
}