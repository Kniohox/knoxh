#include "basicshader.h"

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
}

void BasicShader::getUniformLocations()
{
	//nothing here
}
