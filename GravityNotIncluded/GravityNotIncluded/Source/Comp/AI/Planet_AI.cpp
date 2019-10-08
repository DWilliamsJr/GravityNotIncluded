#include "PCH.h"
#include "Comp/AI/Planet_AI.h"

extern StateLibrary *StaticStateLibrary;

Planet_AI::Planet_AI()
{
	 message(_LOG, "CREATED NEW Planet_AI", __FILE__, __LINE__);
	 updateMessage = "CREATE NEW ENTITY";
	 StartTime = std::clock();
	 Elapsed = 0;
}

void Planet_AI::updateAI()
{
	updateMessage = "";
	std::string ParentState = ParentPlanet->peekState().getID();

	Elapsed = (std::clock() - StartTime) / (double)CLOCKS_PER_SEC;
	std::ostringstream SS;
	SS << Elapsed;

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
		ParentPlanet->getResources() -= &tempEntity->getResConsumption();
		ParentPlanet->getResources() += &tempEntity->getResContribution();

		if (ParentState.compare(StateIDList[DISEASEOUTBREAK]) == 0 && (std::rand() % 21) == 3 && ParentPlanet->getDisease() != nullptr)
			//|| ((ParentState.compare(StateIDList[EPIDEMIC]) == 0) && (std::rand() % 15) >= 10))
		{
			ParentPlanet->getMember(x)->setDisease(ParentPlanet->getDisease());
		}
	}

	if (ParentPlanet->getRequest() != nullptr && ParentPlanet->m_Cure == nullptr)
	{
		if (ParentPlanet->getRequest()->m_Disease != nullptr)
		{
			updateMessage = "CREATE NEW CURE";
			return;
		}
	}
	
	if (ParentState.compare(StateIDList[STABLE]) == 0)
	{

		if (ParentPlanet->getDisease() != nullptr && (std::rand() % 11) > 9)
		{
			message(_TestGame, ParentPlanet->getID() + ": New state DiseaseOutbreak. Elapsed Time: " + SS.str(), __FILE__, __LINE__);
			Elapsed = 0;
			StartTime = std::clock();
			ParentPlanet->pushState(&StaticStateLibrary->GetState(DISEASEOUTBREAK));	
		}
		else if ((std::rand() % 16) == 2 && Elapsed > .0015 && ParentPlanet->getDisease() == nullptr)
		{
			Elapsed = 0;
			StartTime = std::clock();
			updateMessage = "CREATE NEW DISEASE";
			return;
		}
		else if (Elapsed > .001 && (std::rand() % 11) == 4)
		{
			Elapsed = 0;
			StartTime = std::clock();
			updateMessage = "CREATE NEW ENTITY";
			return;
		}
	}

	else if((ParentState.compare(StateIDList[DISEASEOUTBREAK]) == 0 || (ParentState.compare(StateIDList[EPIDEMIC]) == 0)) 
							&& ParentPlanet->getDisease() == nullptr)
	{
		ParentPlanet->popState();
	}
	else if (ParentPlanet->getDisease()->peekState().getID().compare(StateIDList[STAGETHREE]) == 0 && ParentState.compare(StateIDList[DISEASEOUTBREAK]) == 0)
	{
		message(_TestGame, ParentPlanet->getID() + ": New state EPIDEMIC. Elapsed Time: " + SS.str(), __FILE__, __LINE__);
		ParentPlanet->pushState(&StaticStateLibrary->GetState(EPIDEMIC));
	}
	else if (((ParentState.compare(StateIDList[DISEASEOUTBREAK]) == 0 && (std::rand() % 21) == 12)
				|| (ParentState.compare(StateIDList[EPIDEMIC]) == 0)) && ParentPlanet->getRequest() == nullptr)
	{
		message(_TestGame, ParentPlanet->getID() + ": New Request", __FILE__, __LINE__);
		Request *temp = new Request();
		temp->m_Disease = ParentPlanet->getDisease();
		ParentPlanet->newRequest(temp);
	}

	if (ParentPlanet->m_Cure != nullptr && ParentPlanet->getDisease() != nullptr)
	{
		ParentPlanet->getDisease()->Compare(ParentPlanet->m_Cure);
	}
	if (ParentPlanet->m_Cure != nullptr)
	{
		if (ParentPlanet->m_Cure->peekState().getID().compare(StateIDList[COMPLETED]) == 0)
		{
			//updateMessage = "DELETE DISEASE";
			return;
		}
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
