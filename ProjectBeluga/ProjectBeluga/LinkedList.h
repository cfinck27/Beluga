#ifndef RING_BUFFER_H
#define RING_BUFFER_H

#include "Node.h"

template <class T>
class LinkedList
{

protected:

	int size;

	Node<T>* head;
	Node<T>* tail;

public:

	LinkedList()
	{
		size = 0;
	}

	virtual ~LinkedList()
	{
		Node<T>* next;
		while (head != NULL)
		{
			next = head->getNext();
			delete head;
			head = next;
		}
	}

	void addFront(T* data)
	{
		Node<T>* node = new Node<T>(data);

		if (head)
		{
			node->setNext(head);
			head = node;
		}
		else
		{
			head = node;
			tail = node;
		}

		size++;
	}

	void addBack(T* data)
	{
		Node<T>* node = new Node<T>(data);
		
		if (tail)
		{
			tail->setNext(node);
			tail = node;
		}
		else if (head)
		{
			head->setNext(node);
			tail = node;
		}
		else
		{
			head = node;
			tail = node;
		}

		size++;
	}

	T* get(int pos)
	{
		if (!head)
			return NULL;

		Node<T>* cur = head;
		for (int i = 0; i < pos; i++)
		{
			cur = cur->getNext();

			if (!cur)
				return NULL;
		}

		return cur->getData();
	}

	T* getFirst()
	{
		return head->getData();
	}

	T* getLast()
	{
		return tail->getData();
	}

	int getSize()
	{
		return size;
	}

	bool remove(int pos)
	{
		if (!head)
			return false;

		Node<T>* cur = head;
		Node<T>* prev = NULL;
		for (int i = 0; i < pos; i++)
		{
			prev = cur;
			cur = cur->getNext();

			if (!cur)
				return false;
		}

		prev->setNext(cur->getNext());
		delete cur;

		size--;

		return true;
	}

	bool removeFirst()
	{
		if (!head)
			return false;

		Node<T>* next = head->getNext();
		delete head;
		head = next;

		size--;

		return true;
	}

	bool removeLast()
	{
		if (!tail)
			return false;

		Node<T>* cur = head;
		while (cur->getNext() != tail)
		{
			cur = cur->getNext();
		}

		cur->setNext(NULL);
		delete tail;
		tail = cur;

		size--;

		return true;
	}

};

#endif