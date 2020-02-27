#pragma once

#include <string>

namespace knoxh
{
	std::string loadFile(std::string path);

	void loadImage(std::string path, unsigned char*& data, int& w, int& h, int& components);

	void loadOBJ(std::string path, float*& vertices, float*& normals, float*& textureCoords, int& vertexCount, int*& indices, int& indiceCount)
}
