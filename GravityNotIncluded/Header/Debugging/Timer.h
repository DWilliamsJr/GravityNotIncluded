#pragma once

#include "PCH.h"
#include <ctime>
#include <cstdio>

class Timer
{
private:
	std::clock_t start;
	double duration;

public:
	Timer();
	Timer(const char* File, short Line);
	~Timer();
};