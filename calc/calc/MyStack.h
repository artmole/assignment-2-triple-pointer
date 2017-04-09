#pragma once
#include <string.h>

template<class T> struct stack {
private: 
	int m_size = 0;
	T* m_elems;
	int max_size = 100;
public:
	stack(int maxSize = 100)
	{
		max_size = maxSize;
		m_elems = new T[max_size];
	}
	~stack()
	{
		delete m_elems, m_size;
	}
	void Push(T arg)
	{
		m_size++;
		if (m_size > max_size *0.8)
		{
			int new_size = sizeof(m_elems) / sizeof(T) * 2;
			T* new_elems = new T[new_size];
			memcpy(new_elems, m_elems, sizeof(T)*(m_size - 1));
			new_elems[m_size - 1] = arg;
			m_elems = new T[new_size];
			memcpy(m_elems, new_elems, sizeof(T)*(m_size));
		}
		m_elems[m_size - 1] = arg;
	}
	T Pop()
	{
		m_size--;
		T out = m_elems[m_size];
		/*if (m_size < max_size*0.4)
		{
			int new_size = sizeof(m_elems) / sizeof(T) / 2;			
			T* new_elems = new T[new_size];
			memcpy(new_elems, m_elems, sizeof(T)*(m_size));
			m_elems = new T[new_size];
			memcpy(m_elems, new_elems, sizeof(T)*(m_size));
		}*/
		return out;
	}
	T Back()
	{
		return m_elems[m_size-1];
	}
	T Size()
	{
		return m_size;
	}
	void Clear()
	{
		m_size = 0;
		m_elems = new T[100];
	}
};