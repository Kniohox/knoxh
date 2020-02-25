#pragma once

#include <string>

namespace knoxh
{
	class Texture
	{
	private:
		unsigned int m_id;
		void init(unsigned char* pixels, int width, int height, int components);
	public:
		virtual ~Texture();
		Texture(unsigned char* pixels, int width, int height, int components);
		Texture(std::string path);
	};
}
