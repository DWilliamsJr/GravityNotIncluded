#pragma once 
//--------------------PROGRAMMING JUNK----------------------
#include <iostream>
#include <stack>
#include <list>
#include <random>
#include <vector>
#include <sstream>

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
	
	const short _LOG = 15;
	const short _INFO = 10;
	const short _WARN = 14;
	const short _ERROR = 12;
	const short _TIMER = 11;
	const short PINK = 13;//currently not in use



#ifndef DEBUG_MODE
	#define DEBUG_MODE

#include "Debugging/message.h"
#include "Debugging/Timer.h"

			//MESSAGEMANAGER
		static short maxSize = 100;
		static HANDLE  hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		static message *Messages = new message[maxSize];;
		static short index = 0;

#endif
