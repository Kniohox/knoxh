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
	void Shader::compileShader(unsigned int& id, const char* code, unsigned int type)
	{
		id = glCreateShader(type);
		glShaderSource(id, 1, &code, nullptr);
		glCompileShader(id);
		int compileStatus;
		glGetShaderiv(id, GL_COMPILE_STATUS, &compileStatus);
		if (compileStatus == GL_FALSE)
		{
			char* infoLog = new char[1024];
			glGetShaderInfoLog(id, 1024, NULL, infoLog);
			fprintf(stderr, "Could not compile shader\n%s", infoLog);
			delete[] infoLog;
		}
	}

	void Shader::bindAttrib(unsigned int index, const char* name)
	{
		glBindAttribLocation(m_programID, index, name);
	}

	void Shader::bindFragmentData(unsigned int index, const char* name)
	{
		glBindFragDataLocation(m_programID, index, name);
	}

	unsigned int Shader::getUniformLocation(const char* name)
	{
		return glGetUniformLocation(m_programID, name);
	}

	Shader::~Shader()
	{
		glUseProgram(0);
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

		compileShader(m_vertexID, loadFile(m_vertPath).c_str(), GL_VERTEX_SHADER);
		glAttachShader(m_programID, m_vertexID);
		compileShader(m_fragmentID, loadFile(m_fragPath).c_str(), GL_FRAGMENT_SHADER);
		glAttachShader(m_programID, m_fragmentID);

		bindAttribs();
		bindFragmentData();

		glLinkProgram(m_programID);
		glValidateProgram(m_programID);

		getUniformLocations();

		glDeleteShader(m_vertexID);
		glDeleteShader(m_fragmentID);
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
