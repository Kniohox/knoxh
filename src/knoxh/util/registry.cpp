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

	void Registry::clear()
	{
		m_index = m_size-1;
		for (int i = 0; i < m_size; i++)
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

}
