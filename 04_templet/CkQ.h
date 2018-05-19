#pragma once

template <typename T>
class CkQ
{
private:
	int m_front;
	int m_tail;
	int m_max;
	int m_size;
	T* m_q;

public:
	CkQ(int max = 100)
	{
		m_front = 0;
		m_tail = 0;
		m_size = 0;
		m_max = max;
		m_q = new T[max];
	}

	bool isFull()
	{
		return m_size >= m_max;
	}
	bool isEmpty()
	{
		return m_size <= 0;
	}

	void enQ(T itme)
	{
		if (!isFull())
		{
			if (m_tail == m_max) m_tail = 0;
			m_q[m_tail++] = itme;
			m_size++;
		}
	}

	int get_max_size()
	{
		return m_max;
	}

	T getFront()
	{
		return m_q[m_front];
	}

	T deQ( )
	{
		T retVal;
		if (!isEmpty())
		{
				m_size--;
				retVal = m_q[m_front];
				m_front = (m_front + 1) % m_max;
				return retVal;
		}
		return T();
	}
};