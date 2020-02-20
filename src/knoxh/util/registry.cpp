#include <knoxh/util/registry.h>
#include <iostream>

namespace knoxh
{
	Registry::~Registry()
	{
		delete[] m_freeLocations;
	}

	Registry::Registry(const int size)
	{
		m_size = size;
		m_index = size-1;
		m_freeLocations = new int[size];
		for (int i = 0; i < size; i++)
		{
			m_freeLocations[i] = i;
		}
	}

	int Registry::nextLocation()
	{
		return m_freeLocations[m_index--];
	}

	void Registry::freeLocation(const int index)
	{
		m_freeLocations[++m_index] = index;
	}

	int Registry::getSize()
	{
		return m_size;
	}

	void Registry::expand(const int change)
	{
		int* narr = new int[m_size+change];
		for (int i = 0; i < change; i++)
		{
			narr[i] = m_size+i;
		}
		for (int i = 0; i <= m_index; i++)
		{
			narr[i+change] = m_freeLocations[i];
		}
		m_index+=change;
		m_size+=change;
		delete[] m_freeLocations;
		m_freeLocations = narr;
	}

	void Registry::reset(const int size)
	{
		delete[] m_freeLocations;
		m_size = size;
		m_index = size-1;
		m_freeLocations = new int[size];
		for (int i = 0; i < size; i++)
		{
			m_freeLocations[i] = i;
		}
	}

	void Registry::getFreeLocations(int**& locations, int*& size)
	{
		locations = &m_freeLocations;
		size = &m_index;
	}

	void Registry::getFreeLocations(int*& locations, int& size)
	{
		size = m_index+1;
		if (locations != nullptr)
		{
			delete[] locations;
		}
		if (size == 0)
		{
			locations = nullptr;
			return;
		}
		locations = new int[size];
		for (int i = 0; i < size; i++)
		{
			locations[i] = m_freeLocations[i];
		}
	}

	int Registry::freeLocationCount()
	{
		return m_index+1;
	}

	int Registry::usedLocationCount()
	{
		return m_size-m_index-1;
	}

	/*
	VOID REGISTRY
	*/

	VoidRegistry::~VoidRegistry()
	{
		delete[] m_data;
		delete[] m_freeLocations;
		delete[] m_type;
	}

	VoidRegistry::VoidRegistry(const int size)
	{
		m_size = size;
		m_index = size-1;
		m_data = new void*[size] {nullptr};
		m_type = new unsigned char[size];
		m_freeLocations = new int[size];
		for (int i = 0; i < size; i++)
		{
			m_freeLocations[i] = i;
		}
	}

	int VoidRegistry::addItem(void* item, const unsigned char type)
	{
		m_data[m_freeLocations[m_index]] = item;
		m_type[m_freeLocations[m_index]] = type;
		return m_freeLocations[m_index--];
	}

	void* VoidRegistry::popItem(const int index)
	{
		m_freeLocations[++m_index] = index;
		return m_data[index];
	}

	void VoidRegistry::removeItem(const int index)
	{
		m_freeLocations[++m_index] = index;
	}

	void* VoidRegistry::getItem(const int index)
	{
		return m_data[index];
	}

	void VoidRegistry::expand(const int change)
	{
		int* nfl = new int[m_size+change];
		void** ndt = new void*[m_size+change] {nullptr};
		for (int i = 0; i < change; i++)
		{
			nfl[i] = m_size+i;
		}
		for (int i = 0; i <= m_index; i++)
		{
			nfl[i+change] = m_freeLocations[i];
		}
		for (int i = 0; i < m_size; i++)
		{
			ndt[i] = m_data[i];
		}
		m_index+=change;
		m_size+=change;
		delete[] m_freeLocations;
		delete[] m_data;
		m_freeLocations = nfl;
		m_data = ndt;
	}

	int VoidRegistry::getSize()
	{
		return m_size;
	}

	int VoidRegistry::freeLocationCount()
	{
		return m_index+1;
	}

	void VoidRegistry::getFreeLocations(int**& locations, int*& size)
	{
		locations = &m_freeLocations;
		size = &m_size;
	}

	void VoidRegistry::getFreeLocations(int*& locations, int& size)
	{
		size = m_index+1;
		if (locations != nullptr)
		{
			delete[] locations;
		}
		if (size == 0)
		{
			locations = nullptr;
			return;
		}
		locations = new int[size];
		for (int i = 0; i < size; i++)
		{
			locations[i] = m_freeLocations[i];
		}
	}

	int VoidRegistry::usedLocationCount()
	{
		return m_size-m_index-1;
	}

	void VoidRegistry::getUsedLocations(int*& locations, int& size)
	{
		size = m_size-m_index-1;
		if (locations != nullptr)
		{
			delete[] locations;
		}
		if (size == 0)
		{
			locations = nullptr;
			return;
		}
		locations = new int[size];
		if (size == m_size)
		{
			for (int i = 0; i < m_size; i++)
			{
				locations[i] = i;
			}
		}
		for (int i = 0, j = 0; i < m_size && j < size; i++)
		{
			for (int k = 0; k <= m_index; k++)
			{
				if (i == m_freeLocations[k])
				{
					break;
				}
				if (k == m_index)
				{
					locations[j++] = i;
				}
			}
		}
	}

}
