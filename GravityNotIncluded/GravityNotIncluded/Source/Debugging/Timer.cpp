#include "Debugging/Timer.h"

Timer::Timer(const char* File, short Line)
{
	std::cout << "Timer File: " << File << " : Line: " << Line << std::endl;

	start = std::clock();
}
Timer::~Timer()
{
	duration = (std::clock() - start) / (double)CLOCKS_PER_SEC;

	std::cout << "Time Elapsed: " << duration << std::endl;
}