#include <knoxh/util/registry.h>

namespace knoxh
{
	Registry::~Registry()
	{
		delete[] this->freeLocations;
	}

	Registry::Registry(const int size)
	{
		this->size = size;
		this->index = size-1;
		this->freeLocations = new int[size];
		for (int i = 0; i < size; i++)
		{
			freeLocations[i] = i;
		}
	}

	int Registry::nextLocation()
	{
		return this->freeLocations[this->index--];
	}

	void Registry::freeLocation(const int index)
	{
		this->freeLocations[++this->index] = index;
	}

	int Registry::getSize()
	{
		return this->size;
	}

	void Registry::expand(const int change)
	{
		int* narr = new int[this->size+change];
		for (int i = 0; i < change; i++)
		{
			narr[i] = this->size+i;
		}
		for (int i = 0; i <= this->index; i++)
		{
			narr[i+change] = this->freeLocations[i];
		}
		this->index+=change;
		this->size+=change;
		delete[] this->freeLocations;
		this->freeLocations = narr;
	}

	void Registry::reset(const int size)
	{
		delete[] this->freeLocations;
		this->size = size;
		this->index = size-1;
		this->freeLocations = new int[size];
		for (int i = 0; i < size; i++)
		{
			freeLocations[i] = i;
		}
	}

	void Registry::getFreeLocations(int**& array, int*& size)
	{
		array = &this->freeLocations;
		size = &this->index;
	}

	int Registry::freeLocationCount()
	{
		return this->index+1;
	}

	int Registry::usedLocationCount()
	{
		return this->size-this->index-1;
	}
}
