#ifndef BTYPES_H
#define BTYPES_H

#include <iostream>
#include <cstring>

typedef __int8	INT8;
typedef __int16	INT16;
typedef __int32	INT32;
typedef __int64	INT64;

typedef unsigned __int8		UINT8;
typedef unsigned __int16	UINT16;
typedef unsigned __int32	UINT32;
typedef unsigned __int64	UINT64;

typedef char	CHAR;
typedef wchar_t	WCHAR;

template <class T>
class BaseString
{

protected:

	T* m_szRaw;
	UINT32 m_size;

public:

	template <class U>
	static UINT32 size(U* cstring)
	{
		UINT32 size = 0;
		for (U* i = cstring; *i; i++)
		{
			size++;
		}
		return size + 1;
	}

	template <class U>
	static UINT32 length(U* cstring)
	{
		UINT32 length = 0;
		for (U* i = cstring; *i; i++)
		{
			length++;
		}
		return length;
	}

	BaseString()
	{
		m_szRaw = 0;
	}

	BaseString(T* cstring)
	{
		m_size = size(cstring);
		m_szRaw = new T[m_size];
		std::memcpy(m_szRaw, cstring, m_size * sizeof(T));
		m_szRaw[m_size - 1] = 0;
	}

	virtual ~BaseString()
	{
		if (m_szRaw)
		{
			delete m_szRaw;
		}
	}

	virtual T* cstring()
	{
		T* out = new T[m_size];
		std::memcpy(out, m_szRaw, m_size);
		return out;
	}

};

#endif