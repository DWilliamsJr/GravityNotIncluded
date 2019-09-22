#pragma once

#include "PCH.h"

class State
{
private:
	State* m_StateList;
	std::string m_ID;
	short m_size;

public:
	State(short t_size, State *t_list, std::string t_ID);
	State();

	~State();

	std::string getID();
	void addStates(State *t_list);
	State* Exit(short index);
};