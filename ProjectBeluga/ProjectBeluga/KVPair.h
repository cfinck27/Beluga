#ifndef KEY_VALUE_PAIR_H
#define KEY_VALUE_PAIR_H

template <class T, U>
class KVPair
{

protected:

	T* m_key;
	U* m_value;

public:

	KVPair(T* k, U* v)
	{
		m_key = k;
		m_value = v;
	}

	virtual ~KVPair()
	{
	}

	void setKey(T* k)
	{
		m_key = k;
	}

	T* getKey()
	{
		return m_key;
	}

	void setValue(U* v)
	{
		m_value = v;
	}

	U* getValue()
	{
		return m_value;
	}

};

#endif