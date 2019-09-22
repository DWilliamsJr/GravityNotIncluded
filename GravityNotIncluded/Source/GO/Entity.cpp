#include "PCH.h"
#include "GO/Entity.h"


Entity::Entity()
{
	new message(_LOG, "CREATED NEW ENTITY", __FILE__, __LINE__);

	m_ResConsumption.setResources(distribution(generator), distribution(generator), distribution(generator), 
		distribution(generator), distribution(generator));

	m_ResContribution.setResources(distribution(generator), distribution(generator), distribution(generator), 
		distribution(generator), distribution(generator));

	deathFlag = false;

	// get an AI COMP, set it's parent == this
}

void Entity::pushState(State *T_State)
{
	m_State.push(*T_State);
}

void Entity::setDisease(Disease& t_disease)
{
	m_Disease = &t_disease;
}

State* Entity::peekState()
{
	return &m_State.top();
}

State* Entity::popState()
{
	State* temp = &m_State.top();
	m_State.pop();
	return temp;
}

Disease* Entity::getDisease()
{
	return m_Disease;
}

Resources& Entity::getResContribution()
{
	return m_ResContribution;
}

Resources& Entity::getResConsumption()
{
	return m_ResConsumption;
}

bool Entity::getDeathFlag()
{
	return deathFlag;
}

void Entity::setDeathFlag()
{
	deathFlag = true;
}

AI* Entity::getAI()
{
	return m_AI;
}

void Entity::cure()
{
	m_Disease = nullptr;
}

void Entity::update(){}