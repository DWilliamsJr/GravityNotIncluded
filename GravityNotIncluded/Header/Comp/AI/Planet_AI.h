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
	void AI::update();
	Planet* getParent();
	void setParent(Planet& t_parent);
};