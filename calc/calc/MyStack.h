#pragma once
#include <string.h>

struct stack {
private: 
	int m_size = 0;
	int* m_elems = new int[0];
public:
	void push(int arg)
	{
		m_size++;
		int* new_elems = new int[m_size];
		memcpy(new_elems, m_elems, sizeof(int)*(m_size - 1));
		new_elems[m_size-1] = arg;
		m_elems = new int[m_size];
		memcpy(m_elems, new_elems, sizeof(int)*(m_size));
	}
	int pop()
	{
		m_size--;
		int out = m_elems[m_size];		
		int* new_elems = new int[m_size];
		memcpy(new_elems, m_elems, sizeof(int)*(m_size));
		m_elems = new int[m_size];
		memcpy(m_elems, new_elems, sizeof(int)*(m_size));
		return out;
	}
	int back()
	{
		return m_elems[m_size-1];
	}
	int size()
	{
		return m_size;
	}
	void clear()
	{
		m_size = 0;
		m_elems = new int[0];
	}
};