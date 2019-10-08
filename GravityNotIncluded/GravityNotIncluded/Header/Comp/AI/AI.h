#pragma once
#include "PCH.h"
#include "Other/SM/StateLibrary.h"
#include "Comp/Componet.h"

class AI: public Componet
{
public:
	std::string updateMessage;
	virtual void updateAI() = 0;
	virtual void setParent(void *t_GO) = 0;
};