#include "Timestamp.h"


#include <ctime>

static_assert(sizeof(epoch_t) == sizeof(time_t), "epoch_t is not compatible with time_t");

Timestamp Timestamp::getCurrentTimestamp()
{
	time_t rawtime;
	time(&rawtime);
	return Timestamp(rawtime);
}

Timestamp::Timestamp(epoch_t s)
{
	stamp = new tm();
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