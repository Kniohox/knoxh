#include "basicshader.h"

#include <iostream>

BasicShader::~BasicShader()
{

}

BasicShader::BasicShader() : Shader("res/shaders/basicVertex.glsl", "res/shaders/basicFragment.glsl")
{
	//nothing here
}

void BasicShader::bindAttribs()
{
	Shader::bindAttrib(0, "vertex");
	Shader::bindAttrib(1, "color");
}

void BasicShader::bindFragmentData()
{
	Shader::bindFragmentData(0, "outColor");
}

void BasicShader::bindSamplers()
{
	//nothing here
	//texture samplers would be bound here if there were any in the shader
}

void BasicShader::getUniformLocations()
{
	//nothing here
	//uniform locations would be retrieved here if there were any in the shader
}
