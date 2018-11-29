#include <iostream>

#include "BLog.h"
#include "Timestamp.h"
#include <ctime>

int main(int argc, char** argv)
{
	std::cout << "Hello World!" << std::endl;

	BLog* log = new BLog();

	log->init();
	// this only prints twice because std::cout and std::cerr
	// being directed to the same place.
	log->write(LOG_INFO | LOG_ERROR, "This is a test!");

	system("PAUSE");

	return 0;
}