#pragma once

template<typename T>
class MyLinkedList
{
private:
	struct Node
	{
		T data;
		Node* next;
	};
public:
	MyLinkedList()
	{
		head = new Node();
		head->next = nullptr;
	}
	~MyLinkedList()
	{
		Clear();
		delete[] head;
	}
public:
	void Push(T _data);
	bool Pop();
	bool IsEmpty();
	bool Clear();
private:
	Node* head;
};

template<typename T>
inline void MyLinkedList<T>::Push(T _data)
{
	Node* addNode = new Node();
	addNode->data = _data;
	Node* originNode = head->next;
	addNode->next = originNode;
	head->next = addNode;
}

template<typename T>
inline bool MyLinkedList<T>::Pop()
{
	if (IsEmpty())
	{
		return false;
	}
	Node* popNode = head->next;
	head->next = popNode->next;

	return true;
}

template<typename T>
inline bool MyLinkedList<T>::IsEmpty()
{	
	return head->next == nullptr ? true : false;
}

template<typename T>
inline bool MyLinkedList<T>::Clear()
{
	if (IsEmpty())
	{
		return false;
	}
	Node* clearNode = head->next;
	while (clearNode != nullptr) {
		head->next = clearNode = clearNode->next;
	}
	return true;
}
