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

	bool deathFlag;

	AI* m_AI;

public:
	Entity();

	void pushState(State *T_State);

	State* peekState();

	State* popState();

	Disease* getDisease();

	void setDisease(Disease& t_disease);

	Resources& getResContribution();

	Resources& getResConsumption();

	AI* getAI();

	void GameObject::update();

	bool getDeathFlag();

	void setDeathFlag();

	void cure();

};