#pragma once

#include<glad/glad.h>

class EBO
{
public:
	GLuint ID;
	EBO(GLuint* indices, GLsizeiptr size);
	EBO() : ID(0) {}

	void Bind();
	void Unbind();
	void Delete();
};













