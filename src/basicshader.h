#pragma once

#include <knoxh/graphics/shader.h>

class BasicShader : public knoxh::Shader
{
public:
	BasicShader();
	~BasicShader();
	void bindAttribs();
	void bindFragmentData();
	void bindSamplers(); //not used, no textures
	void getUniformLocations(); //not used, no uniforms
};
