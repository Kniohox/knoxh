#include <knoxh/core/engine.h>

#include <iostream>

namespace knoxh
{
	Engine::~Engine()
	{

	}

	Engine::Engine(const int textureCap, const int fontCap, const int modelCap, const int shaderCap)
	{
		this->textureCap = textureCap;
		this->fontCap = fontCap;
		this->modelCap = modelCap;
		this->shaderCap = shaderCap;

		this->textureReg = new Registry(textureCap);
		this->fontReg = new Registry(fontCap);
		this->modelReg = new Registry(modelCap);
		this->shaderReg = new Registry(shaderCap);

		this->textureQueue = new Queue(textureCap);
		this->fontQueue = new Queue(fontCap);
		this->modelQueue = new Queue(modelCap);
		this->shaderQueue = new Queue(shaderCap);

		std::cout << std::endl << "Initializing new engine" << std::endl <<
		"-----------------------" << std::endl <<
		"Texture Cap = " << textureCap << std::endl <<
		"Font Cap    = " << fontCap << std::endl <<
		"Model Cap   = " << modelCap << std::endl <<
		"Shader Cap  = " << shaderCap << std::endl << std::endl;
	}
}
