#pragma once

#include <knoxh/core/window.h>

#include <knoxh/util/funclib.h>
#include <knoxh/util/registry.h>

namespace knoxh
{
	class Engine
	{
	private:
		Window* window;
		Registry* textureReg;
		Registry* modelReg;
		Registry* shaderReg;
		int mode;

	public:
		~Engine();
		Engine(const int mode);

		static const int CLIENT = 0;
		//glfw window
		static const int SERVER = 1;
		//no glfw window, no render function called

		static const int LIMITED_TICK_RATE = 0;
		//capped tick rate
		static const int UNLIMITED_TICK_RATE = 2;
		//no cap on tick rate
	};
}
