#include "BLogChannel.h"

#include <cstdarg>

#include "Timestamp.h"

BLogChannel::BLogChannel(char* channelName, char* filename, ChannelOutType outType)
{
	m_channelName = channelName;
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

void BLogChannel::write(const char* msg)
{
	writeFile(msg);
	writeOutput(msg);
}

void BLogChannel::writeFile(const char* msg)
{
	*file << '[' << Timestamp::getCurrentTimestamp().asHourString() << "] " << msg << std::endl;
	file->flush();
}

void BLogChannel::writeOutput(const char* msg)
{
	if (out)
	{
		*out << '[' << Timestamp::getCurrentTimestamp().asHourString() << "] " <<
					'(' << m_channelName << ") " << msg << std::endl;
		out->flush();
	}
}

void BLogChannel::fwrite(const char* msg, ...)
{
	va_list args;
	va_start(args, msg);
	char szBuf[MAX_CHANNEL_BUFFER];
	vsprintf_s(szBuf, msg, args);

	write(szBuf);
}

void BLogChannel::fwriteFile(const char* msg, ...)
{
	va_list args;
	va_start(args, msg);
	char szBuf[MAX_CHANNEL_BUFFER];
	vsprintf_s(szBuf, msg, args);

	writeFile(szBuf);
}

void BLogChannel::fwriteOutput(const char* msg, ...)
{
	va_list args;
	va_start(args, msg);
	char szBuf[MAX_CHANNEL_BUFFER];
	vsprintf_s(szBuf, msg, args);

	writeOutput(msg);
}