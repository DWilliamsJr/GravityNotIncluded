#include "Other/State.h"

State::State(short size, State *t_list)
{
	m_StateList = new State[size];
	if (t_list != nullptr)
	{
		addStates(size, t_list);
	}
}

State::State() {}

State::~State()
{
	delete [] m_StateList;
}

void State::addStates(short size, State *t_list)
{
	for (int x = 0; x < size; x++)
	{
		m_StateList[x] = t_list[x];
	}
}
State* State::Exit(short index)
{
	return &m_StateList[index];
}