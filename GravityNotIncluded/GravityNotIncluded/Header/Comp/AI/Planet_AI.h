#pragma once
#include "PCH.h"
#include "AI.h"
#include "GO/Planet.h"

class Planet_AI: public AI
{
private:
	Planet* ParentPlanet;

public:
	Planet_AI();
	void AI::updateAI();
	Planet* getParent();
	void AI::setParent(void* t_parent);
};