#pragma once

namespace knoxh
{
	/*
	OpenGL 3.0 compatable mesh
	*/
	class LegacyMesh
	{
	private:
		unsigned int m_vaoID;
		unsigned int m_indiceCount;
		unsigned int* m_vboIDs;
		unsigned char m_vboCount;
	public:
		~LegacyMesh();
		LegacyMesh(const unsigned char pCount);
		LegacyMesh(const unsigned char pCount, const unsigned int* indices, const unsigned int indiceCount);
		LegacyMesh(const unsigned char pCount, const unsigned int* indices, const unsigned int indiceCount, const float** data, const unsigned int dataSize);
		void destroy();

		void startLoad(const unsigned int* indices, const unsigned int indiceCount);
		void loadProperty(const float* data, const unsigned int dataSize, const unsigned char index);
		void endLoad();

		unsigned int getIndiceVboID();
		unsigned int* getIndiceVBO();
		unsigned int getIndiceCount();
		unsigned int getVaoID();
		unsigned int* getVAO();
	};
}
