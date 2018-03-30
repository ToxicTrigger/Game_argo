#pragma once

class CkQ
{
private:
	int m_front;
	int m_tail;
	int m_max;
	int m_size;
	int * m_q;

public:
	CkQ(int max = 100)
	{
		m_front = 0;
		m_tail = 0;
		m_size = 0;
		m_max = max;
		m_q = new int[max];
	}

	bool isFull()
	{
		return m_size >= m_max;
	}
	bool isEmpty()
	{
		return m_size <= 0;
	}

	void enQ(int itme)
	{
		if (!isFull())
		{
			if (m_tail == m_max) m_tail = 0;
			m_q[m_tail++] = itme;
			m_size++;
		}
	}

	int getFront()
	{
		return m_q[m_front];
	}

	int deQ( )
	{
		int retVal;
		if (!isEmpty())
		{
				m_size--;
				retVal = m_q[m_front];
				m_front = (m_front + 1) % m_max;
				return retVal;
		}
		return -1;
	}
};