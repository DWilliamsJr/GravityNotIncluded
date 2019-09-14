#pragma once 

//--------------------PROGRAMMING JUNK----------------------
#include <iostream>
#include <stack>
#include <list>
#include <random>


#include "Other/Resources.h"
#include "Other/Request.h"
#include "Other/State.h"

union Pos
{
	float x;
	float y;
};

union HitBox
{
	int x;
	int y;
};


	static std::default_random_engine generator;
	static std::uniform_int_distribution<int> distribution(1, 5);





//--------------------DEBUGGING JUNK-----------------------




#ifndef DEBUG_MODE
	#define DEBUG_MODE

#include "Debugging/message.h"
#include "Debugging/Timer.h"

	const short _LOG = 15;
	const short _INFO = 10;
	const short _WARN = 14;
	const short _ERROR = 12;
		const short TEAL = 11;//currently not in use
		const short PINK = 13;// ^^

#endif