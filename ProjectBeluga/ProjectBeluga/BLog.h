#ifndef B_LOG_H
#define B_LOG_H

#include "BLogChannel.h"

enum LogChannelType
{
	LOG_INFO = 1 << 0,
	LOG_ERROR = 1 << 1,
	LOG_ANIM = 1 << 2,
	LOG_MAX = 1 << 3 // highest max: 33
};

class BLog
{

protected:

	BLogChannel* infoChannel;
	BLogChannel* animChannel;
	BLogChannel* errorChannel;

public:

	BLog();

	bool init();
	void write(int target, const char* msg, ...);
	

};

#endif