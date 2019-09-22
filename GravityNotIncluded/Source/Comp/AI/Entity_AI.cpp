#include "PCH.h"
#include "Comp/AI/Entity_AI.h"

extern StateLibrary *StaticStateLibrary;

Entity_AI::Entity_AI()
{
	new message(_LOG, "CREATED NEW ENTITY_AI", __FILE__, __LINE__);
}

void Entity_AI::update()
{
	State tempState;
	Disease tempDisease;
	tempState = *ParentEntity->peekState();

	if (tempState.getID().compare(StateIDList[SICK]) == TRUE)
	{
		if (ParentEntity->getDeathFlag() == true)
		{
			ParentEntity->pushState(&StaticStateLibrary->GetState(DEAD));
			return;
		}
		if (ParentEntity->getDisease() == nullptr)
		{
			ParentEntity->popState();
			return;
		}
		else
		{
			ParentEntity->getResContribution().Food = 0;
			ParentEntity->getResContribution().Water = 0;
			ParentEntity->getResContribution().Medicine = 0;
			ParentEntity->getResContribution().Tech = 0;
			ParentEntity->getResContribution().Wood = 0;

			ParentEntity->getResConsumption().setResources(2, 2, 0, 0, 2);
		}
	}
	else if (tempState.getID().compare(StateIDList[DEAD]) == TRUE)
	{
		ParentEntity->getResContribution().Food = 0;
		ParentEntity->getResContribution().Water = 0;
		ParentEntity->getResContribution().Medicine = 0;
		ParentEntity->getResContribution().Tech = 0;
		ParentEntity->getResContribution().Wood = 0;

		ParentEntity->getResConsumption().Food = 0;
		ParentEntity->getResConsumption().Water = 0;
		ParentEntity->getResConsumption().Medicine = 0;
		ParentEntity->getResConsumption().Tech = 0;
		ParentEntity->getResConsumption().Wood = 0;
		return;
	}
	else if (tempState.getID().compare(StateIDList[HEALTHY]) == TRUE)
	{
		if (ParentEntity->getDisease() != nullptr)
		{
			ParentEntity->pushState(&StaticStateLibrary->GetState(SICK));
			return;
		}

		short t_RNG = distribution(generator);
		if (t_RNG == 1)
		{
			ParentEntity->getResContribution().setResources(1, 1, 1, 1, 1);
		}
		else if (t_RNG == 2)
		{
			ParentEntity->getResContribution().setResources(1,-1,1, 1, -1);
		}
		else if (t_RNG == 3)
		{
			ParentEntity->getResContribution().setResources(-1, -1, -1, -1, -1);
		}
		else if (t_RNG == 4)
		{
			ParentEntity->getResConsumption().setResources(1, 0, 0, 1, 1);
		}
		else if (t_RNG == 5)
		{
			ParentEntity->getResConsumption().setResources(-1, -1, -1, -1, -1);
		}
		else
		{
			// UNLUCK LUL 0 and 6
		}
	}
	else if (tempState.getID().compare(StateIDList[HUNGRY]) == TRUE)		// CURRENTLY DOESN'T DO ANYTHING SPECIAL???
	{
		ParentEntity->getResContribution().setResources(-1, -1, -1, -1, -1);

		ParentEntity->getResConsumption().Food = 0;
	}
	else 
	{
		new message(_ERROR, "Invalid State Entered in Entity_AI: " + tempState.getID(), __FILE__, __LINE__);
	}
}

Entity* Entity_AI::getParent()
{
	return ParentEntity;
}

void Entity_AI::setParent(Entity& t_parent)
{
	 ParentEntity = &t_parent;
}