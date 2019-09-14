#include "GO/Entity.h"


Entity::Entity()
{
	
	m_ResConsumption.Food = distribution(generator);
	m_ResConsumption.Water = distribution(generator);
	m_ResConsumption.Medicine = distribution(generator);
	m_ResConsumption.Tech = distribution(generator);
	m_ResConsumption.Wood = distribution(generator);

	m_ResContribution.Food = distribution(generator);
	m_ResContribution.Water = distribution(generator);
	m_ResContribution.Medicine = distribution(generator);
	m_ResContribution.Tech = distribution(generator);
	m_ResContribution.Wood = distribution(generator);
	
	m_Disease = nullptr;


// GET CURE AI COMP
// GET PHYSICS COMP
// GET GRAPHICS COMP
// GET SOUND COMP
}

void Entity::pushState(State *T_State){}

State* Entity::peekState()
{
	return NULL;
}

State* Entity::popState()
{
	return NULL;
}

Disease* Entity::getDisease()
{
	return NULL;
}

Resources& Entity::getResContribution()
{
	return m_ResContribution;
}

Resources& Entity::getResConsumption()
{
	return m_ResConsumption;
}

//Entity_AI* Entity::getAI(){}

void Entity::update(){}