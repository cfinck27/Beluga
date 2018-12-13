#ifndef IMM_OBJECT_H
#define IMM_OBJECT_H

#include <list>

class IMMObject
{

private:

	static std::list<IMMObject*> liveObjects;
	static std::list<IMMObject*> deadObjects;

	long refCount;

protected:

	IMMObject();
	virtual ~IMMObject();

public:

	void addRef();
	void release();

	static void collectGarbage();
	static void collectRemainingObjects(bool bEmitWarnings);

};

#endif