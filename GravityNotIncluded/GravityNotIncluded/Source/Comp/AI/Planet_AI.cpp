#include "PCH.h"
#include "Comp/AI/Planet_AI.h"

extern StateLibrary *StaticStateLibrary;

Planet_AI::Planet_AI()
{
	 message(_LOG, "CREATED NEW Planet_AI", __FILE__, __LINE__);
	 updateMessage = "CREATE NEW ENTITY";
}

void Planet_AI::updateAI()
{
	updateMessage = "";
	std::string ParentState = ParentPlanet->peekState().getID();
	Resources *tempResources = &ParentPlanet->getResources();

	Entity *tempEntity;

	for (int x = 0; x < MEMBERLISTSIZE; x++)
	{
		tempEntity = ParentPlanet->getMember(x);
		if (tempEntity == nullptr)
		{
			continue;
		}
		if (tempEntity->peekState().getID().compare(StateIDList[DEAD]) == 0)
		{
			ParentPlanet->removeMember(x);
			continue;
		}
		*tempResources -= &tempEntity->getResConsumption();
		*tempResources += &tempEntity->getResContribution();

		if (ParentState.compare(StateIDList[DISEASEOUTBREAK]) == 0 && (std::rand() % 31) == 3 && ParentPlanet->getDisease() != nullptr)
			//|| ((ParentState.compare(StateIDList[EPIDEMIC]) == 0) && (std::rand() % 15) >= 10))
		{
			ParentPlanet->getMember(x)->setDisease(ParentPlanet->getDisease());
		}
	}

	if (ParentPlanet->getRequest() != nullptr && ParentPlanet->m_Cure == nullptr && ParentPlanet->getDisease() != nullptr)
	{
		if (ParentPlanet->getRequest()->m_Disease != nullptr)
		{
			updateMessage = "CREATE NEW CURE";
			return;
		}
	}
	
	if (ParentState.compare(StateIDList[STABLE]) == 0)
	{

		if (ParentPlanet->getDisease() != nullptr && (std::rand() % 50) > 45)
		{
			message(_LOG, ParentPlanet->getID() + ": New state DiseaseOutbreak.", __FILE__, __LINE__);
			ParentPlanet->pushState(&StaticStateLibrary->GetState(DISEASEOUTBREAK));	
		}
		else if ((std::rand() % 50) == 2 && ParentPlanet->getDisease() == nullptr)
		{
			updateMessage = "CREATE NEW DISEASE";
			return;
		}
		else if ((std::rand() % 21) == 4)
		{
			updateMessage = "CREATE NEW ENTITY";
			return;
		}
	}

	else if((ParentState.compare(StateIDList[DISEASEOUTBREAK]) == 0 || (ParentState.compare(StateIDList[EPIDEMIC]) == 0)) 
							&& ParentPlanet->getDisease() == nullptr)
	{
		ParentPlanet->popState();
	}
	else if (ParentPlanet->getDisease() != nullptr)
	{
		if (ParentPlanet->getDisease()->peekState().getID().compare(StateIDList[STAGETHREE]) == 0 && ParentState.compare(StateIDList[DISEASEOUTBREAK]) == 0)
		{
			message(_LOG, ParentPlanet->getID() + ": New state EPIDEMIC.", __FILE__, __LINE__);
			ParentPlanet->pushState(&StaticStateLibrary->GetState(EPIDEMIC));
		}

	}
	
	else if (((ParentState.compare(StateIDList[DISEASEOUTBREAK]) == 0 && (std::rand() % 31) == 12)
				|| (ParentState.compare(StateIDList[EPIDEMIC]) == 0)) && ParentPlanet->getRequest() == nullptr)
	{
			Request *temp = new Request();
			ParentPlanet->newRequest(temp);

		message(_TestGame, ParentPlanet->getID() + ":New Request, Disease", __FILE__, __LINE__);
		ParentPlanet->getRequest()->m_Disease = ParentPlanet->getDisease();
	}

	if ((tempResources->Food < 100 || tempResources->Water < 100 || tempResources->Wood < 100
		|| tempResources->Tech < 100 || tempResources->Medicine < 100) && ParentPlanet->getRequest() == nullptr)
	{
		Request *temp = new Request();
		ParentPlanet->newRequest(temp);
		temp->m_Disease = nullptr;

		if (tempResources->Food < 100)
		{
			temp->M_resources.Food = 400 - tempResources->Food;
		}
		if (tempResources->Water < 100)
		{
			temp->M_resources.Water = 400 - tempResources->Water;
		}
		if (tempResources->Tech < 100)
		{
			temp->M_resources.Tech = 400 - tempResources->Tech;
		}
		if (tempResources->Wood < 100)
		{
			temp->M_resources.Wood = 400 - tempResources->Wood;
		}
		if (tempResources->Medicine < 100)
		{
			temp->M_resources.Medicine = 400 - tempResources->Medicine;
		}
		message(_TestGame, ParentPlanet->getID() + ": New Request, Materials:  Food: " + std::to_string(temp->M_resources.Food)
			+ " Water: " + std::to_string(temp->M_resources.Water) + " Tech: " + std::to_string(temp->M_resources.Tech) + " Medicine: "
			+ std::to_string(temp->M_resources.Medicine) + " Wood: " + std::to_string(temp->M_resources.Wood), __FILE__, __LINE__);
	}

	if (ParentPlanet->m_Cure != nullptr && ParentPlanet->getDisease() != nullptr)
	{
		ParentPlanet->getDisease()->Compare(ParentPlanet->m_Cure);
	}
	if (ParentPlanet->m_Cure != nullptr)
	{
		if (ParentPlanet->m_Cure->peekState().getID().compare(StateIDList[COMPLETED]) == 0)
		{
			updateMessage = "DELETE DISEASE";
			return;
		}
	}

	if ((tempResources->Food > 100 && tempResources->Water > 100 && tempResources->Wood > 100
		&& tempResources->Tech > 100 && tempResources->Medicine > 100) && ParentPlanet->getRequest() != nullptr)
	{
		if (ParentPlanet->getRequest()->m_Disease != nullptr)
		{
			return;
		}
		updateMessage = "DELETE REQUEST";
	}
}

Planet* Planet_AI::getParent()
{
	return ParentPlanet;
}

void Planet_AI::setParent(void* t_parent)
{
	ParentPlanet = (Planet*)t_parent;
	ParentPlanet->pushState(&StaticStateLibrary->GetState(STABLE));
}
