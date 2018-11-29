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

	Timestamp ts = Timestamp(1543443698);
	std::cout << ts.asHourString() << std::endl;

	time_t rawtime;
	time(&rawtime);
	Timestamp cur = Timestamp(rawtime);
	std::cout << cur.asHourString() << std::endl;

	system("PAUSE");

	return 0;
}