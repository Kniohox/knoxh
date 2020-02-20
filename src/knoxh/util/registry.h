#pragma once

namespace knoxh
{
	/*
	class for id-ing items in an array
	*/
	class Registry
	{
	private:
		int m_size;
		//size of freeLocations array
		int* m_freeLocations;
		//array of available locations, acts as a stack
		int m_index;
		//index of top of location stack
	public:
		~Registry();
		/*
		deconstructor, deletes freeLocations array
		*/

		Registry(const int size);
		/*
		constructor, initialises variables
		*/


		int nextLocation();
		/*
		gets the next free location
		*/

		void freeLocation(const int index);
		/*
		adds "index" as an available free location
		*/

		int getSize();
		/*
		returns m_size
		*/

		void expand(const int change);
		/*
		increases the size of the Registry by "change"
		*/

		void reset(const int size);
		/*
		resets the registry, with a new size "size"
		*/

		void getFreeLocations(int**& locations, int*& size);
		/*
		sets pointer "array" to the memory address of m_freeLocations
		sets pointer "size" to the memory address of m_index
		*/

		void getFreeLocations(int*& locations, int& size);
		/*
		sets "locations" to an array of the free free locations
		sets "size" to the size of the array
		*/

		int freeLocationCount();
		/*
		returns the number of free locations
		*/

		int usedLocationCount();
		/*
		returns the number of used locations
		*/
	};

	/*
	VOID REGISTRY
	*/

	/*
	class for storing items and id-ing them
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
		unsigned char* m_type;
		//array of data type ids for each item
		int m_index;
		//index of top of location stack
	public:
		~VoidRegistry();
		/*
		deletes m_data array, m_type array, and m_freeLocations array
		does not delete pointers in m_data array
		deletion of elements must manually be done outside of VoidRegistry
		*/

		VoidRegistry(const int size);
		/*
		initialises arrays and m_index
		sets m_size to "size"
		*/

		int addItem(void* item, const unsigned char type);
		/*
		adds "item" to the next free location in m_data
		adds "type" to the same location in m_type
		returns the location in m_data
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

		void* getItem(const int index);
		/*
		returns the item at index "index" in m_data
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

	};
}
