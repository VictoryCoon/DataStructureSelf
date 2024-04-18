#pragma once

template<typename T>
class MyQueue
{
private:
	T* data;
	int cnt;
	int maxSize;
public:
	T* buffer;
public:
	MyQueue()
		: data(nullptr)
		, cnt(0)
		, maxSize(2)
		, buffer{nullptr}
	{
		buffer = new T[maxSize];
	}
	~MyQueue()
	{
		delete[] buffer;
	}
public:
	bool Push(T _data);
	bool Pop();
	int Size();
	bool IsEmpty();
	T& GetHead();
	T& GetTail();
};

template<typename T>
inline bool MyQueue<T>::Push(T _data)
{
	if (maxSize < cnt)
	{
		maxSize *= 2;
		T* newBuffer = new T[maxSize];
		memcpy(newBuffer, buffer, sizeof(T) * cnt);
		delete[] buffer;
		buffer = newBuffer;
	}

	if (0 != cnt)
	{
		T* tempBuffer = new T[maxSize];
		memcpy(tempBuffer, &_data, sizeof(T));
		memcpy(++tempBuffer, buffer, sizeof(T) * cnt);
		--tempBuffer;
		delete[] buffer;
		buffer = tempBuffer;
		/*
		T* tempBuffer = new T[maxSize];
		memcpy(tempBuffer, buffer, sizeof(T) * cnt);
		memcpy(buffer, &_data, sizeof(T));
		memcpy(++buffer, tempBuffer, sizeof(T) * cnt);
		delete tempBuffer;
		*/
	}
	else
	{
		memcpy(buffer, &_data, sizeof(T));
	}

	++cnt;
	return true;
}

template<typename T>
inline bool MyQueue<T>::Pop()
{
	if (0 == cnt)
	{
		return false;
	}
	--cnt;
	return true;
}

template<typename T>
inline int MyQueue<T>::Size()
{
	return cnt;
}

template<typename T>
inline bool MyQueue<T>::IsEmpty()
{
	return cnt == 0 ? true : false;
}

template<typename T>
inline T& MyQueue<T>::GetHead()
{
	return buffer[cnt-1];
}

template<typename T>
inline T& MyQueue<T>::GetTail()
{
	return buffer[0];
}