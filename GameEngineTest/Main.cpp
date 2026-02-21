#include "EngineBase.h"

int main()
{
	Window::InitWindow(800, 600, "OpenGL Engine");

	Renderer::StartOfFunc();

	std::vector<VertexArray::VertexAttribute> layout = {
		{0, 3, GL_FLOAT, GL_FALSE, 0}
	};

	ShaderManager::loadShader("shader", "defaultShader.vs", "defaultShader.fs", "");
	Shader* shader = ShaderManager::GetShader("shader");

	float vertices[] = {
		// Position
		 0.5f, -0.5f,  0.0f,
		-0.5f, -0.5f,  0.0f,
		 0.0f,  0.5f,  0.0f
	};


	VertexArray mesh(vertices, sizeof(vertices), layout, 3, nullptr, 0, GL_STATIC_DRAW);

	while (!glfwWindowShouldClose(Window::handle))
	{
		Renderer::BeginFrame();

		// Renderer::DrawScene(scene) make something like this

		shader->Activate();
		mesh.Draw(layout);

		Renderer::EndFrame();
	}

	Cleanup::CleanupAll();

	return 0;
}