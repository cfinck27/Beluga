#include "BLog.h"

#include "BLogChannel.h"

#include <cstdarg>


// FIXME: do something with this..
const std::string LOG_PATH = "logs/";
BLog* BLog::sLog = 0;

BLog::BLog()
{
	bInitialized = false;
	init();
}

BLog::~BLog()
{
}

BLog& BLog::get()
{
	if (sLog == 0)
	{
		sLog = new BLog();
	}
	return *sLog;
}

void BLog::addChannelMap(LogChannelType type, BLogChannel* channel)
{
	channelMap.insert(std::pair<LogChannelType, BLogChannel*>(type, channel));
}

BLogChannel* BLog::getChannelMapping(LogChannelType type)
{
	return channelMap.at(type);
}

bool BLog::init()
{
	bInitialized = true;

	infoChannel = new BLogChannel("INFO", "info.log", CHANNEL_STD_OUT);
	addChannelMap(LOG_INFO, infoChannel);
	animChannel = new BLogChannel("ANIM", "anim.log", CHANNEL_STD_OUT);
	addChannelMap(LOG_ANIM, animChannel);
	errorChannel = new BLogChannel("ERROR", "error.log", CHANNEL_STD_ERR);
	addChannelMap(LOG_ERROR, errorChannel);

	return true;
}

void BLog::write(int target, const char* msg, ...)
{
	va_list args;
	va_start(args, msg);
	char szBuf[MAX_CHANNEL_BUFFER];
	vsprintf_s(szBuf, msg, args);

	bool streamsWritten[CHANNEL_TYPE_MAX] = { false };

	for (int i = 1; i < LOG_MAX; i = i << 1)
	{
		LogChannelType curType = (LogChannelType)i;
		BLogChannel* curChannel = getChannelMapping(curType);
		if (target & curType)
		{
			if (!streamsWritten[curChannel->getOutputType()])
			{
				streamsWritten[curChannel->getOutputType()] = true;
				curChannel->write(szBuf);
			}
			else
			{
				curChannel->writeFile(szBuf);
			}
		}
	}
}