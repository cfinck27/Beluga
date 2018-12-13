#ifndef CMM_POINTER_H
#define CMM_POINTER_H

#include "IMMObject.h"

#include <cassert>
#include <type_traits>

template <class T>
class CMMPointer
{
	
	static_assert(std::is_base_of<IMMObject, T>::value, "Tried to make MMPointer without MMObject");

protected:

	T* obj;

public:

	CMMPointer()
	{
		obj = 0;
	}

	CMMPointer(T* o)
	{
		obj = 0;
		*this = o;
	}

	CMMPointer(const CMMPointer<T>& p)
	{
		obj = 0;
		*this = p;
	}

	virtual ~CMMPointer()
	{
		if (obj)
		{
			obj->release();
		}
	}

	inline CMMPointer<T>& operator=(T* o)
	{
		if (obj)
		{
			obj->release();
		}
		obj = o;
		if (obj)
		{
			obj->addRef();
		}

		return *this;
	}

	inline CMMPointer<T>& operator=(const CMMPointer<T>& p)
	{
		if (obj)
		{
			obj->release();
		}
		obj = p.obj;
		if (obj)
		{
			obj->addRef();
		}

		return *this;
	}

	inline T& operator*() const
	{
		assert(obj != 0 && "Tried to * on a NULL smart pointer");
		return *obj;
	}

	inline T* operator->() const
	{
		assert(obj != 0 && "Tried to -> on a NULL smart pointer");
		return obj;
	}

	inline operator T*() const
	{
		return obj;
	}

	inline bool isValid() const
	{
		return (obj != 0);
	}

	inline bool operator!()
	{
		return !(obj);
	}

	inline bool operator==(const CMMPointer<T>& p) const
	{
		return (obj == p.obj);
	}

	inline bool operator==(const T* o) const
	{
		return (obj == o);
	}

};

#endif