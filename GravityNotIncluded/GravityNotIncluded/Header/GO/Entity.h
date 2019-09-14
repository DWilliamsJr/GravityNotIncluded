#pragma once

#include "PCH.h"
#include "GameObject.h"
#include "Disease.h"


class Entity: public GameObject
{
private:
	Resources m_ResContribution;

	Resources m_ResConsumption;

	std::stack<State> m_State;

	Disease* m_Disease;

	//Entity_AI* m_AI;

public:
	Entity();

	void pushState(State *T_State);

	State* peekState();

	State* popState();

	Disease* getDisease();

	Resources& getResContribution();

	Resources& getResConsumption();

	//Entity_AI* getAI();

	void GameObject::update();

};