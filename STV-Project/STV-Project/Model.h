#pragma once
#include "MemoryListener.h"
#include "Dependencies\glew\glew.h"
#include "Dependencies\freeglut\freeglut.h"

class Model
{
public:
	Model(GLuint VAO, unsigned int indices_size) : 
		_vao(VAO), 
		_indices_size(indices_size) 
	{};

	GLuint polygon_mode = GL_FILL;
	GLuint getVAO() { return _vao; }
	unsigned int getIndiceCount() { return _indices_size;  }

private:
	GLuint _vao;
	unsigned int _indices_size;
};

