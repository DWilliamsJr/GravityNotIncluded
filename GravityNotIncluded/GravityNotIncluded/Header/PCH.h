#pragma once 

#include <iostream>
#include <stack>
#include <list>
#include <random>
#include <vector>
#include <sstream>
#include <string>

#include "Debugging/message.h"
#include "Debugging/Timer.h"
#include "Other/Resources.h"


//--------------------DEBUGGING JUNK-----------------------

const short _LOG = 15;
const short _INFO = 10;
const short _WARN = 14;
const short _ERROR = 12;
const short _TIMER = 13;
const short _TestGame = 11;



#ifndef DEBUG_MODE
#define DEBUG_MODE

			//MESSAGEMANAGER
static short s_maxSize = 1000;
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


struct PoolIndexInformation
{
	short PoolIndex;
	short Location;
};

struct Request
{
	Resources M_resources;
	void* m_Disease;
	void* m_Parent;
	std::string m_Message;
	bool completed = false;
};


const short MEMBERLISTSIZE = 20;

const short NumPlanet = 3;
const short NumEntity = MEMBERLISTSIZE * NumPlanet;
const short NumDisease = 5;
const short NumCure = 5;
const short NumCAI = NumCure;
const short NumDAI = NumDisease;
const short NumEAI = NumEntity;
const short NumPAI = NumPlanet;
const short NumPhysics = NumPlanet;
const short NumSound = NumPlanet;
const short NumGraphics = NumPlanet;

