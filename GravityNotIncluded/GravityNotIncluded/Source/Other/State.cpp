#include "PCH.h"
#include "Other/State.h"

State::State(short t_size, State *t_list, std::string t_ID)
{
	m_size = t_size;
	m_ID = t_ID;
	m_StateList = new State[t_size];
	if (t_list != nullptr)
	{
		addStates(t_list);
	}
}

State::State() {}

State::~State()
{
	delete [] m_StateList;
}

void State::addStates(State *t_list)
{
	for (int x = 0; x < m_size; x++)
	{
		if (&m_StateList[x] == NULL)
		{
			break;
		}
		m_StateList[x] = t_list[x];
	}
}
State* State::Exit(short index)
{
	return &m_StateList[index];
}

std::string State::getID()
{
	return m_ID;
}