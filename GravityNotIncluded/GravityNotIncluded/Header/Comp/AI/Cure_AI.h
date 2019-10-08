#pragma once
#include "PCH.h"

#include "AI.h"
#include "GO/Cure.h"


class Cure_AI : public AI
{
private:
	Cure* ParentCure;
	std::clock_t CureStart;
	double CureElapsed;

public:
	Cure_AI();
	void AI::updateAI();
	Cure* getParent();
	void AI::setParent(void* t_parent);
};