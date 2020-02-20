#include <knoxh/core/engine.h>

#include <iostream>

namespace knoxh
{
	Engine::~Engine()
	{

	}

	Engine::Engine(const int textureCap, const int modelCap, const int shaderCap)
	{
		m_textureCap = textureCap;
		m_modelCap = modelCap;
		m_shaderCap = shaderCap;

		m_textureReg = new Registry(textureCap);
		m_modelReg = new Registry(modelCap);
		m_shaderReg = new Registry(shaderCap);

		m_textureQueue = new Queue(textureCap);
		m_modelQueue = new Queue(modelCap);
		m_shaderQueue = new Queue(shaderCap);

		m_textures = new Texture*[textureCap] {nullptr};

		std::cout << std::endl << "Initializing new engine" << std::endl <<
		"-----------------------" << std::endl <<
		"Texture Cap = " << m_textureCap << std::endl <<
		"Model Cap   = " << m_modelCap << std::endl <<
		"Shader Cap  = " << m_shaderCap << std::endl << std::endl;
	}
}
