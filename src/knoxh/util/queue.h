#pragma once

namespace knoxh
{
	/*
	Name of class is self explanitory as to what its role is
	*/
	class Queue
	{
	private:
		int* data;
		//queue

		int size;
		//size of queue

		int pushIndex;
		//index of next item to be added

		int popIndex;
		//index of the next item to be removed

		bool full;
		//keeping track of if the queue is full
		//popIndex == pushIndex can be full queue or empty queue

	public:
		~Queue();
		/*
		delete data array
		*/

		Queue(const int size);
		/*
		create queue with size size
		*/

		int getSize();
		/*
		returns the queue size
		*/

		int queuedItems();
		/*
		returns the amount of items in the queue
		*/

		void getQueue(int*& queue, int& size);
		/*
		returns and array of the queued items
		*/

		bool isEmpty();
		/*
		returns if whether or not the queue is full
		*/

		bool isFull();
		/*
		returns if the queue is full
		*/

		bool push(const int item);
		/*
		add an item to the queue
		returns if the attempt was successful
		*/

		int pop();
		/*
		get oldest item in queue
		*/

		void expand(const int change);
		/*
		increase queue size by changes
		performace for this functions suffers as queue order has to be maintained
		*/

		void reset(const int size);
		/*
		clears the queue and sets the size
		*/

	};
}
