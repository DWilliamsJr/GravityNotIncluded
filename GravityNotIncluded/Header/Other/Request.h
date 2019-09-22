#pragma once

#include "PCH.h"
//#include "GO/GameObject.h"

struct Request
{
	Resources M_resources;

	void* m_Disease;

	std::string m_Message;

	bool completed = false;
};