#include "Timestamp.h"



Timestamp::Timestamp(epoch_t s)
{
	m_seconds = s;
	updateStamp();
}

Timestamp::~Timestamp()
{
}

void Timestamp::updateStamp()
{
	time_t total = m_seconds;
	localtime_s(stamp, &total);
}

void Timestamp::setTime(epoch_t s)
{
	m_seconds = s;
	updateStamp();
}

epoch_t Timestamp::getTime()
{
	return m_seconds;
}

char* Timestamp::asHourString()
{
	char* buffer = new char[80];
	strftime(buffer, 80, "%R:%S", stamp);
	return buffer;
}