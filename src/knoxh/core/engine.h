#pragma once

#include <knoxh/core/window.h>

#include <knoxh/util/funclib.h>
#include <knoxh/util/registry.h>

namespace knoxh
{
	/*
	class for managing resources
	*/
	class Engine
	{
	private:
		Window* window;
		//Window to be used
		Registry* textureReg;
		//registry for textures
		Registry* modelReg;
		//registry for models
		Registry* shaderReg;
		//registry for shaders

	public:
		~Engine();

		Engine();

	};
}
