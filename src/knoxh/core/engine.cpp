#include <knoxh/core/engine.h>
#include <knoxh/core/window.h>

#include <knoxh/graphics/texture.h>

#include <iostream>

namespace knoxh
{
	void Engine::deleteTexture(void* ptr) {delete reinterpret_cast<Texture*>(ptr);}
	void Engine::deleteWindow(void* ptr) {delete reinterpret_cast<Window*>(ptr);}
}
