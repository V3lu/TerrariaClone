#include<iostream>
#include<glad/glad.h>
#include<SFML/Window.hpp>
#include<SFML/Graphics.hpp>
#include<string>
#include<vector>

#include "ShaderClass.h"
#include "VBO.h"
#include "VAO.h"
#include "EBO.h"
#include "Game.h"

using namespace std;

//Vertices coordinates
GLfloat vertices[] =
{
	//   COORDINATES           COLORS
	-0.5f, -0.5f, 0.0f,   0.8f, 0.3f,  0.02f, //Lower left corner
	0.5f,  -0.5f, 0.0f,	  0.8f, 0.3f,  0.02f, //Lower right corner
	0.0f,  0.5f,  0.0f,   1.0f, 0.3f,  0.32f,    //Upper corner
	-0.5f, 0.5f,  0.0f,   0.9f, 0.45f, 0.17f,  //Inner left
	0.5f,  0.5f,  0.0f,   0.9f, 0.45f, 0.17f,   //Inner right
	0.0f,  -0.5f, 0.0f,   0.8f, 0.3f,  0.02f  //Inner bottom
};

GLuint indices[] =
{
	0, 3, 4,   //Lower left triangle
	4, 1, 0,   //Lower right triangle
};

void APIENTRY glDebugOutput(GLenum source,
	GLenum type,
	unsigned int id,
	GLenum severity,
	GLsizei length,
	const char* message,
	const void* userParam)
{
	// ignore non-significant error/warning codes
	if (id == 131169 || id == 131185 || id == 131218 || id == 131204) return;

	std::cout << "---------------" << std::endl;
	std::cout << "Debug message (" << id << "): " << message << std::endl;

	switch (source)
	{
	case GL_DEBUG_SOURCE_API:             std::cout << "Source: API"; break;
	case GL_DEBUG_SOURCE_WINDOW_SYSTEM:   std::cout << "Source: Window System"; break;
	case GL_DEBUG_SOURCE_SHADER_COMPILER: std::cout << "Source: Shader Compiler"; break;
	case GL_DEBUG_SOURCE_THIRD_PARTY:     std::cout << "Source: Third Party"; break;
	case GL_DEBUG_SOURCE_APPLICATION:     std::cout << "Source: Application"; break;
	case GL_DEBUG_SOURCE_OTHER:           std::cout << "Source: Other"; break;
	} std::cout << std::endl;

	switch (type)
	{
	case GL_DEBUG_TYPE_ERROR:               std::cout << "Type: Error"; break;
	case GL_DEBUG_TYPE_DEPRECATED_BEHAVIOR: std::cout << "Type: Deprecated Behaviour"; break;
	case GL_DEBUG_TYPE_UNDEFINED_BEHAVIOR:  std::cout << "Type: Undefined Behaviour"; break;
	case GL_DEBUG_TYPE_PORTABILITY:         std::cout << "Type: Portability"; break;
	case GL_DEBUG_TYPE_PERFORMANCE:         std::cout << "Type: Performance"; break;
	case GL_DEBUG_TYPE_MARKER:              std::cout << "Type: Marker"; break;
	case GL_DEBUG_TYPE_PUSH_GROUP:          std::cout << "Type: Push Group"; break;
	case GL_DEBUG_TYPE_POP_GROUP:           std::cout << "Type: Pop Group"; break;
	case GL_DEBUG_TYPE_OTHER:               std::cout << "Type: Other"; break;
	} std::cout << std::endl;

	switch (severity)
	{
	case GL_DEBUG_SEVERITY_HIGH:         std::cout << "Severity: high"; break;
	case GL_DEBUG_SEVERITY_MEDIUM:       std::cout << "Severity: medium"; break;
	case GL_DEBUG_SEVERITY_LOW:          std::cout << "Severity: low"; break;
	case GL_DEBUG_SEVERITY_NOTIFICATION: std::cout << "Severity: notification"; break;
	} std::cout << std::endl;
	std::cout << std::endl;
}

int main()
{
	sf::RenderWindow window(sf::VideoMode({ 1200, 800 }), "Terraria clone", sf::Style::Close);

	//Load GLAD so it configures OpenGL
	gladLoadGL();
	gladLoadGLLoader((GLADloadproc)sf::Context::getFunction);

	glViewport(0, 0, 1200, 800);

	Shader shaderProgram("default.vert", "default.frag");

	VAO VAO1;
	VAO1.Bind();

	VBO VBO1(vertices, sizeof(vertices));
	EBO EBO1(indices, sizeof(indices));

	VAO1.LinkAttrib(VBO1, 0, 3, GL_FLOAT, 6 * sizeof(float), (void*)0);
	VAO1.LinkAttrib(VBO1, 1, 3, GL_FLOAT, 6 * sizeof(float), (void*)(3 * sizeof(float)));

	VAO1.Unbind();
	VBO1.Unbind();
	EBO1.Unbind();

	Game game;
	game.InitializeGame(20);
	game.state = LOAD;

	while (window.isOpen()) 
	{
		while (const std::optional event = window.pollEvent())
		{
			// "close requested" event: we close the window
			if (event -> is<sf::Event::Closed>())
				window.close();
		}
		window.clear();
		glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		shaderProgram.Activate();
		glBindTexture(GL_TEXTURE_2D, texID);
		VAO1.Bind();

		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
		window.display();
	}

	VAO1.Delete();
	VBO1.Delete();
	EBO1.Delete();
	shaderProgram.Delete();

	return 0;
}