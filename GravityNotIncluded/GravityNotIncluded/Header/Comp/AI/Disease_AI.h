#pragma once
#include "PCH.h"

#include "AI.h"
#include "GO/Disease.h"


class Disease_AI : public AI
{
private:
	Disease* ParentDisease;
	short count;

public:

	Disease_AI();

	void AI::updateAI();

	Disease* getParent();

	void AI::setParent(void* t_parent);
};