#pragma once

#include <assert.h>

template<typename T>
class MyStack
{
private:
	int cnt;
	int maxSize;
public:
	T* buffer;
public:
	MyStack()
		: cnt(0)
		, maxSize(2)
		, buffer(nullptr)
	{
		buffer = new T[maxSize];
	}
	~MyStack()
	{
		delete buffer;
	}
public:
	bool Push(T _data);
	T& Pop(void);
	bool IsEmpty(void);
	int Size(void);
	T& Toppick(void);
private:
	T& resize();
};

template<typename T>
inline bool MyStack<T>::Push(T _data)
{
	if(maxSize < cnt)
	{
		maxSize *= 2;
		T* newBuffer = new T[maxSize];
		memcpy(newBuffer, buffer, sizeof(T)*cnt);
		delete buffer;
		buffer = newBuffer;
	}
	
	buffer[cnt++] = _data;

	return true;
}

template<typename T>
inline T& MyStack<T>::Pop(void)
{
	return buffer[cnt--];
}

template<typename T>
inline bool MyStack<T>::IsEmpty(void)
{
	return cnt == 0 ? true : false;
}

template<typename T>
inline int MyStack<T>::Size(void)
{
	return cnt;
}

template<typename T>
inline T& MyStack<T>::Toppick(void)
{
	if (IsEmpty())
	{
		assert(nullptr);
	}
	return buffer[cnt-1];
}
