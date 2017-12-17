#pragma comment(lib, "opengl32")
#pragma comment(lib, "glew32s")
#pragma comment(lib, "glfw3dll")

#include "Graphics\Graphics.h"
#include "Graphics\Mesh.h"
#include "Graphics\Shader.h"
#include "Graphics\Texture.h"
#include "Graphics\Transform.h"
#include "Input.h"

std::string pressedKey = "";
Input &input = Input::GetInstance();

int main()
{
	Graphics graphics(800, 600, "Wings");

	glfwSetKeyCallback(graphics.window, input.Keyboard_Callback);
	glfwSetMouseButtonCallback(graphics.window, input.Mouse_Button_Callback);

	Vertex vertices[] = { Vertex(glm::vec2(0.0f, 0.5f), glm::vec2(0.0, 0.0)),
						  Vertex(glm::vec2(0.5f, 0.5f), glm::vec2(1.0, 0.0)),
						  Vertex(glm::vec2(0.0f, -0.5f), glm::vec2(0.0, 1.0)),
						  Vertex(glm::vec2(0.5f, -0.5f), glm::vec2(1.0, 1.0))};

	/*Vertex vertices[] = { Vertex(glm::vec2(10, 15), glm::vec2(0.0, 0.0)),
						  Vertex(glm::vec2(15, 15), glm::vec2(1.0, 0.0)),
						  Vertex(glm::vec2(10, 20), glm::vec2(0.0, 1.0)),
						  Vertex(glm::vec2(15, 20), glm::vec2(1.0, 1.0)) };*/

	Vertex vertices2[] = { Vertex(glm::vec2(0.5f, 1.0f), glm::vec2(0.0, 0.0)),
						Vertex(glm::vec2(1.0f, 1.0f), glm::vec2(1.0, 0.0)),
						Vertex(glm::vec2(0.5f, 0.5f), glm::vec2(0.0, 1.0)),
						Vertex(glm::vec2(1.0f, 0.5f), glm::vec2(1.0, 1.0)) };

	Mesh mesh(vertices, sizeof(vertices) / sizeof(vertices[0]));
	Shader shader("./Shaders/basicShader");
	Texture texture("./Textures/wingsiePNG.png");
	Texture texture2("./Textures/pattern1.png");
	Transform transform;

	Mesh mesh2(vertices2, sizeof(vertices2) / sizeof(vertices2[0]));

	float rotCounter = 0.0f;
	float counter = 0.0f;
	
	while (!glfwWindowShouldClose(graphics.window))
	{
		glfwPollEvents();

		graphics.Clear(1.0f, 0.5f, 0.75f, 0.0f);

		shader.Bind();
		texture.Bind(0);
		shader.Update(transform);
		mesh.Draw();
		texture2.Bind(0);
		shader.Update(transform);
		mesh2.Draw();
		graphics.Update();
		//transform.GetRot().y = rotCounter;
		//transform.SetScale(glm::vec3(cosf(counter), cosf(counter), cosf(counter)));
		
		
		if (1)
			transform.GetPos().y += 0.01f;
		else if (pressedKey == "down")
			transform.GetPos().y -= 0.01f;
		else if (pressedKey == "right")
			transform.GetPos().x += 0.01f;
		else if (pressedKey == "left")
			transform.GetPos().x -= 0.01f;
		/*else if (glfwGetKey(graphics.window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
			glfwSetWindowShouldClose(graphics.window, GL_TRUE);*/

		counter += 0.001f;
		rotCounter += 0.001f;

		if (pressedKey != "")
			std::cout << "'" << pressedKey << "'" << " has been pressed!\n";
	}

	return 0;
}