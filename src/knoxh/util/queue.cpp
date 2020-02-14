#include <knoxh/util/queue.h>

namespace knoxh
{
	Queue::~Queue()
	{
		delete[] this->data;
	}

	Queue::Queue(const int size)
	{
		this->data = new int[size];
		this->size = size;
		this-> pushIndex = 0;
		this->popIndex = 0;
		this->full = false;
	}

	int Queue::getSize()
	{
		return this->size;
	}

	int Queue::queuedItems()
	{
		/*
		mmm
		spaghetti
		*/
		return this->full ? this->size : this->popIndex <= this->pushIndex ? this->pushIndex-this->popIndex : this->pushIndex+this->size-this->popIndex;
	}

	void Queue::getQueue(int*& queue, int& size)
	{
		size = this->queuedItems();
		delete[] queue;
		queue = new int[size];
		if (this->popIndex <= this->pushIndex && !this->full)
		{
			for (int i = this->popIndex; i < this->pushIndex; i++)
			{
				queue[i-this->popIndex] = this->data[i];
			}
		}
		else
		{
			for (int i = this->popIndex; i < this->size; i++)
			{
				queue[i-this->popIndex] = this->data[i];
			}
			for (int i = 0; i < this->pushIndex; i++)
			{
				queue[i+this->size-this->popIndex] = this->data[i];
			}
		}
	}

	bool Queue::isEmpty()
	{
		return this->full ? false : this->popIndex == this->pushIndex;
	}

	bool Queue::isFull()
	{
		return this->full;
	}

	bool Queue::push(const int item)
	{
		if (this->full)
		{
			//oh fuck, the queue is full
			return false;
		}
		this->data[this->pushIndex] = item;
		if (++this->pushIndex == this->size)
		{
			this->pushIndex = 0;
		}
		if (this->pushIndex == this->popIndex)
		{
			this->full = true;
		}
		return true;
	}

	int Queue::pop()
	{
		if (this->full)
		{
			this->full = false;
		}
		if (++this->popIndex == this->size)
		{
			this->popIndex = 0;
			return this->data[this->size-1];
		}
		return this->data[this->popIndex-1];
	}

	void Queue::expand(const int change)
	{
		/*
		no point in reusing the previous code in getQueue as it sets the array size to the amount of items in the queue
		may split it into several functions at some point to reduce code redundency
		*/
		int* narr = new int[this->size+change];
		if (this->popIndex <= this->pushIndex && !this->full)
		{
			for (int i = this->popIndex; i < this->pushIndex; i++)
			{
				narr[i-this->popIndex] = this->data[i];
			}
		}
		else
		{
			for (int i = this->popIndex; i < this->size; i++)
			{
				narr[i-this->popIndex] = this->data[i];
			}
			for (int i = 0; i < this->pushIndex; i++)
			{
				narr[i+this->size-this->popIndex] = this->data[i];
			}
		}

		this->pushIndex = this->queuedItems();
		delete[] this->data;
		this->data = narr;

		this->size+=change;
		this->popIndex = 0;
		this->full = false;
	}

	void Queue::reset(const int size)
	{
		delete[] this->data;
		this->data = new int[size];
		this->size = size;
		this->pushIndex = 0;
		this->popIndex = 0;
		this->full = false;
	}
}
