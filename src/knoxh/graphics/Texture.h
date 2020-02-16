#pragma once

#include <knoxh/util/funclib.h>

namespace knoxh
{
	class Texture
	{
	private:
		unsigned int id;
	public:
		~Texture();
		Texture(char* pixels, const unsigned short width, const unsigned short height);
		Texture(ImageData image);
	};
}
