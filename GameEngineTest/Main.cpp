#include "EngineBase.h"


int main()
{
	Window::InitWindow(800, 600, "Why am i doing this?");

	std::vector<VertexArray::VertexAttribute> layout = {
		{0, 3, GL_FLOAT, GL_FALSE, 0}
	};

	ShaderManager::loadShader("shader", "defaultShader.vs", "defaultShader.fs", " ");
	Shader* shader = ShaderManager::GetShader("shader");

	float vertices[] = {
		// Position
		 0.5f, -0.5f,  0.0f,
		-0.5f, -0.5f,  0.0f,
		 0.0f,  0.5f,  0.0f
	};


	VertexArray mesh(vertices, sizeof(vertices), layout, nullptr, 0, GL_STATIC_DRAW);

	while (!glfwWindowShouldClose(Window::handle))
	{
		Renderer::BeginFrame();

		shader->Activate();

		mesh.Bind();
		glDrawArrays(GL_TRIANGLES, 0, 3);
		mesh.Unbind();

		Renderer::EndFrame();
	}

	Cleanup::CleanupAll();

	return 0;
}