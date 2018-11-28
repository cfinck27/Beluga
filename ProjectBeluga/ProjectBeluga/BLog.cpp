#include "BLog.h"

#include "BLogChannel.h"

#include <cstdarg>


// FIXME: do something with this..
const std::string LOG_PATH = "logs/";

BLog::BLog()
{
}

bool BLog::init()
{
	infoChannel = new BLogChannel("info.log", CHANNEL_STD_OUT);
	animChannel = new BLogChannel("anim.log", CHANNEL_STD_OUT);
	errorChannel = new BLogChannel("error.log", CHANNEL_STD_ERR);

	return true;
}

void BLog::write(int target, const char* msg, ...)
{
	va_list args;
	va_start(args, msg);
	char szBuf[MAX_CHANNEL_BUFFER];
	vsprintf_s(szBuf, msg, args);

	bool streamsWritten[CHANNEL_TYPE_MAX] = { false };

	// FIXME: change to loop ... for (int i == 1; i < LOG_MAX; i << 1)

	if (target & LOG_INFO)
	{
		if (!streamsWritten[infoChannel->getOutputType()])
		{
			streamsWritten[infoChannel->getOutputType()] = true;
			infoChannel->write(szBuf);
		}
		else
		{
			infoChannel->writeFile(szBuf);
		}
	}

	if (target & LOG_ANIM)
	{
		if (!streamsWritten[animChannel->getOutputType()])
		{
			streamsWritten[animChannel->getOutputType()] = true;
			animChannel->write(szBuf);
		}
		else
		{
			animChannel->writeFile(szBuf);
		}
	}

	if (target & LOG_ERROR)
	{
		if (!streamsWritten[errorChannel->getOutputType()])
		{
			streamsWritten[errorChannel->getOutputType()] = true;
			errorChannel->write(szBuf);
		}
		else
		{
			errorChannel->writeFile(szBuf);
		}
	}
}