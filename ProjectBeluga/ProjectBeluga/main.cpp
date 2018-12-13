#include <iostream>

#include "BLog.h"
#include "Timestamp.h"
#include "IMMObject.h"
#include "CMMPointer.h"
#include "BTypes.h"

#include <ctime>

int main(int argc, char** argv)
{
	std::cout << "Hello World!" << std::endl;

	BLog::get().init();
	// this only prints twice because std::cout and std::cerr
	// being directed to the same place.
	BLog::get().write(LOG_INFO | LOG_ERROR, "This is a test!");

	Timestamp time = Timestamp::getCurrentTimestamp();
	BLog::get().write(LOG_INFO, time.asHourString());

	BaseString<char> string("Test");
	BLog::get().write(LOG_INFO, string.cstring());

	system("PAUSE");

	return 0;
}