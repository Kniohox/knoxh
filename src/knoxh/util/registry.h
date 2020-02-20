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

		void clear();
		/*
		sets all locations as free
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
}
