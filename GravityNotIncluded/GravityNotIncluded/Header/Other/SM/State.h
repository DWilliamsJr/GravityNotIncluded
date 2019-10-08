#pragma once

#include "PCH.h"

class State
{
private:
	std::string m_ID;

public:
	State( std::string t_ID);
	State();

	std::string getID();
	void setID(std::string temp);
};