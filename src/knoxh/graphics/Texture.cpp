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
		glDeleteTextures(1, &m_id);
	}

	Texture::Texture(char* pixels, const unsigned short width, const unsigned short heigth)
	{

	}

	Texture::Texture(ImageData image)
	{
		if (image.data == nullptr)
		{
			return;
		}
		glGenTextures(1, &m_id);
		int imageType;
		int dataType;
		switch(image.components)
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

		glTexImage2D(GL_TEXTURE_2D, 0, dataType, image.width, image.height, 0, imageType, GL_UNSIGNED_BYTE, image.data);

		glBindTexture(GL_TEXTURE_2D, 0);
		stbi_image_free(image.data);
	}
}
