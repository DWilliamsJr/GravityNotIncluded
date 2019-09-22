#pragma once 

#include <iostream>
#include <stack>
#include <list>
#include <random>
#include <vector>
#include <sstream>

#include "Debugging/message.h"
#include "Debugging/Timer.h"


//--------------------DEBUGGING JUNK-----------------------

const short _LOG = 15;
const short _INFO = 10;
const short _WARN = 14;
const short _ERROR = 12;
const short _TIMER = 11;
const short PINK = 13;//currently not in use



#ifndef DEBUG_MODE
#define DEBUG_MODE

			//MESSAGEMANAGER
static short s_maxSize = 100;
static short s_index = 0;
static HANDLE  hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
static message *Messages = new message[s_maxSize];


#endif

//---------------------PROGRAMMING JUNK--------------------

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

	static  std::default_random_engine generator;
	static  std::uniform_int_distribution<int> distribution(0, 6);