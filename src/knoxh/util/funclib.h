#pragma once

#include <string>

namespace knoxh
{
	void error_callback(int error, const char* description);
	/*
	not my method, will probably replace soon
	*/

	struct ImageData
	{
		int width;
		int height;
		int components;
		unsigned char* data = nullptr;
	};

	ImageData loadImage(std::string path);
}
