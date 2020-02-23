#include <knoxh/graphics/shader.h>
#include <knoxh/util/funclib.h>

#ifndef GLEW_STATIC
#define GLEW_STATIC
#endif
#include <GL/glew.h>

#include <string>
#include <iostream>

namespace knoxh
{
	void Shader::loadShader(std::string path, unsigned int type)
	{
		switch(type)
		{
		case GL_VERTEX_SHADER:
			m_vertexID = compileShader(loadFile(path).c_str(), GL_VERTEX_SHADER);
			break;
		case GL_FRAGMENT_SHADER:
			m_fragmentID = compileShader(loadFile(path).c_str(), GL_FRAGMENT_SHADER);
			break;
		}
	}

	unsigned int Shader::compileShader(const char* code, unsigned int type)
	{
		unsigned int id = glCreateShader(type);
		glShaderSource(id, 1, &code, NULL);
		glCompileShader(id);
		int* compileStatus;
		glGetShaderiv(id, GL_COMPILE_STATUS, compileStatus);
		if (*compileStatus == GL_FALSE)
		{
			char* infoLog = new char[1024];
			glGetShaderInfoLog(id, 1024, NULL, infoLog);
			fprintf(stderr, "Could not compile shader\n%s", infoLog);
			delete[] infoLog;
		}
		return id;
	}

	Shader::~Shader()
	{
		glUseProgram(0);
		glDetachShader(m_programID, m_vertexID);
		glDetachShader(m_programID, m_fragmentID);
		glDeleteShader(m_vertexID);
		glDeleteShader(m_fragmentID);
		glDeleteProgram(m_programID);
	}

	Shader::Shader(std::string vertPath, std::string fragPath)
	{
		m_vertPath = vertPath;
		m_fragPath = fragPath;
	}

	void Shader::init()
	{
		m_programID = glCreateProgram();
		loadShader(m_vertPath, GL_VERTEX_SHADER);
		glAttachShader(m_programID, m_vertexID);
		loadShader(m_fragPath, GL_FRAGMENT_SHADER);
		glAttachShader(m_programID, m_fragmentID);

		bindAttribs();
		bindFragmentData();

		glLinkProgram(m_programID);
		glValidateProgram(m_programID);

		getUniformLocations();
	}

	void Shader::bind()
	{
		glUseProgram(m_programID);
	}

	void Shader::unbind()
	{
		glUseProgram(0);
	}
}
