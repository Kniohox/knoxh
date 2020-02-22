#pragma once

#include <knoxh/util/registry.h>

typedef void (*knoxh_delFunc)(void* item);

namespace knoxh
{
	/*
	semi-automatic resource management class
	*/
	class VoidRegistry
	{
	private:
		int m_size;
		//size of registry
		void** m_data;
		//array of items
		int* m_freeLocations;
		//array of free locations
		short* m_type;
		//array of data type ids for each item
		int m_index;
		//index of top of location stack

		Registry* m_callreg;
		//registry to keep track of callback functions
		knoxh_delFunc* m_delFunctions;
		//array of delete functions for each item type

	public:
		~VoidRegistry();
		/*
		deletes all items in the m_data array
		deletes all pointers
		no memory leak here boss
		*/

		VoidRegistry(const int size, const short typeCount);
		/*
		initialises arrays and m_index
		sets m_size to "size"
		initialises the callback registry with "typeCount" as the size
		*/

		int addItem(void* item, const short type);
		/*
		adds "item" to the next free location in m_data
		adds "type" to the same location in m_type
		returns the location in m_data
		*/

		int safeAddItem(void* item, const short type);
		/*
		doubles the VoidRegistry size if there are no more free locations
		adds "item" to the next free location in m_data
		adds "type" to the same location in m_type
		returns the location in m_data
		*/

		void replaceItem(const int index, void* item, const short type);
		/*
		sets the item at index "index" of m_data to "item"
		sets the type at index "index" of m_type to "type"
		*/

		bool safeReplaceItem(const int index, void* item, const short type);
		/*
		deletes the current item at index "index" of m_data
		if there is no existing item at the index "index" of m_data the function returns false
		if there was an existing item, setItem(index, item, type) is called
		*/

		void* popItem(const int index);
		/*
		returns the item at index "index" in m_data and removes it from the array
		adds "index" to the list of free locations
		*/

		void removeItem(const int index);
		/*
		removes the item at index "index" in m_data
		adds "index" to the list of free locations
		*/

		void deleteItem(const int index);
		/*
		removes the item at index "index" in m_data
		deletes the item using the specified function in m_delFunctions pointed to by m_type
		adds "index" to the list of free locations
		*/

		void safeDeleteItem(const int index);
		/*
		calls deleteItem(index) if m_data[index] != nullptr
		*/

		void* getItem(const int index);
		/*
		returns the item at index "index" in m_data
		*/

		short getType(const int index);
		/*
		returns the type of the item at index "index" in m_data (m_type[index])
		*/

		void setType(const int index, const short type);
		/*
		sets the type of the item at index "index" in m_data to "type"
		*/

		void expand(const int change);
		/*
		increases the size of the VoidRegistry by "change"
		*/

		int getSize();
		/*
		returns the VoidRegistry size
		*/

		int freeLocationCount();
		/*
		returns the number of free locations
		*/

		void getFreeLocations(int**& locations, int*& size);
		/*
		sets "locations" to the memory address of m_freeLocations
		sets "size" to the memory address of index
		*/

		void getFreeLocations(int*& locations, int& size);
		/*
		sets "locations" to an array of the free locations
		sets "size" to the size of the array
		*/

		int usedLocationCount();
		/*
		returns the number of used locations
		*/

		void getUsedLocations(int*& locations, int& size);
		/*
		sets "locations" to an array of the used locations
		sets "size" to the size of the array
		should be used sparingly
		*/

		short addType(const knoxh_delFunc function);
		/*
		adds "function" to the next free location in m_delFunctions
		returns the index of "function" in the array
		*/

		short safeAddType(const knoxh_delFunc function);
		/*
		doubles the size of the
		*/

		void removeType(const short index);
		/*
		removes the function in m_delFunctions at the index "index"
		*/

		void safeRemoveType(const short index);
		/*
		deletes all elements in m_data with the type id "index"
		removes the function in m_delFunctions at the index "index"
		*/

		void removeAllTypes();
		/*
		removes all types from the VoidRegistry
		m_delFunctions becomes filled with nullptr
		*/

		void expandTypeCap(const int change);
		/*
		increases the size of the m_delFunctions array and m_callreg by "change"
		*/

		int getTypeSize();
		/*
		returns the size of m_callreg
		*/

		int freeTypeCount();
		/*
		returns the number of free locations in m_callreg
		*/

		int usedTypeCount();
		/*
		returns the number of used locations in m_callreg
		*/

		void deleteAll();
		/*
		deletes all elements in m_data
		*/

		void clear();
		/*
		calls deleteAll() and removeAllTypes()
		*/

		void destroy();
		/*
		deletes all pointers and arrays in the VoidRegistry
		*/

	};
}
