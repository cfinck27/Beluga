#ifndef NODE_H
#define NODE_H

template <class T>
class Node
{

protected:

	T* m_data;
	Node<T>* m_next;

public:

	Node(T* data, Node<T>* next = 0)
	{
		m_data = data;
		m_next = next;
	}

	virtual ~Node()
	{
		// nothing to free
	}

	void setData(T* data)
	{
		m_data = data;
	}

	T* getData()
	{
		return m_data;
	}

	void setNext(Node<T>* next)
	{
		m_next = next;
	}

	Node<T>* getNext()
	{
		return m_next;
	}

};

#endif