#pragma once

#include <knoxh/util/funclib.h>

namespace knoxh
{
	class Texture
	{
	private:
		unsigned int m_id;
	public:
		virtual ~Texture();
		Texture(char* pixels, const unsigned short width, const unsigned short height);
		Texture(ImageData image);
	};
}
