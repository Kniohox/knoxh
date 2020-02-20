#include <knoxh/core/engine.h>
#include <knoxh/graphics/texture.h>

#include <iostream>

namespace knoxh
{

	void deleteTexture(voit* ptr) {delete reinterpret_cast<Texture>(ptr);}

	Engine::~Engine()
	{
		delete m_registry;
	}

	Engine::Engine(const int size)
	{
		m_queue = new Queue(size);
		m_registry = new VoidRegistry(size, 16);
		m_typeid_texture = m_registry->addType(&deleteTexture);
	}
}
