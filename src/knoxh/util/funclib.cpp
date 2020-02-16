#include <iostream>
#include <string>
#include <filesystem>

#define STB_IMAGE_IMPLEMENTATION
#include <stb/stb_image.h>

#include <knoxh/util/funclib.h>

namespace knoxh
{
	void error_callback(int error, const char* description)
	{
	    fputs(description, stderr);
	    //_fgetchar();
	}

	ImageData loadImage(std::string path)
	{
		path.insert(0, std::filesystem::current_path().string()+="/");
		stbi_set_flip_vertically_on_load(true);

		ImageData image;
		image.data = stbi_load(path.c_str(), &image.width, &image.height, &image.components, 0);
		if (stbi_failure_reason())
		{
			std::cout << stbi_failure_reason() << std::endl;
		};

		//stbi_image_free(image.data);
		return image;
	}
}
