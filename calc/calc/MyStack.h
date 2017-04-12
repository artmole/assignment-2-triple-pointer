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
			max_size *= 2;
			m_elems = (T*)realloc(m_elems, max_size * sizeof(T));
		}
		m_elems[m_size - 1] = arg;
	}
	T Pop()
	{
		m_size--;
		T out = m_elems[m_size];
		if (m_size < max_size*0.4)
		{
			max_size /= 2;
			m_elems = (T*)realloc(m_elems, max_size * sizeof(T));
		}
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