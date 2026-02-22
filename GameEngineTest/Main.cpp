#include "EngineBase.h"

Camera camera;

int main()
{

	std::vector<VertexArray::VertexAttribute> layout = {
		{0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float)},
		{1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float)}
	};

	Window::InitWindow(800, 600, "OpenGL Engine");

	Renderer::Init();

	ShaderManager::loadShader("shader", "defaultShader.vs", "defaultShader.fs", "");
	Shader* shader = ShaderManager::GetShader("shader");


	float vertices[] = {
		-0.5f, -0.5f, -0.5f,  0.0f, 0.0f,
		 0.5f, -0.5f, -0.5f,  1.0f, 0.0f,
		 0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
		 0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
		-0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
		-0.5f, -0.5f, -0.5f,  0.0f, 0.0f,

		-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
		 0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
		 0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
		 0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
		-0.5f,  0.5f,  0.5f,  0.0f, 1.0f,
		-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,

		-0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
		-0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
		-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
		-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
		-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
		-0.5f,  0.5f,  0.5f,  1.0f, 0.0f,

		 0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
		 0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
		 0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
		 0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
		 0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
		 0.5f,  0.5f,  0.5f,  1.0f, 0.0f,

		-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
		 0.5f, -0.5f, -0.5f,  1.0f, 1.0f,
		 0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
		 0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
		-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
		-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,

		-0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
		 0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
		 0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
		 0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
		-0.5f,  0.5f,  0.5f,  0.0f, 0.0f,
		-0.5f,  0.5f, -0.5f,  0.0f, 1.0f
	};
	GLuint textureTest = TextureLoader::loadTexture("res/textures/guy.png");

	shader->Activate();
	shader->setInt("texture1", 0);

	glm::mat4 projection;
	projection = glm::perspective(glm::radians(45.0f), float(Window::s_width) / float(Window::s_height), 0.1f, 100.0f);

	Scene scene("TestScene", 1);
	Scene scene2("TestScene2", 2);

	std::shared_ptr<VertexArray> meshPtr(
		new VertexArray(vertices, sizeof(vertices), layout, 36, nullptr, 0, GL_STATIC_DRAW)
	);

	auto triangle = std::make_shared<GameObject>(meshPtr);
	auto triangle2 = std::make_shared<GameObject>(meshPtr);
	auto triangle3 = std::make_shared<GameObject>(meshPtr);

	triangle2->SetPosition(glm::vec3(0.0f, 0.0f, 3.0f));
	triangle3->SetPosition(glm::vec3(0.0f, 1.0f, 0.0f));

	scene.AddObjects({ triangle });
	scene2.AddObjects({ triangle2 });

	while (!glfwWindowShouldClose(Window::handle))
	{
		
		InputHandler::ProcessInput(camera);

		Time::Update();
		Time::MeasureFramesPerSecond();

		Renderer::BeginFrame();

		// -----------------------------------------
		//			 TEST WILL REMOVE.
		// -----------------------------------------



		if (glfwGetKey(Window::handle, GLFW_KEY_G) == GLFW_PRESS)
		{
			scene2.DrawScene(shader);
		}
		else
		{
			scene.DrawScene(shader);
		}

		glm::mat4 view = camera.GetViewMatrix();


		shader->setMat4("projection", projection);
		shader->setMat4("view", view);

		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, textureTest);

		float t_value = glfwGetTime();
		float value = sin(t_value / 2) + 0.5f;


		scene.DrawScene(shader);

		//-----------------------------------------------

		// Renderer::DrawScene(scene) make something like this

		Renderer::EndFrame();
	}

	Cleanup::CleanupAll();

	return 0;
}