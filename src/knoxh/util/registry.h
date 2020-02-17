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
		//index of top of stack
	public:
		~Registry();
		/*
		deconstructor, deletes freeLocations array
		*/

		Registry(const int size);
		/*
		deconstructor, initialises variables
		*/


		int nextLocation();
		/*
		gets the next free location
		*/

		void freeLocation(const int index);
		/*
		adds index as an available free location
		*/

		int getSize();
		/*
		returns size
		*/

		void expand(const int change);
		/*
		increases the size of the possible locations by change, adds change free locations
		*/

		void reset(const int size);
		/*
		resets the registry, with a new size
		*/

		void getFreeLocations(int**& array, int*& size);
		/*
		sets pointer array to the memory address of freeLocations
		sets pointer size to the memory address of index
		*/

		int freeLocationCount();
		/*
		returns the amount of free locations
		*/

		int usedLocationCount();
		/*
		returns the amount of used locations
		*/
	};
}
