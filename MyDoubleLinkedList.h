#pragma once

template<typename T>
class MyDoubleLinkedList
{
private:
	struct Node
	{
		T data;
		Node* next;
		Node* prev;
	};
	Node* head;
	Node* tail;
public:
	MyDoubleLinkedList()
	{
		head = new Node();
		tail = new Node();
		head->next = tail;
		tail->prev = head;
	}
	~MyDoubleLinkedList()
	{
		Clear();
		delete head;
		delete tail;
	}
public:
	void PushFront(T _in);
	void PushBack(T _in);
	bool PopFront();
	bool PopBack();
	bool IsEmpty();
	void Clear();
	//T GetHead();
	//T GetTail();
};

template<typename T>
inline void MyDoubleLinkedList<T>::PushFront(T _in)
{
	Node* addNode = new Node();
	addNode->data = _in;
	addNode->next = head->next;
	addNode->prev = head;
	head->next = addNode;
	addNode->next->prev = addNode;
}

template<typename T>
inline bool MyDoubleLinkedList<T>::PopFront()
{
	if (IsEmpty())
	{
		return false;
	}
	else
	{
		head->next->next->prev = head;
		head->next = head->next->next;
		return true;
	}
}

template<typename T>
inline void MyDoubleLinkedList<T>::PushBack(T _in)
{
	Node* addNode = new Node();
	addNode->data = _in;
	addNode->prev = tail->prev;
	addNode->next = tail;
	tail->prev = addNode;
	addNode->prev->next = addNode;
}

template<typename T>
inline bool MyDoubleLinkedList<T>::PopBack()
{
	if (IsEmpty())
	{
		return false;
	}
	else
	{
		tail->prev->prev->next = tail;
		tail->prev = tail->prev->prev;
		return true;
	}
}

template<typename T>
inline bool MyDoubleLinkedList<T>::IsEmpty()
{
	return head->next == tail;
}

template<typename T>
inline void MyDoubleLinkedList<T>::Clear()
{
	while (!IsEmpty())
	{
		PopFront();
	}
}

/*
template<typename T>
inline T MyDoubleLinkedList<T>::GetHead()
{
	return head->next->data;
}

template<typename T>
inline T MyDoubleLinkedList<T>::GetTail()
{
	return tail->prev->data;
}
*/
