#pragma once

namespace knoxh
{
	class Mesh
	{
	private:
		unsigned int id;
	public:
		~Mesh();
		Mesh(const int pCount);
		Mesh(const int pCount, int* indices, int indiceCount);
		Mesh(const int pCount, int* indices, int indiceCount, float** data, int dataSize);

		void startLoad(int* indices, int indiceCount);
		void loadProperty(float* data, int dataSize);
		void endLoad();
	};
}
