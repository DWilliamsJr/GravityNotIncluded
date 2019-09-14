#pragma once

#include "PCH.h"

class StateLibrary
{
private:
	State* m_StateList;
	short index;

public:
	StateLibrary();

	State& GetState(short index);

};