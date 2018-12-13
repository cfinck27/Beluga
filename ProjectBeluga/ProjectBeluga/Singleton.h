#ifndef SINGLETON_H
#define SINGLETON_H

//https://www.gamedev.net/articles/programming/general-and-gameplay-programming/enginuity-part-ii-r1954/

template <class T>
class Singleton
{

private:

	static T* s_pObj = 0;

public:

	Singleton()
	{
		assert(!s_pObj && "Singleton already exists!");

		int offset = (int)(T*)1 - (int)(Singleton *)(T*)1;
		s_pObj = (T*)((int)this + offset);
	}

	~Singleton()
	{
		assert(s_pObj && "Couldn't find singleton..???");
		s_pObj = 0;
	}
		
	static T& get()
	{
		return *s_pObj;
	}

	static T* getPtr()
	{
		return s_pObj;
	}

};

#endif