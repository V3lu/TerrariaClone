#pragma once

#include<glad/glad.h>

class VBO
{
public:
	GLuint ID;
	VBO(GLfloat* vertices, GLsizeiptr size);
	VBO() : ID(0) {}

	void Bind();
	void Unbind();
	void Delete();
};













