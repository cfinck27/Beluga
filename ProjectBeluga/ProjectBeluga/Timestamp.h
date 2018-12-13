#ifndef TIMESTAMP_H
#define TIMESTAMP_H

#include "IMMObject.h"
#include "CMMPointer.h"

//#include <ctime>
struct tm;

// Time since Jan 1, 1970 in seconds
typedef unsigned long long epoch_t;

class Timestamp
{

public:

	static Timestamp getCurrentTimestamp();

private:
	
	tm* stamp;

protected:

	epoch_t m_seconds;

	void updateStamp();

public:

	Timestamp(epoch_t s);
	virtual ~Timestamp();

	void setTime(epoch_t s);
	epoch_t getTime();

	char* asHourString();

};

#endif