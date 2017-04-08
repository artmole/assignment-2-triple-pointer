#pragma once
#include <string.h>

template<class T> struct stack {
private: 
	int m_size = 0;
	T* m_elems = new T[0];
public:
	void push(T arg)
	{
		m_size++;
		T* new_elems = new T[m_size];
		memcpy(new_elems, m_elems, sizeof(T)*(m_size - 1));
		new_elems[m_size-1] = arg;
		m_elems = new T[m_size];
		memcpy(m_elems, new_elems, sizeof(T)*(m_size));
	}
	T pop()
	{
		m_size--;
		T out = m_elems[m_size];
		T* new_elems = new T[m_size];
		memcpy(new_elems, m_elems, sizeof(T)*(m_size));
		m_elems = new T[m_size];
		memcpy(m_elems, new_elems, sizeof(T)*(m_size));
		return out;
	}
	T back()
	{
		return m_elems[m_size-1];
	}
	T size()
	{
		return m_size;
	}
	void clear()
	{
		m_size = 0;
		m_elems = new T[0];
	}
};