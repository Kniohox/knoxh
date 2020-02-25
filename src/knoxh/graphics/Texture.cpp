#include <stb/stb_image.h>

#ifndef GLEW_STATIC
#define GLEW_STATIC
#endif
#include <GL/glew.h>

#include <knoxh/graphics/texture.h>
#include <knoxh/util/funclib.h>

#include <iostream>

namespace knoxh
{
	Texture::~Texture()
	{
		std::cout << "Deleting texture at " << this << std::endl;
		glDeleteTextures(1, &m_id);
	}

	Texture::Texture(unsigned char* pixels, int width, int height, int components)
	{
		init(pixels, width, height, components);
	}

	Texture::Texture(std::string path)
	{
		int width, height, components;
		unsigned char* pixels;

		loadImage(path, pixels, width, height, components);
		init(pixels, width, height, components);
	}
	void Texture::init(unsigned char* pixels, int width, int height, int components)
	{
		if (pixels == nullptr)
		{
			return;
		}

		glGenTextures(1, &m_id);
		int imageType;
		int dataType;

		switch(components)
		{
		case 1:
			imageType = GL_RED;
			dataType = GL_R8;
			break;
		case 2:
			imageType = GL_RG;
			dataType = GL_RG8;
			break;
		case 3:
			imageType = GL_RGB;
			dataType = GL_RGB8;
			break;
		case 4:
			imageType = GL_RGBA;
			dataType = GL_RGBA8;
			break;
		}

		glBindTexture(GL_TEXTURE_2D, m_id);

		glTexImage2D(GL_TEXTURE_2D, 0, dataType, width, height, 0, imageType, GL_UNSIGNED_BYTE, pixels);

		glBindTexture(GL_TEXTURE_2D, 0);
		stbi_image_free(pixels);
	}
}
