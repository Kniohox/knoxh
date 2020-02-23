#pragma once

#ifndef GLEW_STATIC
#define GLEW_STATIC
#endif
#include <GL/glew.h>

#include <string>

namespace knoxh
{
	class Shader
	{
	private:
		unsigned int m_programID = 0;
		unsigned int m_vertexID = 0;
		unsigned int m_fragmentID = 0;

		std::string m_vertPath;
		std::string m_fragPath;

	protected:
		void loadShader(std::string path, unsigned int type);
		/*
		loads a shader with path "path" and type "type"
		sets the corresponding id to the shader id
		*/

		static unsigned int compileShader(const char* code, unsigned int type);
		/*
		compiles GLSL shader with code "code" and type "type"
		returns the shader id
		*/

		/*
		NO DEFAULT CODE, NEED AN OVERLOAD
		*/
		virtual void bindAttribs() = 0;
		virtual void bindFragmentData() = 0;
		virtual void bindSamplers() = 0;
		virtual void getUniformLocations() = 0;

	public:

		virtual ~Shader();
		/*
		deletes the shaders and shader program
		*/

		Shader(std::string vertPath, std::string fragPath);
		/*
		sets m_vertPath to "vertPath" and m_fragPath to "fragPath"
		*/

		void init();
		/*
		loads the vertex shader and fragment shader
		*/

		void bind();
		/*
		binds the shader program
		*/

		static void unbind();
		/*
		unbinds the current shader program
		*/
	};
}
