#include <knoxh/util/voidregistry.h>
#include <knoxh/util/registry.h>

#include <iostream>

namespace knoxh
{
	VoidRegistry::~VoidRegistry()
	{
		//no point in trying to deleting null pointers
		if (usedLocationCount() > 0)
		{
			destroy();
		}
	}

	VoidRegistry::VoidRegistry(const int size, const short typeCount)
	{
		m_size = size;
		m_index = size-1;

		m_data = new void*[size] {nullptr};
		m_type = new short[size] {-1};
		m_freeLocations = new int[size];
		for (int i = 0; i < size; i++)
		{
			m_freeLocations[i] = i;
		}

		m_callreg = new Registry(typeCount);
		m_delFunctions = new knoxh_delFunc[typeCount] {nullptr};
	}

	int VoidRegistry::addItem(void* item, const short type)
	{
		m_data[m_freeLocations[m_index]] = item;
		m_type[m_freeLocations[m_index]] = type;
		return m_freeLocations[m_index--];
	}

	int VoidRegistry::safeAddItem(void* item, const short type)
	{
		if (m_index == -1)
		{
			expand(m_size);
		}
		return addItem(item, type);
	}

	void* VoidRegistry::popItem(const int index)
	{
		m_freeLocations[++m_index] = index;
		return m_data[index];
	}

	void VoidRegistry::removeItem(const int index)
	{
		m_freeLocations[++m_index] = index;
		m_type[index] = -1;
		m_data[index] = nullptr;
	}

	void VoidRegistry::deleteItem(const int index)
	{
		m_delFunctions[m_type[index]](m_data[index]);
		removeItem(index);
	}

	void VoidRegistry::safeDeleteItem(const int index)
	{
		if (m_data[index] != nullptr)
		{
			deleteItem(index);
		}
	}

	void* VoidRegistry::getItem(const int index)
	{
		return m_data[index];
	}

	short VoidRegistry::getType(const int index)
	{
		return m_type[index];
	}

	void VoidRegistry::setType(const int index, const short type)
	{
		m_type[index] = type;
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
		for (int i = 0, j = 0; i < m_size && j < size; i++)
		{
			if (m_data[i] != nullptr)
			{
				locations[j++] = i;
			}
		}
	}

	short VoidRegistry::addType(const knoxh_delFunc function)
	{
		short id = (short)m_callreg->nextLocation();
		m_delFunctions[id] = function;
		return id;
	}

	short VoidRegistry::safeAddType(const knoxh_delFunc function)
	{
		if (m_callreg->freeLocationCount() == 0)
		{
			expandTypeCap(m_callreg->getSize());
		}
		return addType(function);
	}

	void VoidRegistry::removeType(const short index)
	{
		m_delFunctions[index] = nullptr;
	}

	void VoidRegistry::safeRemoveType(const short index)
	{
		for (int i = 0; i < m_size; i++)
		{
			if (m_type[i] == index)
			{
				deleteItem(i);
			}
		}
		m_delFunctions[index] = nullptr;
	}

	void VoidRegistry::removeAllTypes()
	{
		for (int i = 0; i < m_callreg->getSize(); i++)
		{
			m_delFunctions[i] = nullptr;
		}
		m_callreg->clear();
	}

	void VoidRegistry::expandTypeCap(const int change)
	{
		knoxh_delFunc* narr = new knoxh_delFunc[m_callreg->getSize()+change] {nullptr};
		for (int i = 0; i < m_callreg->getSize(); i++)
		{
			narr[i] = m_delFunctions[i];
		}
		delete[] m_delFunctions;
		m_delFunctions = narr;
		m_callreg->expand(change);
	}

	void VoidRegistry::deleteAll()
	{
		for (int i = 0; i < m_size; i++)
		{
			safeDeleteItem(i);
		}
	}

	void VoidRegistry::clear()
	{
		deleteAll();
		removeAllTypes();
	}

	void VoidRegistry::destroy()
	{
		deleteAll();
		delete[] m_data;
		delete[] m_freeLocations;
		delete[] m_type;
		delete[] m_delFunctions;
		delete m_callreg;
	}
}
