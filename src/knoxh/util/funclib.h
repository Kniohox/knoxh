#pragma once

#include <string>

namespace knoxh
{
	std::string loadFile(std::string path);

	struct ImageData
	{
		int width;
		int height;
		int components;
		unsigned char* data = nullptr;
	};

	ImageData loadImage(std::string path);
}
