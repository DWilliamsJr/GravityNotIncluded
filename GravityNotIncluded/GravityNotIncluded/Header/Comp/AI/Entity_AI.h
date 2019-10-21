#pragma once
#include "PCH.h"

#include "AI.h"
#include "GO/Entity.h"


class Entity_AI: public AI
{
private:
	Entity* ParentEntity;

public:
	Entity_AI();
	void AI::updateAI();
	Entity* getParent();
	void AI::setParent(void* t_parent);
};