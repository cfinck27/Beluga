#include "BLogChannel.h"

#include <cstdarg>

BLogChannel::BLogChannel(char* filename, ChannelOutType outType)
{
	file = new std::ofstream(filename);

	setOutput(outType);
}

void BLogChannel::setOutput(ChannelOutType outType)
{
	this->outType = outType;

	if (outType == CHANNEL_NONE)
	{
		out = NULL;
	}
	else if (outType == CHANNEL_STD_OUT)
	{
		out = &std::cout;
	}
	else if (outType == CHANNEL_STD_ERR)
	{
		out = &std::cerr;
	}
	else if (outType == CHANNEL_CONSOLE)
	{
		out = NULL;
	}
}

ChannelOutType BLogChannel::getOutputType()
{
	return outType;
}

void BLogChannel::write(const char* msg, ...)
{
	va_list args;
	va_start(args, msg);
	char szBuf[MAX_CHANNEL_BUFFER];
	vsprintf_s(szBuf, msg, args);

	writeFile(szBuf);
	writeOutput(szBuf);
}

void BLogChannel::writeFile(const char* msg, ...)
{
	va_list args;
	va_start(args, msg);
	char szBuf[MAX_CHANNEL_BUFFER];
	vsprintf_s(szBuf, msg, args);

	*file << szBuf << std::endl;
	file->flush();
}

void BLogChannel::writeOutput(const char* msg, ...)
{
	va_list args;
	va_start(args, msg);
	char szBuf[MAX_CHANNEL_BUFFER];
	vsprintf_s(szBuf, msg, args);

	if (out)
	{
		*out << szBuf << std::endl;
		out->flush();
	}
}