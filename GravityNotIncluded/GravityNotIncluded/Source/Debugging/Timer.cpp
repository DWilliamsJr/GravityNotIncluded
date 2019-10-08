#include "PCH.h"
#include "Debugging/Timer.h"

Timer::Timer(const char* File, short Line)
{
	std::cout << "Timer File: " << File << " : Line: " << Line << std::endl;

	start = std::clock();

}
Timer::Timer()
{
	start = std::clock();
}

Timer::~Timer()
{
	duration = (std::clock() - start) / (double)CLOCKS_PER_SEC;
	std::ostringstream strs;
	strs << duration;

	new message(_TIMER, "Time Elapsed: " + strs.str(), __FILE__, __LINE__);
}