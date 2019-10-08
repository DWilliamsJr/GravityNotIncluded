#include "PCH.h"
#include "Other/SM/State.h"

State::State(std::string t_ID)
{
	m_ID = t_ID;
}

State::State() {/* NEVER CREATE A STATE LIKE THIS*/}

std::string State::getID()
{
	return m_ID;
}

void State::setID(std::string temp)
{
	m_ID = temp;
}