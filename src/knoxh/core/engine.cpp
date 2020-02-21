#include <knoxh/core/engine.h>
#include <knoxh/core/window.h>

#include <knoxh/util/voidregistry.h>
#include <knoxh/util/queue.h>

#include <knoxh/graphics/texture.h>

#include <iostream>

namespace knoxh
{

	void deleteTexture(void* ptr) {delete reinterpret_cast<Texture*>(ptr);}
	void deleteWindow(void* ptr) {delete reinterpret_cast<Window*>(ptr);}

	Engine::~Engine()
	{
		delete m_queue;
		delete m_registry;
	}

	Engine::Engine(const int size)
	{
		m_queue = new Queue(size);
		m_registry = new VoidRegistry(size, 16);
		m_typeid_texture = m_registry->addType(&deleteTexture);
		m_typeid_window = m_registry->addType(&deleteWindow);
	}

	void Engine::deleteItem(const int id)
	{
		m_registry->safeDeleteItem(id);
	}

	void Engine::deleteItems(const int* ids, const int size)
	{
		for (int i = 0; i < size; i++)
		{
			deleteItem(ids[i]);
		}
	}

}
