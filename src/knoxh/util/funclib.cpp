#include <knoxh/util/funclib.h>

#define STB_IMAGE_IMPLEMENTATION
#include <stb/stb_image.h>

#include <iostream>
#include <string>
#include <filesystem>

namespace knoxh
{

	std::string loadFile(std::string path)
	{
		FILE* file = fopen(path.c_str(), "r");
		if (file != nullptr)
		{
			fseek(file, 0, SEEK_END);
			size_t size = ftell(file);

			std::string contents;
			contents.resize(size);

			rewind(file);
			fread(&contents[0], sizeof(char), size, file);

			fclose(file);
			return contents;
		}
		return NULL;
	}

	ImageData loadImage(std::string path)
	{

		ImageData image;

		std::cout << "Loading image at \"" << path << "\"" << std::endl;

		if (!std::filesystem::exists(std::filesystem::status(path)))
		{
			std::cout << "\\-Failed to load image\n\t->Error loading image: file does not exist" << std::endl;
			return image;
		}

		stbi_set_flip_vertically_on_load(true);
		image.data = stbi_load(path.c_str(), &image.width, &image.height, &image.components, 0);

		if (image.data != nullptr)
		{
			std::cout << "\\-Successfully loaded image" << std::endl;
		}
		else
		{
			std::cout << "\\-Failed to load image" << std::endl;
		}
		if (stbi_failure_reason())
		{
			std::cout << "\t->Error loading image: " << stbi_failure_reason() << std::endl;
		};

		return image;
	}
}
