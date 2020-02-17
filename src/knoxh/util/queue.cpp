#include <knoxh/util/queue.h>

namespace knoxh
{
	Queue::~Queue()
	{
		delete[] m_data;
	}

	Queue::Queue(const int size)
	{
		m_data = new int[size];
		m_size = size;
		m_pushIndex = 0;
		m_popIndex = 0;
		m_full = false;
	}

	int Queue::getSize()
	{
		return m_size;
	}

	int Queue::queuedItems()
	{
		/*
		mmm
		spaghetti
		*/
		return m_full ? m_size : m_popIndex <= m_pushIndex ? m_pushIndex-m_popIndex : m_pushIndex+m_size-m_popIndex;
	}

	void Queue::getQueue(int*& queue, int& size)
	{
		size = queuedItems();
		delete[] queue;
		queue = new int[size];
		if (m_popIndex <= m_pushIndex && !m_full)
		{
			for (int i = m_popIndex; i < m_pushIndex; i++)
			{
				queue[i-m_popIndex] = m_data[i];
			}
		}
		else
		{
			for (int i = m_popIndex; i < m_size; i++)
			{
				queue[i-m_popIndex] = m_data[i];
			}
			for (int i = 0; i < m_pushIndex; i++)
			{
				queue[i+m_size-m_popIndex] = m_data[i];
			}
		}
	}

	bool Queue::isEmpty()
	{
		return m_full ? false : m_popIndex == m_pushIndex;
	}

	bool Queue::isFull()
	{
		return m_full;
	}

	bool Queue::push(const int item)
	{
		if (m_full)
		{
			//oh fuck, the queue is full
			return false;
		}
		m_data[m_pushIndex] = item;
		if (++m_pushIndex == m_size)
		{
			m_pushIndex = 0;
		}
		if (m_pushIndex == m_popIndex)
		{
			m_full = true;
		}
		return true;
	}

	int Queue::pop()
	{
		if (m_full)
		{
			m_full = false;
		}
		if (++m_popIndex == m_size)
		{
			m_popIndex = 0;
			return m_data[m_size-1];
		}
		return m_data[m_popIndex-1];
	}

	void Queue::expand(const int change)
	{
		/*
		no point in reusing the previous code in getQueue as it sets the array size to the amount of items in the queue
		may split it into several functions at some point to reduce code redundency
		*/
		int* narr = new int[m_size+change];
		if (m_popIndex <= m_pushIndex && !m_full)
		{
			for (int i = m_popIndex; i < m_pushIndex; i++)
			{
				narr[i-m_popIndex] = m_data[i];
			}
		}
		else
		{
			for (int i = m_popIndex; i < m_size; i++)
			{
				narr[i-m_popIndex] = m_data[i];
			}
			for (int i = 0; i < m_pushIndex; i++)
			{
				narr[i+m_size-m_popIndex] = m_data[i];
			}
		}

		m_pushIndex = queuedItems();
		delete[] m_data;
		m_data = narr;

		m_size+=change;
		m_popIndex = 0;
		m_full = false;
	}

	void Queue::reset(const int size)
	{
		delete[] m_data;
		m_data = new int[size];
		m_size = size;
		m_pushIndex = 0;
		m_popIndex = 0;
		m_full = false;
	}
}
