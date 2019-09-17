#pragma once

#include "PCH.h"

class StateLibrary
{
private:
	State* m_StateList;
	short index;

	void pushState(State& t_state);
	void pushSubState(int t_index, State t_StateList[]);

public:
	StateLibrary();

	State& GetState(short index);

};