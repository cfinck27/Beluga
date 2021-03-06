#ifndef B_LOG_CHANNEL_H
#define B_LOG_CHANNEL_H

#include <iostream>
#include <fstream>


const int MAX_CHANNEL_BUFFER = 2048;

enum ChannelOutType
{
	CHANNEL_NONE = 0,

	CHANNEL_STD_OUT,
	CHANNEL_STD_ERR,
	CHANNEL_CONSOLE,

	CHANNEL_TYPE_MAX
};

class BLogChannel
{

protected:

	char* m_channelName;
	ChannelOutType outType;

	std::ofstream* file;
	std::ostream* out = 0;

public:

	BLogChannel(char* channelName, char* filename, ChannelOutType outType = CHANNEL_NONE);

	void setOutput(ChannelOutType outType);
	ChannelOutType getOutputType();
	
	// write with no timestamp, channel name, or endl
	void writeRaw(const char* msg);
	void fwriteRaw(const char* msg, ...);

	void write(const char* msg);
	void writeFile(const char* msg);
	void writeOutput(const char* msg);
	void fwrite(const char* msg, ...);
	void fwriteFile(const char* msg, ...);
	void fwriteOutput(const char* msg, ...);

};

#endif