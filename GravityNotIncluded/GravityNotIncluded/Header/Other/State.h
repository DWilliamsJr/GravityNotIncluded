#pragma once

#include "PCH.h"

class State
{
private:
	State* m_StateList;

public:
	State(short size, State *t_list);
	State();

	~State();

	void addStates(short size, State *t_list);
	State* Exit(short index);
};