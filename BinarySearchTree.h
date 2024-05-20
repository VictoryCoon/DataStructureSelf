#pragma once
#include <iostream>

using namespace std;

template<typename T>
class BinarySearchTree
{
private:
	struct Node
	{
		T data;
		Node* pNode;
		Node* lNode;
		Node* rNode;
	};
	Node* root;
public:
	BinarySearchTree()
	{
	};
	~BinarySearchTree()
	{
	};
	void Insert(T _data);
	void Insert(Node* _node, T _data);
	void Clear();
	void InOrder();
	void PreOrder();
	void PostOrder();
	void InOrder(Node* _node);
	void PreOrder(Node* _node);
	void PostOrder(Node* _node);
};

template<typename T>
inline void BinarySearchTree<T>::Insert(T _data)
{
	if (nullptr == root)
	{
		root = new Node();
		root->data = _data;
		return;
	}
	else
	{
		Insert(root, _data);
	}
}

template<typename T>
inline void BinarySearchTree<T>::Insert(Node* _node, T _data)
{
	if (_node->data == _data) {
		return;
	}

	if (_node->data > _data)
	{
		if (_node->lNode == nullptr)
		{
			Node* addNode = new Node();
			addNode->data = _data;
			addNode->pNode = _node;
			_node->lNode = addNode;
		}
		else
		{
			Insert(_node->lNode, _data);
		}
	}
	else if (_node->data < _data)
	{
		if (_node->rNode == nullptr)
		{
			Node* addNode = new Node();
			addNode->data = _data;
			addNode->pNode = _node;
			_node->rNode = addNode;
		}
		else
		{
			Insert(_node->rNode, _data);
		}
	}
}

template<typename T>
inline void BinarySearchTree<T>::InOrder()
{
	InOrder(root);
}

template<typename T>
inline void BinarySearchTree<T>::PreOrder()
{
	PreOrder(root);
}

template<typename T>
inline void BinarySearchTree<T>::PostOrder()
{
	PostOrder(root);
}

template<typename T>
inline void BinarySearchTree<T>::InOrder(Node* _node)
{
	if (nullptr != _node)
	{
		InOrder(_node->lNode);
		cout << _node->data << " ";
		InOrder(_node->rNode);
	}
}

template<typename T>
inline void BinarySearchTree<T>::PreOrder(Node* _node)
{
	if (nullptr != _node)
	{
		PreOrder(_node->lNode);
		PreOrder(_node->rNode);
		cout << _node->data << " ";
	}
}

template<typename T>
inline void BinarySearchTree<T>::PostOrder(Node* _node)
{
	if (nullptr != _node)
	{
		cout << _node->data << " ";
		PostOrder(_node->lNode);
		PostOrder(_node->rNode);
	}
}
