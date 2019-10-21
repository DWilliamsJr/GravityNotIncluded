#pragma once
#include "PCH.h"

#include "AI.h"
#include "GO/Cure.h"


class Cure_AI : public AI
{
private:
	Cure* ParentCure;

public:
	Cure_AI();
	void AI::updateAI();
	Cure* getParent();
	void AI::setParent(void* t_parent);
};