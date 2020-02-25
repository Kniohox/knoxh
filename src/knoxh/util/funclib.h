#pragma once

#include <string>

namespace knoxh
{
	std::string loadFile(std::string path);

	void loadImage(std::string path, unsigned char*& data, int& w, int& h, int& components);
}
