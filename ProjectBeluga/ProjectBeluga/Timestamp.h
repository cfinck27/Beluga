#ifndef TIMESTAMP_H
#define TIMESTAMP_H

#include <ctime>

typedef unsigned long long epoch_t;

class Timestamp
{

protected:

	tm* stamp = new tm();
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