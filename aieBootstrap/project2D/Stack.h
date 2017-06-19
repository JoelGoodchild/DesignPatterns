#pragma once
#include "DynamicArray.h"

template <typename T>
class Stack
{
public:

	Stack(){}
	~Stack(){}

	bool empty()
	{
		return s.empty();
	}
	
	int size()
	{
		return s.size();
	}

	void push(T value)
	{
		s.pushBack(value);
	}

	T pop()
	{
		return s.popBack();
	}

	T top()
	{
		return s.back();
	}

	void Clear()
	{
		s.Clear();
	}

	dynamicArray<T> s;
};