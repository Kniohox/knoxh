#include <knoxh/core/engine.h>

#include <iostream>

namespace knoxh
{
	Engine::~Engine()
	{

	}

	Engine::Engine(const int mode)
	{
		this->mode = mode;
	}

	void Engine::init()
	{
		//spaghetti inbound
		if (this->mode&1 == Engine::CLIENT)
		{
			if (this->model>>1&1 == Engine::UNLIMITED_TICK_RATE>>1)
			{
				
			}
			else //this->mode>>1&1 == Engine::LIMITED_TICK_RATE>>1
			{

			}
		}
		else //this->mode&1 == Engine::SERVER
		{
			if (this->mode>>1&1 == Engine::UNLIMITED_TICK_RATE>>1)
			{

			}
			else //this->mode>>1&1 == Engine::LIMITED_TICK_RATE>>1
			{

			}
		}
	}
}
