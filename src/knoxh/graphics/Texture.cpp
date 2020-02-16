#include <stb/stb_image.h>

//#include <GLFW/glfw3.h>
//#include <GL/glext.h>
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
		std::cout << "Deleting OpenGL texture with id " << this->id << std::endl;
		glDeleteTextures(1, &this->id);
	}

	Texture::Texture(char* pixels, const unsigned short width, const unsigned short heigth)
	{

	}

	Texture::Texture(ImageData image)
	{
		glGenTextures(1, &this->id);
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

		glBindTexture(GL_TEXTURE_2D, this->id);

		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, image.width, image.height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image.data);

		glBindTexture(GL_TEXTURE_2D, 0);

		stbi_image_free(image.data);
	}
}
