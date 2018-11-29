#ifndef B_LOG_H
#define B_LOG_H

#include "BLogChannel.h"

#include <map>

enum LogChannelType
{
	LOG_INFO = 1 << 0,
	LOG_ERROR = 1 << 1,
	LOG_ANIM = 1 << 2,
	LOG_MAX = 1 << 3 // highest max: 33
};

/*
char* getLogChannelName(LogChannelType type)
{
	switch (type)
	{
		case LOG_INFO:
			return "INFO";
		case LOG_ERROR:
			return "ERROR";
		case LOG_ANIM:
			return "ANIM";
		default:
			return "UNKNOWN";
	}
}
*/

// TODO: add a spam filter using a ring buffer that stores
//			history of outputs for a certain length of time
//			and then prevents same messages.

class BLog
{

protected:

	std::map<LogChannelType, BLogChannel*> channelMap;

	void addChannelMap(LogChannelType type, BLogChannel* channel);
	BLogChannel* getChannelMapping(LogChannelType type);

	BLogChannel* infoChannel;
	BLogChannel* animChannel;
	BLogChannel* errorChannel;

public:

	BLog();

	bool init();
	void write(int target, const char* msg, ...);
	
};

#endif