#include <knoxh/graphics/legacymesh.h>

#ifndef GLEW_STATIC
#define GLEW_STATIC
#endif
#include <GL/glew.h>

namespace knoxh
{
	LegacyMesh::~LegacyMesh()
	{
		destroy();
	}

	void LegacyMesh::destroy()
	{
		glDeleteBuffers(m_vboCount, m_vboIDs);
		delete[] m_vboIDs;
		glDeleteVertexArrays(1, &m_vaoID);
	}

	LegacyMesh::LegacyMesh(const unsigned int pCount)
	{
		m_vboCount = pCount+1;
		m_vboIDs = new unsigned int[m_vboCount];
	}

	void LegacyMesh::startLoad(const unsigned int* indices, const unsigned int indiceCount)
	{
		m_indiceCount = indiceCount;
		glGenVertexArrays(1, &m_vaoID);
		glBindVertexArray(&m_vaoID);
		glGenBuffers(m_vboCount, m_vboIDs);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_vboIDs[0]);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, indiceCount, indices, GL_STATIC_DRAW);
	}

	void LegacyMesh::loadProperty(const float* data, const unsigned int dataSize, const unsigned char index, const int dimensions)
	{
		glBindBuffer(GL_ARRAY_BUFFER, m_vboIDs[index+1]);
		glBufferData(GL_ARRAY_BUFFER, dataSize, data, GL_STATIC_DRAW);
		glVertexAttribPointer(index, dimensions, GL_FLOAT, false, dataSize * sizeof(unsigned int), 0);
	}

	void LegacyMesh::endLoad()
	{
		glBindBuffer(GL_ARRAY_BUFFER, 0);
		glBindVertexArray(0);
	}

	unsigned int LegacyMesh::getIndiceVboID()
	{
		return m_vboIDs[0];
	}

	unsigned int* LegacyMesh::getIndiceVBO()
	{
		return m_vboIDs;
	}

	unsigned int LegacyMesh::getIndiceCount()
	{
		return m_indiceCount;
	}

	unsigned int LegacyMesh::getVaoID()
	{
		return m_vaoID;
	}

	unsigned int* LegacyMesh::getVAO()
	{
		return &m_vaoID;
	}
}
