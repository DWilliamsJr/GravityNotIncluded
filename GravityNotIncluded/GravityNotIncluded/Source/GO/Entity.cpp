#include "PCH.h"
#include "GO/Entity.h"


Entity::Entity()
{}
Entity::Entity(AI* t_AI)
{
	m_AI = t_AI;
	m_Physics = nullptr;
	m_Graphics = nullptr;
	m_Sound = nullptr;
	m_Disease = nullptr;

	if (m_AI == nullptr)
	{
		message(_ERROR, "ENTITY CREATED WITHOUT AI", __FILE__, __LINE__);
	}
	else
	{
		m_AI->setParent(this);

		message(_LOG, "CREATED NEW ENTITY", __FILE__, __LINE__);

		m_ResConsumption.setResources((std::rand() % 4) + 1, (std::rand() % 4) + 1, (std::rand() % 4) + 1,
			(std::rand() % 4) + 1, (std::rand() % 4) + 1);

		m_ResContribution.setResources((std::rand() % 4), (std::rand() % 4), (std::rand() % 4),
			(std::rand() % 4), (std::rand() % 4));
	}

}

void Entity::setDisease(Disease* t_disease)
{
	m_Disease = t_disease;
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

Entity::~Entity()
{
	
}

void Entity::update(){}