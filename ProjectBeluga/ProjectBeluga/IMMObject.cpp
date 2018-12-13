#include "IMMObject.h"

#include "BLog.h"

#include <iterator>

std::list<IMMObject*> IMMObject::liveObjects;
std::list<IMMObject*> IMMObject::deadObjects;

void IMMObject::collectGarbage()
{
	for (std::list<IMMObject*>::iterator it = deadObjects.begin();
			it != deadObjects.end(); it++)
	{
		delete (*it);
	}

	deadObjects.clear();
}

void IMMObject::collectRemainingObjects(bool bEmitWarnings)
{
	collectGarbage();
	for (std::list<IMMObject*>::iterator it = liveObjects.begin();
			it != liveObjects.end(); it++)
	{
		IMMObject *o = (*it);

		if (bEmitWarnings)
		{
			BLog::get().write(LOG_INFO, "Cleaning object at (%p)", o);
		}

		delete o;
	}

	liveObjects.clear();
}

IMMObject::IMMObject()
{
	liveObjects.push_back(this);

	refCount = 0;
}

IMMObject::~IMMObject()
{

}

void IMMObject::addRef()
{
	++refCount;
}

void IMMObject::release()
{
	--refCount;

	if (refCount <= 0)
	{
		liveObjects.remove(this);
		deadObjects.push_back(this);
	}
}